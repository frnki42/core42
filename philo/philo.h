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
typedef struct s_philo
{
	fork_left;				// shared with N+1 [MAIN]
	fork_right;				// shared with N-1
	meal_amount;				// meals eaten
	last_meal;				// init at start of sim
	number;					// index + 1?
}	t_philo;

typedef struct s_table
{
	number_of_philosophers;			// number_of_forks
	time_to_die;				// in ms
	time_to_eat;				// in ms
	time_to_sleep;				// in ms
	number_of_times_each_philosopher_must_eat;	// optional -1 default 
}	t_table;
// prototypes
// macros
#endif
