/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: .frnki   <frnki@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:20:42 by .frnki            #+#    #+#             */
/*   Updated: 2025/02/23 16:42:42 by .frnki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	main(int argc, char **argv)	// num_of_phil t_die t_eat t_sleep [must_eat]
{					//	[1]	[2]	[3]	[4]	[5]
	t_table	table;
	t_philo	*philo;

	check_args(argc, argv);
	init_table(argc, argv, &table);
	philo = malloc(sizeof(t_philo*) * table.num_of_phil);
	if (!philo)
		destroy_table(&table, 1);
	init_philo(&table, philo);
	destroy_table(&table, 0);
	free_philo(&table, philo);
//	set_start_time(&table);
//	start_simulation();
	return (0);
}
