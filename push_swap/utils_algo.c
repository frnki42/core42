/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efembock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:58:16 by efembock          #+#    #+#             */
/*   Updated: 2025/01/07 16:07:55 by efembock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

// get higher lowest number in stack
static int	get_higher_num(t_data *data, int lowest)
{
	int		tmp;
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

// sets positions in ascending order
void	sort_positions(t_data *data)
{
	int		lowest;
	int		pos;
	int		size;
	t_stack	*ptr;

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

// ..handles smaller numbers
void	handle_smaller_number(t_data *data)
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

// .. handles bigger numbers
void	handle_bigger_number(t_data *data)
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

// well.. radix_sort!
void	radix_sort(t_data *data)
{
	int		bit;
	int		i;
	size_t	size;
	int		tmp;

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
