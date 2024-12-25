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

static void	add_byte(unsigned char character, pid_t client_pid)
{
	static char	*message;
	char		*addition;
	char		*tmp;

	if (!message)
	{
		message = (char *)malloc(1);
		if (!message)
			return ;
		message[0] = '\0';
	}
	if (character == '\0')
	{
		ft_printf("%s\n", message);
		free(message);
		message = NULL;
		kill(client_pid, SIGUSR2);
		return ;
	}
	addition = (char *)malloc(2);
	if (!addition)
	{
		free(message);
		message = NULL;
		return ;
	}
	addition[0] = character;
	addition[1] = '\0';
	tmp = message;
	message = ft_strjoin(message, addition);
	if (!message)
	{
		free(addition);
		free(message);
		message = NULL;
		return ;
	}
	free(tmp);
	free(addition);
	addition = NULL;
}

//translates signals into string
static void	translate_signal(int signum, siginfo_t *info, void *context)
{
	static int		bit;
	static unsigned char	tmp;

	if (signum == SIGUSR1 || signum == SIGUSR2)
	{
		tmp = tmp << 1;
		if (signum == SIGUSR1)
			tmp = tmp | 1;
		bit++;
		if (bit == 8)
		{
			add_byte(tmp, info->si_pid);
			tmp = 0;
			bit = 0;
		}
		kill(info->si_pid, SIGUSR1);
	}
	(void)context;
}

// server main
int	main(void)
{
	struct sigaction action;

	ft_printf("# SERVER-PID: %i\n", getpid());
	action.sa_sigaction = translate_signal;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (42)
		pause();
	return (0);
}
