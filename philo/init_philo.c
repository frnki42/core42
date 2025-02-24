/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: .frnki   <frnki@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:20:42 by .frnki            #+#    #+#             */
/*   Updated: 2025/02/23 16:42:42 by .frnki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	*start_routine(void *philo)
{
	printf("# HI IM A THREAD!\n");
	sleep(1);
	return (philo);
}

void	join_threads(t_table *table, t_philo *philo)
{
	unsigned int i;

	i = 0;
	while (i < table->num_of_phil)
		pthread_join(philo[i++].thread, NULL);
}

void	create_thread(t_philo *philo, t_table *table, unsigned int index)
{
	if (pthread_create(&philo[index].thread, NULL, start_routine, NULL))
	{
		printf("# error creating thread. cleaning up & exiting..\n");
		destroy_table(table);
		free(philo);
		exit(1);
	}
	printf("# philo[%i] created!\n", index);				//remove me
	philo[index].t_last = check_time();
	printf("# philo[%i].t_last = %li\n", index, philo[index].t_last);	//remove me
}
void	init_philo_zero(t_philo *philo, unsigned int index)
{
	philo[index].fork_left = NULL;
	philo[index].fork_right = NULL;
	philo[index].table = NULL;
	philo[index].ate = 0;
	philo[index].num = 0;
	philo[index].thread = 0;
	philo[index].t_last = 0;
}

void	set_philo(t_philo *philo, t_table *table, unsigned int index)
{
	philo[index].fork_left = &table->forks[index];
	if ((index + 1) < table->num_of_phil)
		philo[index].fork_right = &table->forks[index + 1];
	philo[index].table = table;
	philo[index].num = index + 1;
}

void	create_philo(t_philo *philo, t_table *table, unsigned int index)
{
	init_philo_zero(philo, index);
	set_philo(philo, table, index);
	create_thread(philo, table, index);
}

void	init_philo(t_table *table, t_philo *philo)
{
	unsigned int	index;

	index = 0;
	while (index < table->num_of_phil)
		create_philo(philo, table, index++);
}
