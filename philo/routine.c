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

// lock fork_right before locking fork_left
void	pick_right_first(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_right);
	pthread_mutex_lock(&philo->table->msg_lock);
	printf("%li %i has taken a fork (right)\n", check_time(), philo->num);
	pthread_mutex_unlock(&philo->table->msg_lock);
	pthread_mutex_lock(philo->fork_left);
	pthread_mutex_lock(&philo->table->msg_lock);
	printf("%li %i has taken a fork (left)\n", check_time(), philo->num);
	pthread_mutex_unlock(&philo->table->msg_lock);
}

// lock fork_left before locking fork_right
void	pick_left_first(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_left);
	pthread_mutex_lock(&philo->table->msg_lock);
	printf("%li %i has taken a fork (left)\n", check_time(), philo->num);
	pthread_mutex_unlock(&philo->table->msg_lock);
	pthread_mutex_lock(philo->fork_right);
	pthread_mutex_lock(&philo->table->msg_lock);
	printf("%li %i has taken a fork (right)\n", check_time(), philo->num);
	pthread_mutex_unlock(&philo->table->msg_lock);
}

// lock and unlock mutexes for fork_left, fork_right
void	pick_up_forks(t_philo *philo)
{
	if (philo->num % 2)
		pick_left_first(philo);
	else
		pick_right_first(philo);
}

// "eat" until time is gone
void	eat_spaghetti(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->msg_lock);
	printf("%li %i is eating\n", check_time(), philo->num);
	pthread_mutex_unlock(&philo->table->msg_lock);
	philo->t_last = check_time();
	philo->ate++;
	usleep(philo->table->t_eat * 1000);
}

//put forks down
void	put_down_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->fork_left);
	pthread_mutex_lock(&philo->table->msg_lock);
	printf("%li %i put a fork down (left)\n", check_time(), philo->num);
	pthread_mutex_unlock(&philo->table->msg_lock);
	pthread_mutex_unlock(philo->fork_right);
	pthread_mutex_lock(&philo->table->msg_lock);
	printf("%li %i put a fork down (right)\n", check_time(), philo->num);
	pthread_mutex_unlock(&philo->table->msg_lock);
}

//sleep
void	take_a_nap(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->msg_lock);
	printf("%li %i is sleeping\n", check_time(), philo->num);
	pthread_mutex_unlock(&philo->table->msg_lock);
	usleep(philo->table->t_sleep * 1000);
}

//think
void	think_about_life(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->msg_lock);
	printf("%li %i is thinking\n", check_time(), philo->num);
	pthread_mutex_unlock(&philo->table->msg_lock);
	if ((check_time() - philo->t_last) >= philo->table->t_die)
	{
		printf("%li %i died\n", check_time(), philo->num);
		philo->table->all_alive = 0;
	}
}

void	*start_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (philo->ate < philo->table->must_eat)
	{
		pick_up_forks(philo);
		eat_spaghetti(philo);
		put_down_forks(philo);
		take_a_nap(philo);
		think_about_life(philo);
	}
	return (arg);
}
