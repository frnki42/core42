#include "push_swap.h"

void	find_lowest_num(t_data *data)
{
	t_stack	*ptr;

	data->lowest = data->a->num;
	ptr = data->a;
	while (ptr)
	{
		if (data->lowest > ptr->num)
			data->lowest = ptr->num;
		ptr = ptr->next;
	}
	ft_printf("lowest number is: %i\n", data->lowest);
}

void	algo44(t_data *data)
{
	ft_printf("# ALGO44!\n");
	find_lowest_num(data);
//	push_lowest_num_to_b(data);
//	sort 3
//	push a
	exit_clean(data);
}
