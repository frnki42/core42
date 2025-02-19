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
	fork_l;
	fork_r;
	meal_consumed;
	meal_last;
	number;
}	t_philo;

typedef struct s_table
{
	number_of_philosophers;
	time_to_die;
	time_to_eat;
	time_to_sleep;
	number_of_times_each_philosopher_must_eat;
}	t_table;
// prototypes
// macros
#endif
