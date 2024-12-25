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
}

static void	send_string(pid_t pid, char *str)
{
	int	bits;

	while (*str)
	{
		bits = 7;
		while (bits >= 0)
		{
			send_bit(pid, (*str >> bits) & 1);
			pause();
			bits--;
		}
		str++;
	}
	bits = 7;
	while (bits >= 0)
	{
		send_bit(pid, ('\0' >> bits) & 1);
		pause();
		bits--;
	}
}

// client SIGUSR handler
static void	sigusr_handler(int signum)
{
	if (signum == SIGUSR1)
		ft_printf("# server recieved byte\n");
	if (signum == SIGUSR2)
		ft_printf("# server recieved message\n");
}

// main
int	main(int argc, char **argv)
{
	struct sigaction action;
	pid_t	pid;
	char	*str;

	if (argc != 3)
		return (1);
	ft_printf("# CLIENT-PID: %i\n", getpid());
	action.sa_handler = sigusr_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	pid = ft_atoi(argv[1]);
	str = argv[2];
	send_string(pid, str);
	return (0);
}
