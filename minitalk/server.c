/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
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
	if (signum == SIGUSR1)
	{
		write(1, "# 1\n", 4);
		//store binary input
		//translate binary
	}
	if (signum == SIGUSR2)
		write(1, "# 0\n", 4);
}

int	main(void)
{
	struct sigaction action;
	__pid_t	pid;

	//print PID
	pid = getpid();
	ft_printf("# SERVER-PID: %i\n", pid);
	//init struct
	action.sa_handler = sigusr_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	//set signal handler for SIGUSR1 and SIGUSR2
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (42)
		;
}
