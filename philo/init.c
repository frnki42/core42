/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: .frnki   <frnki@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:20:42 by .frnki            #+#    #+#             */
/*   Updated: 2025/02/20 16:42:42 by .frnki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	initialize_table(t_table *table)
{
	table->must_eat = -1;
	table->num_of_phil = 0;
	table->t_die = 0;
	table->t_eat = 0;
	table->t_sleep = 0;
	table->t_start = 0;
}
