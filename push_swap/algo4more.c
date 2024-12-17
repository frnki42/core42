#include "push_swap.h"
/*
size_t	stack_size(t_stack *stack)
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
*/

int	get_higher_num(t_data *data, int lowest)
{
	int	tmp;
	t_stack	*ptr;

	ptr = data->a;
	tmp = 2147483647;
	while (ptr)
	{
		if (ptr->num > lowest && ptr->num < tmp)
			tmp = ptr->num;
		ptr = ptr->next;
	}
	return (tmp);
}

void	sort_positions(t_data *data)
{
	int	lowest;
	int	pos;
	int	size;
	t_stack	*ptr;

	find_lowest_a(data);
	lowest = data->lowest_a;
	pos = 0;
	size = data->size;
	while (size--)
	{	
		ptr = data->a;
		while (ptr)
		{
			if (ptr->num == lowest)
			{
				ptr->pos = pos;
				lowest = get_higher_num(data, lowest);
				pos++;
			}
			ptr = ptr->next;
		}
	}
}

void	radix_sort(t_data *data)
{
	int	bit;
	int	i;
	size_t	size;
	int	tmp;

	tmp = data->highest_pos;
	bit = 0;
	while (tmp >> bit)
		bit++;
	i = -1;
	while (++i < bit)
	{
		size = data->size;
		while (size--)
		{
			if ((data->a->pos >> i) & 1)
				rotate_a(data);
			else
				push_b(data);
		}
		while (data->b)
			push_a(data);
	}
}

void	algo4more(t_data *data)
{
	sort_positions(data);
	find_highest_pos(data);
	radix_sort(data);
}
