/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: .frnki   <frnki@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:20:42 by .frnki            #+#    #+#             */
/*   Updated: 2025/01/07 19:19:42 by efembock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

static int	add_byte(unsigned char character)
{
	static char	*msg;
	char		*tmp;
	char		addition[2];

	if (!msg)
	{
		msg = (char *)malloc(1);
		if (!msg)
			return (1);
		msg[0] = '\0';
	}
	if (character == '\0')
		return (ft_printf("%s\n", msg), free(msg), msg = NULL, 0);
	addition[0] = character;
	addition[1] = '\0';
	tmp = msg;
	msg = ft_strjoin(msg, addition);
	free(tmp);
	if (!msg)
		return (msg = NULL, 1);
	return (0);
}

static void	translate_signal(int signum, siginfo_t *info, void *context)
{
	static int				bit;
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
	usleep(42);
	kill(info->si_pid, SIGUSR1);
	(void)context;
}

int	main(void)
{
	struct sigaction	action;

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
