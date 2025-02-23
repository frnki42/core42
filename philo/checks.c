/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: .frnki   <frnki@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:20:42 by .frnki            #+#    #+#             */
/*   Updated: 2025/02/20 16:42:42 by .frnki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	check_args(int argc, char **argv)
{
	int	errors;

	if (argc < 5 || argc > 6)
	{
		printf("# wrong amount of arguments\n");
		exit(1);
	}
	errors = 0;
	while (--argc)
		errors += check_str(argv[argc]);
	if (errors)
		exit(1);
}

static int	check_char(int c)
{
	if (c >= '0' && c <= '9')
		return (c);
	return (0);
}

int	check_str(char *str)
{
	if (!*str)
		return(printf("# empty argument\n"), 1);
	if (*str == '+' || *str == '-' || check_char(*str))
		str++;
	while (*str)
	{
		if (!check_char(*str++))
			return (printf("# invalid argument\n"), 1);
	}
	return (0);
}

long	check_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		return (printf("# gettimeofday() failed.\n"), -1);
	return ((time.tv_usec / 1000) + (time.tv_sec * 1000));
}
