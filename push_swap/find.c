#include "push_swap.h"

void	find_highest_a(t_data *data)
{
	t_stack	*ptr;

	if (data->a)
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

	if (data->a)
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

	if (data->b)
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

	if (data->b)
		data->lowest_b = data->b->num;
	ptr = data->b;
	while (ptr)
	{
		if (data->lowest_b > ptr->num)
			data->lowest_b = ptr->num;
		ptr = ptr->next;
	}
}

void	find_fourth_highest(t_data *data)
{
	t_stack	*ptr;
	int	tmp;
	int	i;

	ptr = data->a;
	data->fourth_highest = data->highest_a;
	i = 3;
	while (i--)
	{
		ptr = data->a;
		tmp = -2147483648;
		while (ptr)
		{
			if (ptr->num < data->fourth_highest && ptr->num > tmp)
				tmp = ptr->num;
			ptr = ptr->next;
		}
		data->fourth_highest = tmp;
	}
}
