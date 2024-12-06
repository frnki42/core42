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
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

typedef struct	s_data
{
	char	**input;
	long	*numbers;
	size_t	size;
	t_stack	*a;
	t_stack	*b;
}	t_data;

// prototypes
void	exit_clean(t_data *data);
void	exit_error(t_data *data);
void	init_structs(t_data *data);
void	check_valid(t_data *data);
size_t	count_numbers(char *argv);
void	check_doubles(t_data *data);
long	ft_atolong(const char *nptr);
void	check_ints(t_data *data);
void	check_input(t_data *data);
#endif
