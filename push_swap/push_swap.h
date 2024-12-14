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
	size_t	size;
	char	**input;
	long	*numbers;
	t_stack	*a;
	t_stack	*b;
}	t_data;

// prototypes
void	algo43(t_data *data);
void	algo44(t_data *data);
void	check_doubles(t_data *data);
void	check_input(t_data *data);
void	check_ints(t_data *data);
void	check_valid(t_data *data);
size_t	count_numbers(char *argv);
void	exit_clean(t_data *data);
void	exit_error(t_data *data);
void	fill_stack_a(t_data *data);
long	ft_atolong(const char *nptr);
void	init_structs(t_data *data);
void	is_sorted(t_data *data);
void	push_a(t_data *data);
void	push_b(t_data *data);
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
#endif
