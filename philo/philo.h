/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: .frnki   <frnki@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:20:42 by .frnki            #+#    #+#             */
/*   Updated: 2025/02/18 16:42:42 by .frnki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILO_H
# define PHILO_H
// std header
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>
// custom header
// typedef & structs

typedef struct s_table
{
	pthread_mutex_t	*forks;				// array of forks
	unsigned int	number_of_philosophers;		// number_of_forks
	long		number_of_times_each_philosopher_must_eat;// optional -1 default 
	long		time_to_die;			// in ms
	long		time_to_eat;			// in ms
	long		time_to_sleep;			// in ms
	long		time_at_start;			// in ms
	pthread_mutex_t	print_mutex;			// msg check
}	t_table;

typedef struct s_philo
{
	pthread_mutex_t	*fork_left;		// own fork
	pthread_mutex_t	*fork_right;		// shared with N + 1
	unsigned int	meals_eaten;		// meals eaten
	unsigned int	number;			// N
	pthread_t	thread;			// individual thread
	long		time_last_meal;		// init at start of sim
	t_table		*table;
}	t_philo;
// prototypes
// macros
#endif
