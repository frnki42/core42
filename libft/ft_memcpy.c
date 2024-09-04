/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efembock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 20:27:23 by efembock          #+#    #+#             */
/*   Updated: 2024/09/04 20:52:33 by efembock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*dst;
	const char	*sc;

	dst = (char *)dest;
	sc = (const char *)src;
	while (n--)
	{
		*dst = *sc;
		dst++;
		sc++;
	}
	return (dest);
}
/*
int	main(void)
{
	char	src[] = "Supdawg? This is 42code.";
	char	dest[42];

	ft_memcpy(dest, src, sizeof(src));
	printf("Source: %s\n", src);
	printf("Destination: %s\n", dest);
	return (0);
}*/
