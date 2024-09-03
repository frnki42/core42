/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efembock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:51:57 by efembock          #+#    #+#             */
/*   Updated: 2024/09/03 15:56:45 by efembock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c = c + 32;
	return ((unsigned char)c);
}
/*
int	main(void)
{
	printf("%c", ft_tolower(70));
	printf("%c", ft_tolower(79));
	printf("%c", ft_tolower(85));
	printf("%c", ft_tolower(82));
	printf("%c", ft_tolower(84));
	printf("%c", ft_tolower(89));
	printf("%c", ft_tolower(84));
	printf("%c", ft_tolower(87));
	printf("%c\n", ft_tolower(79));
	return (0);
}*/
