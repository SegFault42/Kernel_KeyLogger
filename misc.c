#include "misc.h"

static int	misc_open(struct inode *inode, struct file *filp);
static int	misc_release(struct inode *inode, struct file *filp);

static struct miscdevice		misc_device;
const struct file_operations	f_ops = {
	.owner = THIS_MODULE,
	.open = misc_open,
	.release = misc_release,
	/*.read = misc_read,*/
	/*.write = misc_write,*/
};

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

/*static ssize_t		misc_read(struct file *filp,*/
			/*char *buffer,*/
			/*size_t length,*/
			/*loff_t *offset)*/
/*{*/
	/*if (*offset == 0 && length > LOGIN_LEN) {*/
		/*if (copy_to_user(buffer, LOGIN, LOGIN_LEN) != 0) {*/
			/*pr_info("copy_to_user() failure");*/
			/*return -1;*/
		/*}*/
		/**offset = LOGIN_LEN;*/
		/*return LOGIN_LEN;*/
	/*}*/
	/*pr_debug("buffer = %s\n", buffer);*/
	/*return 0;*/
/*}*/

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
