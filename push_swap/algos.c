#include "push_swap.h"

void	find_highest_a(t_data *data)
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

void	find_lowest_a(t_data *data)
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

void	find_highest_b(t_data *data)
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

void	find_lowest_b(t_data *data)
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

static void	handle_smaller_number(t_data *data)
{
	if (data->a->next->num > data->a->next->next->num)
	{
		if (data->a->num < data->a->next->next->num)
		{
			swap_a(data);
			rotate_a(data);
		}
		else
			reverse_rotate_a(data);
	}
}

static void	handle_bigger_number(t_data *data)
{
	if (data->a->next->num > data->a->next->next->num)
	{
		rotate_a(data);
		swap_a(data);
	}
	else if (data->a->next->num < data->a->next->next->num)
	{
		if (data->a->num < data->a->next->next->num)
			swap_a(data);
		else
			rotate_a(data);
	}
}

void	algo43(t_data *data)
{
	if (data->a->num < data->a->next->num)
		handle_smaller_number(data);
	else if (data->a->num > data->a->next->num)
		handle_bigger_number(data);
}

void	algo42(t_data *data)
{
	if (data->a->num > data->a->next->num)
		swap_a(data);
}

void	select_algo(t_data *data)
{
	if (data->size == 2)
		algo42(data);
	if (data->size == 3)
		algo43(data);
	if (data->size == 4)
		algo44(data);
	if (data->size == 5)
		algo45(data);
	if (data->size > 5)
		quick_sort(data);
//	if (data->size > 5)
//		radix_sort(data);
}
