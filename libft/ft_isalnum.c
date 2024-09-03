/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efembock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:34:21 by efembock          #+#    #+#             */
/*   Updated: 2024/09/03 14:07:11 by efembock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isalnum(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57))
		return (1);
	return (0);
}
/*
int	main(void)
{
	printf("%i\n", ft_isalnum(42));
	printf("%i\n", ft_isalnum(420));
	printf("%i\n", ft_isalnum(52));
	printf("%i\n", ft_isalnum(50));
	return (0);
}*/
