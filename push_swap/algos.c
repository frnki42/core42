#include "push_swap.h"

static void	algo42(t_data *data)
{
	if (data->a->num > data->a->next->num)
		swap_a(data);
}

static void	algo43(t_data *data)
{
	if (data->a->num < data->a->next->num)
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
	else if (data->a->num > data->a->next->num)
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
			else if (data->a->num > data->a->next->next->num)
				rotate_a(data);
		}
	}
}

void	select_algo(t_data *data)
{
	if (data->size == 2)
		algo42(data);
	if (data->size == 3)
		algo43(data);
}
