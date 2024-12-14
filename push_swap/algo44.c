#include "push_swap.h"

void	find_lowest_num(t_data *data)
{
	int	low;
	t_stack	*ptr;

	low = data->a->num;
	ptr = data->a;
	while (ptr)
	{
		if (low > ptr->num)
			low = ptr->num;
		ptr = ptr->next;
	}
	ft_printf("lowest number is: %i\n", low);
}

void	algo44(t_data *data)
{
	ft_printf("# ALGO44!\n");
	find_lowest_num(data);
//	push_lowest_num_to_b(data);
	exit_clean(data);
}
