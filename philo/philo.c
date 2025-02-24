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
	philo = malloc(sizeof(t_philo) * table.num_of_phil);
	if (!philo)
	{
		destroy_table(&table);
		exit(1);
	}
	init_philo(&table, philo);
//////////////////////////// tests ////////////////////////////////////////////
	printf("# philo[0].ate = %i.\n", philo[0].ate);
	printf("# philo[1].ate = %i.\n", philo[1].ate);
	printf("# philo[2].ate = %i.\n", philo[2].ate);
	printf("# philo[41].ate = %i.\n", philo[41].ate);
	printf("# philo[0].num = %i.\n", philo[0].num);
	printf("# philo[1].num = %i.\n", philo[1].num);
	printf("# philo[2].num = %i.\n", philo[2].num);
	printf("# philo[41].num = %i.\n", philo[41].num);
	printf("# philo[0].t_last = %li.\n", philo[0].t_last);
	printf("# philo[1].t_last = %li.\n", philo[1].t_last);
	printf("# philo[2].t_last = %li.\n", philo[2].t_last);
	printf("# philo[41].t_last = %li.\n", philo[41].t_last);
	printf("# fork_left[0] = %p\n", (void *)philo[0].fork_left);
	printf("# fork_right[0] = %p\n", (void *)philo[0].fork_right);
	printf("# fork_left[1] = %p\n", (void *)philo[1].fork_left);
	printf("# fork_right[1] = %p\n", (void *)philo[1].fork_right);
	printf("# fork_left[2] = %p\n", (void *)philo[2].fork_left);
	printf("# fork_right[2] = %p\n", (void *)philo[2].fork_right);
	printf("# fork_left[3] = %p\n", (void *)philo[3].fork_left);
	printf("# fork_right[3] = %p\n", (void *)philo[3].fork_right);
	printf("# fork_left[40] = %p\n", (void *)philo[40].fork_left);
	printf("# fork_right[40] = %p\n", (void *)philo[40].fork_right);
	printf("# fork_left[41] = %p\n", (void *)philo[41].fork_left);
	printf("# fork_right[41] = %p\n", (void *)philo[41].fork_right);
	printf("# table[0] = %p\n", (void *)philo[0].table);
	printf("# table[1] = %p\n", (void *)philo[1].table);
	printf("# table[2] = %p\n", (void *)philo[2].table);
	printf("# table[3] = %p\n", (void *)philo[3].table);
	printf("# table[40] = %p\n", (void *)philo[40].table);
	printf("# table[41] = %p\n", (void *)philo[41].table);
///////////////////////////////////////////////////////////////////////////////
//	set_start_time(&table);
//	start_simulation();
////////////////////////// clean up ///////////////////////////////////////////
	join_threads(&table, philo);
	destroy_table(&table);
	free(philo);
///////////////////////////////////////////////////////////////////////////////
	return (0);
}
