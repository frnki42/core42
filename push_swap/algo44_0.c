#include "push_swap.h"

static void	handle_highest_two(t_data *data)
{
	if (data->a->next->num > data->a->next->next->num)
	{
		push_b(data);
		swap_a(data);
		push_a(data);
	}
}

static void	handle_highest_one(t_data *data)
{
	if (data->a->next->num < data->a->next->next->next->num)
	{
		push_b(data);
		reverse_rotate_a(data);
		swap_a(data);
		push_a(data);
	}
	else if (data->a->next->num > data->a->next->next->next->num)
	{
		reverse_rotate_a(data);
		swap_a(data);
	}
}

static void	handle_highest_zero(t_data *data)
{
	if (data->a->next->next->num < data->a->next->next->next->num)
	{
		swap_a(data);
		rotate_a(data);
	}
	else if (data->a->next->next->num > data->a->next->next->next->num)
	{
		push_b(data);
		swap_a(data);
		reverse_rotate_a(data);
		push_a(data);
	}
}

void	handle_lowest_zero(t_data *data)
{
	if (data->a->next->num == data->highest_a)
		handle_highest_zero(data);
	else if (data->a->next->next->num == data->highest_a)
		handle_highest_one(data);
	else if (data->a->next->next->next->num == data->highest_a)
		handle_highest_two(data);
}
