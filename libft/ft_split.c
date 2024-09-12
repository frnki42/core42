/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efembock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:12:30 by efembock          #+#    #+#             */
/*   Updated: 2024/09/12 19:05:34 by efembock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	count_words(const char *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (*s)
	{
		if (*s != c && j == 0)
		{
			j = 1;
			i++;
		}
		if (*s == c)
			j = 0;
		s++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char **strings;

	if (!s)
		return (NULL);	
	string = (char **)malloc(sizeof(char *) * (count_words(*s, c) + 1));
	if (!string)
		return (NULL);
	return (strings);
	
}

#include <stdio.h>
int	main(void)
{
	char	*str = "Don't panic! This is 42-code.";
	printf("Seperate words inside of the string: %zu\n", count_words(str, ' '));
	return (0);
}
