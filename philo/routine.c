/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: .frnki   <frnki@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:20:42 by .frnki            #+#    #+#             */
/*   Updated: 2025/02/25 16:42:42 by .frnki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

// lock and unlock mutexes for fork_left, fork_right
void	pick_up_forks(t_philo *philo)
{
	if (philo->num % 2)
	{
		pthread_mutex_lock(philo->fork_right);
		printf("%li %i has taken a fork (right)\n", check_time(), philo->num);
		pthread_mutex_lock(philo->fork_left);
		printf("%li %i has taken a fork (left)\n", check_time(), philo->num);
	}
	else
	{
		pthread_mutex_lock(philo->fork_left);
		printf("%li %i has taken a fork (left)\n", check_time(), philo->num);
		pthread_mutex_lock(philo->fork_right);
		printf("%li %i has taken a fork (right)\n", check_time(), philo->num);
	}
}

// "eat" until time is gone
void	eat_spaghetti(t_philo *philo)
{
	printf("%li %i is eating\n", check_time(), philo->num);
	philo->ate++;
	usleep(philo->table->t_eat * 1000);
}

//put forks down
void	put_down_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->fork_left);
	printf("%li %i put a fork down (left)\n", check_time(), philo->num);
	pthread_mutex_unlock(philo->fork_right);
	printf("%li %i put a fork down (right)\n", check_time(), philo->num);
}

void	*start_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;

	pick_up_forks(philo);
	eat_spaghetti(philo);
	put_down_forks(philo);
	//sleep
	printf("%li %i is sleeping\n", check_time(), philo->num);
	usleep(philo->table->t_sleep * 1000);
	//think
	printf("%li %i is thinking\n", check_time(), philo->num);
	return (arg);
}
