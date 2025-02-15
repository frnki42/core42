/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: .frnki   <frnki@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:20:42 by .frnki            #+#    #+#             */
/*   Updated: 2025/02/15 15:02:04 by efembock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

int	g_switch;

static int	add_byte(unsigned char character, siginfo_t *info)
{
	static size_t			i;
	static unsigned char	msg[MAX_ARG_STRLEN];

	if (character && info)
		msg[i++] = character;
	if (character == '\0')
	{
		i = 0;
		ft_printf("%s\n", msg);
		ft_memset(msg, 0, sizeof(msg));
		kill(info->si_pid, SIGUSR2);
	}
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
		add_byte(tmp, info);
		tmp = 0;
		bit = 0;
	}
	(void)context;
	kill(info->si_pid, SIGUSR1);
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
	while (1)
		pause();
	return (0);
}
