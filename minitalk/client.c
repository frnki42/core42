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

static void	send_bit(pid_t pid, int bit)
{
	if (bit)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	pause();
}

static void	send_string(pid_t pid, char *str)
{
	int	bits;

	while (*str)
	{
		bits = 8;
		while (bits--)
			send_bit(pid, (*str >> bits) & 1);
		str++;
	}
	bits = 8;
	while (bits--)
		send_bit(pid, 0);
}

static void	sigusr_handler(int signum)
{
	if (signum == SIGUSR1)
		write(1, "# server recieved bit\n", 23);
}

int	main(int argc, char **argv)
{
	struct sigaction action;
	pid_t	pid;

	if (argc != 3)
		return (1);
	action.sa_handler = sigusr_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	sigaction(SIGUSR1, &action, NULL);
	pid = ft_atoi(argv[1]);
	if (pid < 1)
		return (1);
	send_string(pid, argv[2]);
	return (0);
}
