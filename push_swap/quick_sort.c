#include "push_swap.h"

static void	set_pivot(t_data *data)
{
	t_stack	*ptr;

	ptr = data->a;
	data->pivot = ptr->num;
	while (data->pivot == data->highest_a ||
			data->pivot == data->lowest_a ||
			data->pivot >= data->fourth_highest)
	{
		ptr = ptr->next;
		data->pivot = ptr->num;
	}
	ft_printf("# set_pivot: %i\n", data->pivot);
}

static size_t	stack_size(t_stack *stack)
{
	size_t	len;
	t_stack	*ptr;

	len = 0;
	ptr = stack;
	while (ptr)
	{
		ptr = ptr->next;
		len++;
	}
	return (len);
}

// seperate stack by pivot
static void	partition(t_data *data)
{
	size_t	size;
	t_stack	*ptr;
	t_stack	*tmp;

	ptr = data->a;
	size = stack_size(ptr);
	while (size--)
	{
		tmp = ptr->next;
		// if number is higher than pivot and less than 4th highest
		if (ptr->num >= data->pivot && ptr->num < data->fourth_highest)
		{
			if (ptr->num > data->highest_b)
				data->highest_b = ptr->num;
			push_b(data);
		}
		// if number is smaller than pivot and less than 4th highest
		else if (ptr->num < data->pivot && ptr->num < data->fourth_highest)
		{
			if (ptr->num > data->lowest_b)
				data->lowest_b = ptr->num;
			push_b(data);
			rotate_b(data);
		}
		// if number >= 4th highest
		else
			rotate_a(data);
		ptr = tmp;
	}
	ft_printf("# highest_b: %i\n", data->highest_b);
	ft_printf("# lowest_b: %i\n", data->lowest_b);
}

// continue pushing until 4 highest are left
void	push_to_four(t_data *data)
{
	size_t	size;
	t_stack	*ptr;
	t_stack	*tmp;

	ptr = data->a;
	size = stack_size(ptr);
	while (size > 4)
	{
		tmp = ptr->next;
		if (ptr->num < data->fourth_highest)
		{
			push_b(data);
			size--;
		}
		else
			rotate_a(data);
		ptr = tmp;
	}
}

// push back last substack
void	push_substack(t_data *data)
{
	t_stack	*ptr;
	t_stack	*tmp;

	ptr = data->b;
	while (ptr->num > data->highest_b)
	{
		tmp = ptr->next;
		push_a(data);
		ptr = tmp;
	}
}
/*
void	sort_substack(t_data *data)
{
	t_stack	*ptr;

	ptr = data->b;
	while (ptr->num > data->lowest_b)
	{
		if (ptr->next->num > ptr->num && ptr->next->num > data->lowest_b)
			swap_b(data);
		push_a(data);
		ptr = data->b;
	}
}
*/
void	quick_sort(t_data *data)
{
	find_highest_a(data);
	find_lowest_a(data);
	find_fourth_highest(data);
	set_pivot(data);
	partition(data);
	algo44(data);
	//sort_substack(data);
	//push_substack(data);
	//find_lowest_a(data);
	//find_highest_b(data);
	//push_to_four(data);
	print_stack(data);
}
