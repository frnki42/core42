/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efembock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:57:43 by efembock          #+#    #+#             */
/*   Updated: 2025/01/07 16:06:12 by efembock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

// rotates stack a
static void	ra(t_data *data)
{
	t_stack	*last;
	t_stack	*tmp;

	last = NULL;
	tmp = NULL;
	tmp = data->a;
	data->a = data->a->next;
	last = data->a;
	while (last->next)
		last = last->next;
	last->next = tmp;
	tmp->next = NULL;
}

// rotates stack b
static void	rb(t_data *data)
{
	t_stack	*last;
	t_stack	*tmp;

	last = NULL;
	tmp = NULL;
	tmp = data->b;
	data->b = data->b->next;
	last = data->b;
	while (last->next)
		last = last->next;
	last->next = tmp;
	tmp->next = NULL;
}

// rotates stack a and prints "ra\n"
void	rotate_a(t_data *data)
{
	if (data->a && data->a->next)
	{
		ra(data);
		write(1, "ra\n", 3);
	}
}

// rotates stack b and prints "rb\n"
void	rotate_b(t_data *data)
{
	if (data->b && data->b->next)
	{
		rb(data);
		write(1, "rb\n", 3);
	}
}

// rotates both stacks and prints "rr\n"
void	rotate_both_stacks(t_data *data)
{
	if (data->a && data->a->next && data->b && data->b->next)
	{
		ra(data);
		rb(data);
		write(1, "rr\n", 3);
	}
}
