/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efembock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 20:59:02 by efembock          #+#    #+#             */
/*   Updated: 2024/09/07 19:53:05 by efembock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	char	*ptr;

	ptr = (char *)s;
	while (n--)
	{
		*ptr = 0;
		ptr++;
	}
}
/*
#include <strings.h>
int	main(void)
{
	char	str1[] = "Supdawg?";
	char	str2[] = "Supdawg?";

	ft_bzero(str1, 3);
	bzero(str2, 3);
	printf("ft_bzero result: %s\n", str1);
	printf("bzero result: %s\n", str2);
	return (0);
}*/
