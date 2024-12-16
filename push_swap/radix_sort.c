#include "push_swap.h"

static void	find_highest_a(t_data *data)
{
	t_stack	*ptr;

	data->highest_a = data->a->num;
	ptr = data->a;
	while (ptr)
	{
		if (data->highest_a < ptr->num)
			data->highest_a = ptr->num;
		ptr = ptr->next;
	}
}

void	radix_sort(t_data *data)
{
	int	bits;
	int	i;
	size_t	size;
	int	tmp;

	find_highest_a(data);
	bits = 0;
	i = 0;
	tmp = data->highest_a;
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
