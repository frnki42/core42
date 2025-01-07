/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efembock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:57:25 by efembock          #+#    #+#             */
/*   Updated: 2025/01/07 16:04:23 by efembock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
// std header
// custom header
# include "libft/get_next_line/get_next_line.h"
# include "libft/printf/ft_printf.h"
# include "libft/libft.h"

// typedef & structs

typedef struct s_stack
{
	int				num;
	int				pos;
	struct s_stack	*next;
}	t_stack;

typedef struct s_data
{
	t_stack	*a;
	t_stack	*b;
	char	**input;
	long	*numbers;
	int		highest_a;
	int		highest_pos;
	int		lowest_a;
	size_t	size;
}	t_data;

// prototypes
void	algo42(t_data *data);
void	algo43(t_data *data);
void	algo44(t_data *data);
void	algo45(t_data *data);
void	algo4more(t_data *data);
void	check_doubles(t_data *data);
void	check_input(t_data *data);
void	check_ints(t_data *data);
void	check_valid(t_data *data);
void	convert_args(t_data *data, char **argv);
void	convert_argv(t_data *data, char *argv);
void	convert_input(t_data *data);
size_t	count_numbers(char *argv);
void	exit_clean(t_data *data);
void	exit_error(t_data *data);
void	fill_stack_a(t_data *data);
void	find_highest_a(t_data *data);
void	find_highest_pos(t_data *data);
void	find_lowest_a(t_data *data);
long	ft_atolong(const char *nptr);
void	handle_bigger_number(t_data *data);
void	handle_lowest_zero(t_data *data);
void	handle_lowest_one(t_data *data);
void	handle_lowest_two(t_data *data);
void	handle_lowest_three(t_data *data);
void	handle_smaller_number(t_data *data);
void	init_structs(t_data *data);
void	is_sorted(t_data *data);
void	push_a(t_data *data);
void	push_b(t_data *data);
void	radix_sort(t_data *data);
void	reverse_rotate_a(t_data *data);
void	reverse_rotate_b(t_data *data);
void	reverse_rotate_both_stacks(t_data *data);
void	rotate_a(t_data *data);
void	rotate_b(t_data *data);
void	rotate_both_stacks(t_data *data);
void	select_algo(t_data *data);
void	sort_positions(t_data *data);
void	swap_a(t_data *data);
void	swap_b(t_data *data);
void	swap_both_stacks(t_data *data);
#endif
