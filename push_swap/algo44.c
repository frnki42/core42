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

static void	find_lowest_a(t_data *data)
{
	t_stack	*ptr;

	data->lowest_a = data->a->num;
	ptr = data->a;
	while (ptr)
	{
		if (data->lowest_a > ptr->num)
			data->lowest_a = ptr->num;
		ptr = ptr->next;
	}
}

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
