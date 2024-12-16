#include "push_swap.h"

void	algo45(t_data *data)
{
	t_stack	*ptr;
	size_t	size;

	find_highest_a(data);
	find_lowest_a(data);
	ptr = data->a;
	size = data->size;
	while (size > 4)
	{
		ptr = data->a;
		if (ptr->num == data->lowest_a)
		{
			push_b(data);
			size--;
			find_lowest_a(data);
		}
		else
			rotate_a(data);
	}
	algo44(data);
	while (data->b)
		push_a(data);
}
