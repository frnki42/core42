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
	check_if_empty(argv);
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
		return(printf("# not enough arguments\n"), 1);
	if (argc > 6)
		return(printf("# too many arguments\n"), 1);
	initialize_table(&table);
	printf("# check_str = %i\n", check_str(argv[1]));
//	check_arguments(argv);
//	set_start_time(&table);
//	start_simulation();
	(void) argv;
	return (0);
}
