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

void	pick_up_forks(t_philo *philo)
{
	if (philo->num % 2 == 0)
	{
		pthread_mutex_lock(philo->fork_left);
		printf("%li %i has taken a fork (left hand)\n", check_time(), philo->num);
		pthread_mutex_lock(philo->fork_right);
		printf("%li %i has taken a fork (right hand)\n", check_time(), philo->num);
	}
	else
	{
		pthread_mutex_lock(philo->fork_right);
		printf("%li %i has taken a fork (right hand)\n", check_time(), philo->num);
		pthread_mutex_lock(philo->fork_left);
		printf("%li %i has taken a fork (left hand)\n", check_time(), philo->num);
	}
}

void	*start_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;

	pick_up_forks(philo);
	// "eat" until time is gone
	printf("%li %i is eating\n", check_time(), philo->num);
	philo->ate++;
	usleep(philo->table->t_eat * 1000);
	//put forks down
	pthread_mutex_unlock(philo->fork_left);
	printf("%li %i put a fork down (left hand)\n", check_time(), philo->num);
	pthread_mutex_unlock(philo->fork_right);
	printf("%li %i put a fork down (right hand)\n", check_time(), philo->num);
	//sleep
	printf("%li %i is sleeping\n", check_time(), philo->num);
	usleep(philo->table->t_sleep * 1000);
	//think
	printf("%li %i is thinking\n", check_time(), philo->num);
	return (arg);
}

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

