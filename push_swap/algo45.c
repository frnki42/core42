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
