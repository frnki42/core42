/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: .frnki   <frnki@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:20:42 by .frnki            #+#    #+#             */
/*   Updated: 2025/02/23 16:42:42 by .frnki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	init_table_zero(t_table *table)
{
	table->forks = NULL;
	table->must_eat = -1;
	table->num_of_phil = 0;
	table->t_die = 0;
	table->t_eat = 0;
	table->t_sleep = 0;
	table->t_start = 0;
}

void	create_mutex(pthread_mutex_t fork)
{
	if (pthread_mutex_init(&fork, NULL))
	{
		printf("# pthread_mutex_init failed!\n");
		// free all mutex & exit
	}	
}

void	init_forks(t_table *table)
{
	unsigned int	i;

	table->forks = malloc(sizeof(pthread_mutex_t) * table->num_of_phil);
	if (!table->forks)
	{
		printf("# malloc failed!\n");
		exit(1);
	}
	i = 0;
	while (i < table->num_of_phil)
	{
		create_mutex(table->forks[i++]);
		printf("mutex[%i] created!\n", i - 1);
	}
	free(table->forks);
}

void	init_table(int argc, char **argv, t_table *table)
{
	init_table_zero(table);
	set_table(argc, argv,table);
	init_forks(table);
	pthread_mutex_init(&table->msg_lock, NULL);
	pthread_mutex_destroy(&table->msg_lock);
}
