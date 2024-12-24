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

static char	*g_str = NULL;

static void	add_byte(unsigned char character)
{
	char	*addition = NULL;
	char	*tmp;

	if (!g_str)
	{
		g_str = (char *)malloc(1);
		if (!g_str)
			return ;
		g_str[0] = '\0';
	}
	if (character == '\0')
	{
		ft_printf("%s\n", g_str);
		free(g_str);
		g_str = NULL;
		return ;
	}
	addition = (char *)malloc(2);
	if (!addition)
	{
		free(g_str);
		g_str = NULL;
		return ;
	}
	addition[0] = character;
	addition[1] = '\0';
	tmp = g_str;
	g_str = ft_strjoin(g_str, addition);
	if (!g_str)
	{
		free(addition);
		free(g_str);
		g_str = NULL;
		return ;
	}
	free(tmp);
	free(addition);
	addition = NULL;
}

//translates signals into string
static void	translate_signal(int signum)
{
	static int		bit = 0;
	static unsigned char	tmp = 0;

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
static void	sigusr_handler(int signum)
{
	if (signum == SIGUSR1 || signum == SIGUSR2)
		translate_signal(signum);
}

// server main
int	main(void)
{
	struct sigaction action;
	pid_t	pid;

	pid = getpid();
	ft_printf("# SERVER-PID: %i\n", pid);
	action.sa_handler = sigusr_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (42)
		pause();
	return (0);
}
