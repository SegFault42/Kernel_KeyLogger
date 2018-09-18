#include "./keyboard.h"

t_key	*first = NULL;

void	print_nb_elem_lst(void)
{
	size_t	i = 0;
	t_key	*tmp = first;

	while (tmp != NULL) {
		tmp = tmp->next;
		i++;
	}
	pr_info("elem = %ld\n", i);
}

void	*add_tail(unsigned char scancode)
{
	t_key	*idx = first;
	t_key	*new_node = NULL;

	// create new node
	new_node = (t_key *)kcalloc(1, sizeof(t_key), GFP_KERNEL);
	if (new_node == NULL) { return NULL; }

	// init new node
	new_node->key = scancode & KBD_SCANCODE_MASK;
	new_node->state = scancode & KBD_STATUS_MASK ? 0 : 1;
	strcpy(new_node->name, key_name[new_node->key]);
	new_node->next = NULL;

	// chain list
	if (idx == NULL) {
		first = new_node;
		idx = first;
	} else {
		while (idx->next != NULL) {
			idx = idx->next;
		}
		idx->next = new_node;
	}
}

void	free_lst(void)
{
	t_key	*idx = first;
	t_key	*tmp = idx;

	while (idx != NULL)
	{
		tmp = idx;
		idx = idx->next;
		kfree(tmp);
	}
}