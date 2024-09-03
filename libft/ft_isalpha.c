/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efembock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:58:28 by efembock          #+#    #+#             */
/*   Updated: 2024/09/03 14:11:54 by efembock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (c);
	return (0);
}
/*
int	main(void)
{
	printf("%i\n", ft_isalpha(42));
	printf("%i\n", ft_isalpha(420));
	printf("%i\n", ft_isalpha(70));
	printf("%i\n", ft_isalpha(100));
}*/
