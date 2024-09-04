/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efembock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:44:57 by efembock          #+#    #+#             */
/*   Updated: 2024/09/04 20:10:21 by efembock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	d;

	ptr = (unsigned char *)s;
	d = (unsigned char)c;
	while (n--)
	{
		if (*ptr == d)
			return ((void *)ptr);
		ptr++;
	}
	return (NULL);
}
/*
int	main(void)
{
	const void	*s;
	int			c;
	size_t		n;
	char		*result;

	s = "Supawg?";
	c = 100;
	n = 7;
	result = ft_memchr(s, c, n);
	printf("%s\n", result);
	return (0);
}*/
