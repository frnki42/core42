/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
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
	table->all_alive = 1;
	table->num_of_phil = 0;
	table->t_die = 0;
	table->t_eat = 0;
	table->t_sleep = 0;
	table->t_start = 0;
}

void	create_mutexes(t_table *table)
{
	unsigned int	i;

	i = 0;
	while (i < table->num_of_phil)
	{
		if (pthread_mutex_init(&table->forks[i++], NULL))
		{
			printf("# pthread_mutex_init failed!\n");
			destroy_table(table);
		}	
	}
	if (pthread_mutex_init(&table->msg_lock, NULL))
	{
		printf("# pthread_mutex_init failed!\n");
		destroy_table(table);
	}
	if (pthread_mutex_init(&table->alive_lock, NULL))
	{
		printf("# pthread_mutex_init failed!\n");
		destroy_table(table);
	}
}

void	init_forks(t_table *table)
{
	table->forks = malloc(sizeof(pthread_mutex_t) * table->num_of_phil);
	if (!table->forks)
	{
		printf("# malloc failed!\n");
		exit(1);
	}
	create_mutexes(table);
}

void	init_table(int argc, char **argv, t_table *table)
{
	init_table_zero(table);			//replace me with memset
	set_table(argc, argv,table);
	init_forks(table);
}
