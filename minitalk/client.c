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

void	send_bit(__pid_t pid, int bit)
{
	if (bit)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	usleep(1);
}
void	send_string(__pid_t pid, char *str)
{
	char	cur;
	int	bits;
	int	i;

	i = -1;
	while (str[++i])
	{
		cur = str[i];
		bits = 8;
		while (bits--)
			send_bit(pid, (cur >> bits) & 1);
	}
}

// main
int	main(int argc, char **argv)
{
	__pid_t	pid;
	char	*str;

	if (argc != 3)
		return (1);
	pid = ft_atoi(argv[1]);
	str = argv[2];
	ft_printf("# SERVER-PID: %i\n", pid);
	ft_printf("# STRING: %s\n", str);
	send_string(pid, str);
	while (42)
		;
	return (0);
}
