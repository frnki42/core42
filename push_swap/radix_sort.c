#include "push_swap.h"

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
