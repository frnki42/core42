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
	if (philo->table->all_alive)
		printf("%li %i has taken a fork (right)\n", check_time(), philo->num);
	pthread_mutex_unlock(&philo->table->msg_lock);
	pthread_mutex_lock(philo->fork_left);
	pthread_mutex_lock(&philo->table->msg_lock);
	if (philo->table->all_alive)
		printf("%li %i has taken a fork (left)\n", check_time(), philo->num);
	pthread_mutex_unlock(&philo->table->msg_lock);
}

// lock fork_left before locking fork_right
void	pick_left_first(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_left);
	pthread_mutex_lock(&philo->table->msg_lock);
	if (philo->table->all_alive)
		printf("%li %i has taken a fork (left)\n", check_time(), philo->num);
	pthread_mutex_unlock(&philo->table->msg_lock);
	pthread_mutex_lock(philo->fork_right);
	pthread_mutex_lock(&philo->table->msg_lock);
	if (philo->table->all_alive)
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
	unsigned int	i;

	pthread_mutex_lock(&philo->table->msg_lock);
	if (philo->table->all_alive)
		printf("%li %i is eating\n", check_time(), philo->num);
	pthread_mutex_unlock(&philo->table->msg_lock);
	philo->t_last = check_time();
	philo->ate++;
	i = 0;
	while (philo->table->all_alive && i++ < 100)
		usleep(philo->table->t_eat * 10);
}

//put forks down
void	put_down_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->fork_left);
	pthread_mutex_lock(&philo->table->msg_lock);
	if (philo->table->all_alive)
		printf("%li %i put a fork down (left)\n", check_time(), philo->num);
	pthread_mutex_unlock(&philo->table->msg_lock);
	pthread_mutex_unlock(philo->fork_right);
	pthread_mutex_lock(&philo->table->msg_lock);
	if (philo->table->all_alive)
		printf("%li %i put a fork down (right)\n", check_time(), philo->num);
	pthread_mutex_unlock(&philo->table->msg_lock);
}

//sleep
void	take_a_nap(t_philo *philo)
{
	unsigned int	i;

	if (philo->table->all_alive)
	{
		pthread_mutex_lock(&philo->table->msg_lock);
		if (philo->table->all_alive)
			printf("%li %i is sleeping\n", check_time(), philo->num);
		pthread_mutex_unlock(&philo->table->msg_lock);
		i = 0;
		while (philo->table->all_alive && i++ < 100)
			usleep(philo->table->t_sleep * 10);
	}
}

void	reality_check(t_philo *philo)
{
	if ((check_time() - philo->t_last) >= philo->table->t_die)
	{
		pthread_mutex_lock(&philo->table->alive_lock);
		philo->table->all_alive = 0;
		pthread_mutex_unlock(&philo->table->alive_lock);
		pthread_mutex_lock(&philo->table->msg_lock);
		printf("%li %i died\n", check_time(), philo->num);
		pthread_mutex_unlock(&philo->table->msg_lock);
	}
}

//think
void	think_about_life(t_philo *philo)
{
	if (philo->table->all_alive)
	{
		pthread_mutex_lock(&philo->table->msg_lock);
		if (philo->table->all_alive)
			printf("%li %i is thinking\n", check_time(), philo->num);
		pthread_mutex_unlock(&philo->table->msg_lock);
		reality_check(philo);
	}
}

void	*start_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->t_last = check_time();
	while (philo->ate < philo->table->must_eat && philo->table->all_alive)
	{
		if (philo->table->all_alive)
			pick_up_forks(philo);
		else
			break ;
		if (philo->table->all_alive)
			eat_spaghetti(philo);
		put_down_forks(philo);
		if (philo->table->all_alive)
			take_a_nap(philo);
		else
			break ;
		if (philo->table->all_alive)
			think_about_life(philo);
	}
	return (arg);
}
