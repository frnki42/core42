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

void	*start_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;

	//pick up both forks
	pthread_mutex_lock(philo->fork_left);
	pthread_mutex_lock(&philo->table->msg_lock);
	printf("%li %i has taken a fork (left hand)\n", check_time(), philo->num);
	pthread_mutex_unlock(&philo->table->msg_lock);
	pthread_mutex_lock(philo->fork_right);
	pthread_mutex_lock(&philo->table->msg_lock);
	printf("%li %i has taken a fork (right hand)\n", check_time(), philo->num);
	pthread_mutex_unlock(&philo->table->msg_lock);
	// "eat" until time is gone
	pthread_mutex_lock(&philo->table->msg_lock);
	printf("%li %i is eating\n", check_time(), philo->num);
	pthread_mutex_unlock(&philo->table->msg_lock);
	usleep(philo->table->t_eat * 1000);
	//put forks down
	pthread_mutex_unlock(philo->fork_left);
	pthread_mutex_lock(&philo->table->msg_lock);
	printf("%li %i put a fork down (left hand)\n", check_time(), philo->num);
	pthread_mutex_unlock(&philo->table->msg_lock);
	pthread_mutex_unlock(philo->fork_right);
	pthread_mutex_lock(&philo->table->msg_lock);
	printf("%li %i put a fork down (right hand)\n", check_time(), philo->num);
	pthread_mutex_unlock(&philo->table->msg_lock);
	//sleep
	pthread_mutex_lock(&philo->table->msg_lock);
	printf("%li %i is sleeping\n", check_time(), philo->num);
	pthread_mutex_unlock(&philo->table->msg_lock);
	usleep(philo->table->t_sleep * 1000);
	//think
	pthread_mutex_lock(&philo->table->msg_lock);
	printf("%li %i is thinking\n", check_time(), philo->num);
	pthread_mutex_unlock(&philo->table->msg_lock);
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
}

void	init_philo(t_table *table, t_philo *philo)
{
	unsigned int	index;

	index = 0;
	while (index < table->num_of_phil)
		create_philo(philo, table, index++);
}
