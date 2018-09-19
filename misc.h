#ifndef MISC_H
#define MISC_H

#include <linux/miscdevice.h>
#include <linux/device.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/string.h>

void	destroy_misc(void);
int		create_misc(void);

#endif
