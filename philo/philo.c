/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: .frnki   <frnki@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:20:42 by .frnki            #+#    #+#             */
/*   Updated: 2025/02/18 16:42:42 by .frnki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"
/*
int	check_arguments(t_table table, char **argv)
{
	check_number_of_philosophers(argv);
	check_time_to_die(argv);
	check_time_to_eat(argv);
	check_time_to_sleep(argv);
}
*/
int	main(int argc, char **argv)
{
	t_table	table;

	if (argc < 5)
		return(write(1, "# not enough arguments\n", 23), 1);
	if (argc > 6)
		return(write(1, "# too many arguments\n", 21), 1);
	initialize_table(&table);
//	check_arguments(argv);
	(void) argv;
	return (0);
}
