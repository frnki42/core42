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

// "Hello, World!"
int	main(int argc, char **argv)	// PID + string  ./client 4204 "Hello\!"
{
	__pid_t	pid;
	char	*str;

	if (argc != 3)
		return (1);
	pid = ft_atoi(argv[1]);
	str = argv[2];
	ft_printf("# CLIENT: %i\n", pid);
	ft_printf("# STRING: %s\n", str);
	kill(pid, SIGUSR2);
	return (0);
}
