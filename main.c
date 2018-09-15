#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/interrupt.h>
#include <asm/io.h>

#define KBD_IRQ             1       /* IRQ number for keyboard (i8042) */
#define KBD_DATA_REG        0x60    /* I/O port for keyboard data */
#define KBD_SCANCODE_MASK   0x7f
#define KBD_STATUS_MASK     0x80

static irqreturn_t kbd2_isr(int irq, void *dev_id)
{
    char scancode;

    scancode = inb(KBD_DATA_REG);
    /* NOTE: i/o ops take a lot of time thus must be avoided in HW ISRs */
    pr_info("Scan Code %x %s\n",
            scancode & KBD_SCANCODE_MASK,
            scancode & KBD_STATUS_MASK ? "Released" : "Pressed");

    return IRQ_HANDLED;
}

static int __init kbd2_init(void)
{
	pr_info("Init\n");
    return request_irq(KBD_IRQ, kbd2_isr, IRQF_SHARED, "kbd2", (void *)kbd2_isr);
}

static void __exit kbd2_exit(void)
{
	pr_info("Exit\n");
    free_irq(KBD_IRQ, (void *)kbd2_isr);
}

module_init(kbd2_init);
module_exit(kbd2_exit);

MODULE_LICENSE("GPL");
