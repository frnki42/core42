/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efembock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:57:33 by efembock          #+#    #+#             */
/*   Updated: 2025/01/07 16:05:38 by efembock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

// reverse rotates stack a
static void	rra(t_data *data)
{
	t_stack	*last;
	t_stack	*tmp;

	last = data->a;
	while (last->next->next)
		last = last->next;
	tmp = last->next;
	last->next = NULL;
	tmp->next = data->a;
	data->a = tmp;
}

// reverse rotates stack b
static void	rrb(t_data *data)
{
	t_stack	*last;
	t_stack	*tmp;

	last = data->b;
	while (last->next->next)
		last = last->next;
	tmp = last->next;
	last->next = NULL;
	tmp->next = data->b;
	data->b = tmp;
}

// reverse rotates stack a and prints "rra\n"
void	reverse_rotate_a(t_data *data)
{
	if (data->a && data->a->next)
	{
		rra(data);
		write(1, "rra\n", 4);
	}
}

// reverse rotates stack b and prints "rrb\n"
void	reverse_rotate_b(t_data *data)
{
	if (data->b && data->b->next)
	{
		rrb(data);
		write(1, "rrb\n", 4);
	}
}

// reverse rotates both stacks and prints "rrb\n"
void	reverse_rotate_both_stacks(t_data *data)
{
	if (data->a && data->a->next && data->b && data->b->next)
	{
		rra(data);
		rrb(data);
		write(1, "rrr\n", 4);
	}
}
