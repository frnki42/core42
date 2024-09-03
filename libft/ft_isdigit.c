/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efembock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:24:59 by efembock          #+#    #+#             */
/*   Updated: 2024/09/03 14:12:33 by efembock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (c);
	return (0);
}
/*
int	main(void)
{
	printf("%i\n", ft_isdigit(42));
	printf("%i\n", ft_isdigit(420));
	printf("%i\n", ft_isdigit(52));
	printf("%i\n", ft_isdigit(50));
}*/
