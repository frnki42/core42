#include "push_swap.h"

static void	set_pivot(t_data *data)
{
	t_stack	*ptr;

	ptr = data->a;
	data->pivot = ptr->num;
	while (data->pivot == data->highest_a || data->pivot == data->lowest_a)
	{
		ptr = ptr->next;
		data->pivot = ptr->num;
	}
}

static size_t	stack_length(t_stack *stack)
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

static void	partition(t_data *data)
{
	t_stack	*ptr;
	t_stack	*tmp;
	size_t	size;


	set_pivot(data);
	ptr = data->a;
	size = stack_length(ptr);
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
	find_highest_a(data);
	find_lowest_a(data);
	find_highest_b(data);
	find_lowest_b(data);
	partition(data);
	print_stack(data);
}
