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

static void	add_byte(unsigned char character)
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
static void	translate_signal(int signum)
{
	static int		bit;
	static unsigned char	tmp;

	tmp = tmp << 1;
	if (signum == SIGUSR1)
		tmp = tmp | 1;
	bit++;
	if (bit == 8)
	{
		add_byte(tmp);
		tmp = 0;
		bit = 0;
	}
}

// server SIGUSR handler
static void	sigusr_handler(int signum, siginfo_t *info, void *context)
{
	if (signum == SIGUSR1 || signum == SIGUSR2)
		translate_signal(signum);
	kill(info->si_pid, SIGUSR1);
	(void)context;
}

// server main
int	main(void)
{
	struct sigaction action;

	ft_printf("# SERVER-PID: %i\n", getpid());
	action.sa_sigaction = sigusr_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (42)
		pause();
	return (0);
}
