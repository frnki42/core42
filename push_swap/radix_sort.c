#include "push_swap.h"

static void	find_highest_num(t_data *data)
{
	t_stack	*ptr;

	data->highest = data->a->num;
	ptr = data->a;
	while (ptr)
	{
		if (data->highest < ptr->num)
			data->highest = ptr->num;
		ptr = ptr->next;
	}
}

void	radix_sort(t_data *data)
{
	int	bits;
	int	i;
	size_t	size;
	int	tmp;

	find_highest_num(data);
	bits = 0;
	i = 0;
	tmp = data->highest;
	while ((tmp >> bits) != 0)
		bits++;
	while (i < bits)
	{
		size = data->size;
		while (size--)
		{
			if (((data->a->num >> i) & 1) == 1)
				rotate_a(data);
			else
				push_b(data);
		}
		while (data->b)
			push_a(data);
		i++;
	}
	print_stack(data);
}
