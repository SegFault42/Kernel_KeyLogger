#include "file.h"

struct file *file_open(const char *path, int flags, int rights)
{
	struct file		*filp = NULL;
	mm_segment_t	oldfs;
	int				err = 0;

	oldfs = get_fs();
	set_fs(get_ds());
	filp = filp_open(path, flags, rights);
	set_fs(oldfs);
	if (IS_ERR(filp)) {
		err = PTR_ERR(filp);
		return NULL;
	}

	return filp;
}
