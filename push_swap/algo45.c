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
void	algo45(t_data *data)
{
	t_stack	*ptr;
	size_t	size;

	find_highest_num(data);
	find_lowest_num(data);
	ptr = data->a;
	size = data->size;
	while (size > 4)
	{
		ptr = data->a;
		if (ptr->num == data->lowest)
		{
			push_b(data);
			size--;
			find_lowest_num(data);
		}
		else
			rotate_a(data);
	}
	algo44(data);
	while (data->b)
		push_a(data);
}
