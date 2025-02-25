/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: .frnki   <frnki@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:20:42 by .frnki            #+#    #+#             */
/*   Updated: 2025/02/25 16:42:42 by .frnki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	join_threads(t_table *table, t_philo *philo)
{
	unsigned int i;

	i = 0;
	while (i < table->num_of_phil)
		pthread_join(philo[i++].thread, NULL);
}

void	create_thread(t_philo *philo, t_table *table, unsigned int i)
{
	if (pthread_create(&philo[i].thread, NULL, start_routine, &philo[i]))
	{
		printf("# error creating thread. cleaning up & exiting..\n");
		destroy_table(table);
		free(philo);
		exit(1);
	}
	printf("# philo[%i] created!\n", i);				//remove me
	philo[i].t_last = check_time();
	printf("# philo[%i].t_last = %li\n", i, philo[i].t_last);	//remove me
}

void	create_threads(t_philo *philo, t_table *table)
{
	unsigned int	i;

	i = 0;
	while (i < table->num_of_phil)
		create_thread(philo, table, i++);
}

