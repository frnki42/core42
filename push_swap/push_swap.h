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
typedef struct	s_data
{
	char	**input;
	size_t	size;
	int	*stack_a;
	int	*stack_b;
	long	*stack_c;
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
