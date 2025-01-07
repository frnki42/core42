/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efembock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:55:08 by efembock          #+#    #+#             */
/*   Updated: 2025/01/07 15:55:24 by efembock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

// swaps first 2 ints on stack a and prints "sa\n"
void	swap_a(t_data *data)
{
	int	tmp;

	if (data->a && data->a->next)
	{
		tmp = data->a->num;
		data->a->num = data->a->next->num;
		data->a->next->num = tmp;
		write(1, "sa\n", 3);
	}
}

// swaps first 2 ints on stack b and prints "sb\n"
void	swap_b(t_data *data)
{
	int	tmp;

	if (data->b && data->b->next)
	{
		tmp = data->b->num;
		data->b->num = data->b->next->num;
		data->b->next->num = tmp;
		write(1, "sb\n", 3);
	}
}

// swaps first 2 ints in stack a and stack b prints "ss\n"
void	swap_both_stacks(t_data *data)
{
	int	tmp;

	if (data->a && data->a->next && data->b && data->b->next)
	{
		tmp = data->a->num;
		data->a->num = data->a->next->num;
		data->a->next->num = tmp;
		tmp = data->b->num;
		data->b->num = data->b->next->num;
		data->b->next->num = tmp;
		write(1, "ss\n", 3);
	}
}
