/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: .frnki   <frnki@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:20:42 by .frnki            #+#    #+#             */
/*   Updated: 2024/11/16 16:42:42 by .frnki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

void	send_bit(pid_t pid, int bit)
{
	if (bit)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
}
void	send_string(pid_t pid, char *str)
{
	int	bits;

	while (*str)
	{
		bits = 7;
		while (bits >= 0)
		{
			send_bit(pid, (*str >> bits) & 1);
			usleep(42);
			bits--;
		}
		str++;
	}
	bits = 7;
	while (bits >= 0)
	{
		send_bit(pid, ('\0' >> bits) & 1);
		usleep(42);
		bits--;
	}
}

// main
int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*str;

	if (argc != 3)
		return (1);
	pid = ft_atoi(argv[1]);
	str = argv[2];
	send_string(pid, str);
	return (0);
}
