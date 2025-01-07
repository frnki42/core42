/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efembock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:56:23 by efembock          #+#    #+#             */
/*   Updated: 2025/01/07 15:56:26 by efembock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

// check if character is a digit
static void	check_num(t_data *data, int c)
{
	if (!(c >= '0' && c <= '9'))
		exit_error(data);
}

// check if character is digit, + or -
static void	check_sign(t_data *data, int c)
{
	if (!((c >= '0' && c <= '9') || c == '-' || c == '+'))
		exit_error(data);
}

// checks for duplicates
void	check_doubles(t_data *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < data->size)
	{
		j = 1 + i;
		while (j < data->size)
		{
			if (data->numbers[i] == data->numbers[j++])
				exit_error(data);
		}
		i++;
	}
}

// check if input is valid
void	check_input(t_data *data)
{
	int	x;
	int	y;

	if (!data->input)
		exit_error(data);
	y = -1;
	while (data->input[++y])
	{
		x = -1;
		while (data->input[y][++x])
		{
			if (x == 0)
				check_sign(data, data->input[y][x]);
			else
				check_num(data, data->input[y][x]);
		}
	}
}

// check if numbers fit into an int
void	check_ints(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->size)
	{
		if (data->numbers[i] != (int)data->numbers[i])
			exit_error(data);
		i++;
	}
}
