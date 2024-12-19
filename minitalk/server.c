/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: .frnki   <frnki@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:20:42 by .frnki            #+#    #+#             */
/*   Updated: 2024/11/16 16:42:42 by .frnki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

void	signal_handler(int signum)
{
	int	i;

	i = 0;
	ft_printf("\nsignum %i recieved\n", signum);
	ft_printf("LOADING!\n");
	while (i < 5)
	{
		write(1, "=", 1);
		usleep(100000);
	}
	ft_printf("DONE!\n");
	exit(0);
}

int	main(void)
{
	struct sigaction action;
	int	pid;

	action.sa_handler = signal_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	pid = getpid();
	ft_printf("# SERVER-PID: %i\n", pid);
	sigaction(SIGINT, &action, NULL);
	while (42)
		;
	return (0);
}
