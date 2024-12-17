/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: .frnki   <frnki@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:20:42 by .frnki            #+#    #+#             */
/*   Updated: 2024/11/16 16:24:42 by .frnki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
// std header
// custom header
# include "libft/get_next_line/get_next_line.h"
# include "libft/printf/ft_printf.h"
# include "libft/libft.h"

// typedef & structs

typedef struct s_stack
{
	int		num;
	struct s_stack	*next;
}	t_stack;

typedef struct	s_data
{
	int	fourth_highest;
	int	highest_a;
	int	highest_b;
	int	lowest_a;
	int	lowest_b;
	int	pivot;
	size_t	size;
	char	**input;
	long	*numbers;
	t_stack	*a;
	t_stack	*b;
}	t_data;

// prototypes
void	algo42(t_data *data);
void	algo43(t_data *data);
void	algo44(t_data *data);
void	algo45(t_data *data);
void	check_doubles(t_data *data);
void	check_input(t_data *data);
void	check_ints(t_data *data);
void	check_valid(t_data *data);
void	convert_argv(t_data *data, char *argv);
void	convert_args(t_data *data, char **argv);
void	convert_input(t_data *data);
size_t	count_numbers(char *argv);
void	exit_clean(t_data *data);
void	exit_error(t_data *data);
void	fill_stack_a(t_data *data);
void	find_fourth_highest(t_data *data);
void	find_highest_a(t_data *data);
void	find_highest_b(t_data *data);
void	find_lowest_a(t_data *data);
void	find_lowest_b(t_data *data);
long	ft_atolong(const char *nptr);
void	handle_lowest_zero(t_data *data);
void	handle_lowest_one(t_data *data);
void	handle_lowest_two(t_data *data);
void	handle_lowest_three(t_data *data);
void	init_structs(t_data *data);
void	is_sorted(t_data *data);
void	print_stack(t_data *data);
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
void	swap_a(t_data *data);
void	swap_b(t_data *data);
void	swap_both_stacks(t_data *data);
void	quick_sort(t_data *data);
#endif
