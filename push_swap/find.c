/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efembock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:56:38 by efembock          #+#    #+#             */
/*   Updated: 2025/01/07 15:56:42 by efembock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

// you guessed it! finds the highest num in stack a
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

// you guessed it! finds the lowest num in stack a
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

// finds highest position inside a stack
void	find_highest_pos(t_data *data)
{
	t_stack	*ptr;

	ptr = data->a;
	data->highest_pos = ptr->pos;
	while (ptr)
	{
		if (ptr->pos > data->highest_pos)
			data->highest_pos = ptr->pos;
		ptr = ptr->next;
	}
}
