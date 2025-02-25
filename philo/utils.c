/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: .frnki   <frnki@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 16:20:42 by .frnki            #+#    #+#             */
/*   Updated: 2025/02/21 16:42:42 by .frnki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

long	ft_atolong(char *str)
{
	int		i;
	int		sign;
	long		tmp;

	i = 0;
	sign = 1;
	tmp = 0;
	while (str[i] && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
		tmp = tmp * 10 + (str[i++] - '0');
	return (tmp * sign);
}

void	destroy_table(t_table *table)
{
	unsigned int	i;

	i = 0;
	while (i < table->num_of_phil)
		pthread_mutex_destroy(&table->forks[i++]);
	if (table->forks)
		free(table->forks);
	pthread_mutex_destroy(&table->msg_lock);
	pthread_mutex_destroy(&table->alive_lock);
}
