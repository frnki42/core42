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

static void	find_lowest_num(t_data *data)
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
}

void	algo44(t_data *data)
{
	find_highest_num(data);
	find_lowest_num(data);
	if (data->a->num == data->lowest)
		handle_lowest_zero(data);
	else if (data->a->next->num == data->lowest)
		handle_lowest_one(data);
	else if (data->a->next->next->num == data->lowest)
		handle_lowest_two(data);
	else if (data->a->next->next->next->num == data->lowest)
		handle_lowest_three(data);
}