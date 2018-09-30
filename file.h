#ifndef FILE_H
#define FILE_H

#include <linux/fs.h>
#include <asm/segment.h>
#include <asm/uaccess.h>
#include <linux/buffer_head.h>

struct file	*file_open(const char *path, int flags, int rights);

#endif
