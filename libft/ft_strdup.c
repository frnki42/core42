/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efembock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 18:38:30 by efembock          #+#    #+#             */
/*   Updated: 2024/09/05 19:00:05 by efembock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	length;
	char	*dup;

	i = 0;
	length = 0;
	while (s[length])
		length++;
	dup = (char *)malloc((length + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
/*
int	main(int argc, char **argv)
{
	char	*duplicated;

	if (argc != 2)
	{
		printf("Is your mind on vacation? Give me ONE argument.\n");
		return (0);
	}
	duplicated = ft_strdup(argv[1]);
	if (duplicated == NULL)
	{
		printf("Memory allocation failed bro.\n");
		return (1);
	}
	printf("You have entered: %s\n", argv[1]);
	printf("Duplicated string is: %s\n", duplicated);
	free(duplicated);
	duplicated = NULL;
	return (0);
}*/
