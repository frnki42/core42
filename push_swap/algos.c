#include "push_swap.h"

// handles 2 numbers
void	algo42(t_data *data)
{
	if (data->a->num > data->a->next->num)
		swap_a(data);
}

// handles 3 numbers
void	algo43(t_data *data)
{
	if (data->a->num < data->a->next->num)
		handle_smaller_number(data);
	else if (data->a->num > data->a->next->num)
		handle_bigger_number(data);
}

// handles 4 numbers
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

// handles 5 numbers
void	algo45(t_data *data)
{
	t_stack	*ptr;
	size_t	size;

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

// handles more numbers
void	algo4more(t_data *data)
{
	find_lowest_a(data);
	sort_positions(data);
	find_highest_pos(data);
	radix_sort(data);
}
