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

void	sigusr_handler(int signum)
{
	int	i;

	ft_printf("\nsignum %i recieved\nLOADING!\n", signum);
	if (signum == SIGUSR1)
	{
		i = -1;
		while (++i < 5)
		{
			write(1, "=", 1);
			usleep(100000);
		}
		ft_printf("\nDONE!\n");
		exit(0);
	}
	if (signum == SIGUSR1)
	{
		i = -1;
		while (++i < 5)
		{
			write(1, "#", 1);
			usleep(100000);
		}
		ft_printf("\nDONE!\n");
		exit(0);
	}
}

int	main(void)
{
	struct sigaction action;
	__pid_t	pid;

	//print PID
	pid = getpid();
	ft_printf("# SERVER-PID: %i\n", pid);
	//init structs
	action.sa_handler = sigusr_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	//set actions
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (42)
		;
	return (0);
}
