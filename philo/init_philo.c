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

void	init_philo_zero(t_philo *philo)
{
	philo->fork_left = NULL;
	philo->fork_right = NULL;
	philo->table = NULL;
	philo->ate = 0;
	philo->num = 0;
	philo->thread = 0;
	philo->t_last = 0;
}

void	set_philo(t_philo *philo, t_table *table, unsigned int index)
{
	philo->fork_left = &table->forks[index];
	if ((index + 1) < table->num_of_phil)
		philo->fork_right = &table->forks[index + 1];
	philo->table = table;
	philo->num = index + 1;
}

void	create_philo(t_philo *philo, t_table *table, unsigned int index)
{
	philo = malloc(sizeof(t_philo));
	if (!philo)
		destroy_table(table, 1);
	init_philo_zero(philo);
	set_philo(philo, table, index);
}

void	init_philo(t_table *table, t_philo *philo)
{
	unsigned int	index;

	index = 0;
	while (index < table->num_of_phil)
	{
		create_philo(&philo[index], table, index);
		printf("# philo[%i] created!\n", index++);
	}
}
