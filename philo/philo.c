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

int	main(int argc, char **argv)	// num_of_phil t_die t_eat t_sleep [must_eat]
{					//	[1]	[2]	[3]	[4]	[5]
	t_table	table;

	if (argc < 5 || argc > 6)
		return (printf("# wrong amount of arguments\n"), 1);
	check_args(argc, argv);
	init_table(&table);
//	set_start_time(&table);
//	start_simulation();
	return (0);
}
