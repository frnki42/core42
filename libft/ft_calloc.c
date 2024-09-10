/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efembock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 19:54:35 by efembock          #+#    #+#             */
/*   Updated: 2024/09/10 19:26:13 by efembock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb == 0 || size == 0)
	{
		ptr = malloc(1);
		if (ptr)
			ft_bzero(ptr, 1);
		return (ptr);
	}
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
/*
int	main(void)
{
	char	*ptr;

	ptr = ft_calloc(5, sizeof(char));
	if (ptr == NULL)
	{
		printf("memory allocation failed!\n");
		return (1);
	}
	puts(ptr);
	free(ptr);
	ptr = calloc(5, 0);
	if (ptr == NULL)
	{
		printf("memory allocation failed bro!\n");
		return (1);
	}
	puts(ptr);
	free(ptr);
	return (0);
}*/
