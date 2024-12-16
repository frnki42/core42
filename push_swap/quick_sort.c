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
/*
static void	find_highest_b(t_data *data)
{
	t_stack	*ptr;

	data->highest_b = data->b->num;
	ptr = data->b;
	while (ptr)
	{
		if (data->highest_b < ptr->num)
			data->highest_b = ptr->num;
		ptr = ptr->next;
	}
}

static void	find_lowest_b(t_data *data)
{
	t_stack	*ptr;

	data->lowest_b = data->b->num;
	ptr = data->b;
	while (ptr)
	{
		if (data->lowest_b > ptr->num)
			data->lowest_b = ptr->num;
		ptr = ptr->next;
	}
}
*/
static void	partition(t_data *data)
{
	t_stack	*ptr;
	t_stack	*tmp;
	size_t	size;

	find_highest_a(data);
	find_lowest_a(data);
	ptr = data->a;
	data->pivot = ptr->num;
	while (data->pivot == data->highest_a || data->pivot == data->lowest_a)
	{
		ptr = ptr->next;
		data->pivot = ptr->num;
	}
	ptr = data->a;
	size = data->size;
	while (size--)
	{
		tmp = ptr->next;
		if (ptr->num <= data->pivot)
			push_b(data);
		else
			rotate_a(data);
		ptr = tmp;
	}
}

void	quick_sort(t_data *data)
{
	partition(data);
	print_stack(data);
}
