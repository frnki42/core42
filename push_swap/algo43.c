#include "push_swap.h"

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
