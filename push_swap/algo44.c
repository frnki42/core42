#include "push_swap.h"

void	algo44(t_data *data)
{
	find_highest_a(data);
	find_lowest_a(data);
	if (data->a->num == data->lowest_a)
		handle_lowest_zero(data);
	else if (data->a->next->num == data->lowest_a)
		handle_lowest_one(data);
	else if (data->a->next->next->num == data->lowest_a)
		handle_lowest_two(data);
	else if (data->a->next->next->next->num == data->lowest_a)
		handle_lowest_three(data);
}
