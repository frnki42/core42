/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: .frnki   <frnki@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:20:42 by .frnki            #+#    #+#             */
/*   Updated: 2025/02/26 18:02:53 by efembock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	set_t_start(t_table *table, t_philo *philo)
{
	table->t_start = check_time();
	if (table->t_start == -1)
	{
		printf("# gettimeofday() failed. cleaning up & exit.\n");
		destroy_table(table);
		free(philo);
	}
	printf("# t_start = %li.\n", table->t_start);		//remove me
}

static void	set_num_of_phil(t_table *table, char *arg)
{
	long	tmp;

	tmp = ft_atolong(arg);
	if (tmp < 1 || tmp > 2048)
	{
		printf("# invalid number_of_philosophers!\n");
		printf("# pick a number between 1 and 2048.\n");
		exit(1);
	}
	table->num_of_phil = tmp;
}

static void	set_long(long *time, char *arg)
{
	*time = ft_atolong(arg);
	if (*time < 1)
	{
		printf("# invalid argument!\n");
		printf("# set a positive value.\n");
		exit(1);
	}
}

void	set_table(int argc, char **argv, t_table *table)
{
	set_num_of_phil(table, argv[1]);
	set_long(&table->t_die, argv[2]);
	set_long(&table->t_eat, argv[3]);
	set_long(&table->t_sleep, argv[4]);
	if (argc == 6)
		set_long(&table->must_eat, argv[5]);
}
