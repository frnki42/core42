/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efembock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 11:15:07 by efembock          #+#    #+#             */
/*   Updated: 2024/10/26 15:29:26 by efembock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *rest, int new_line)
{
	if (!rest)
		return (NULL);
	while (*rest)
	{
		if (*rest == (char)new_line)
			return (rest);
		rest++;
	}
	if ((char)new_line == '\0')
		return (rest);
	return (NULL);
}

char	*ft_strjoin(char *rest, char *buffer)
{
	char	*result;
	size_t	i;
	size_t	j;

	if (!rest)
	{
		rest = malloc(1);
		if (!rest)
			return (NULL);
		rest[0] = '\0';
	}
	if (!buffer)
		return (free(rest), NULL);
	result = malloc(ft_strlen(rest) + ft_strlen(buffer) + 1);
	if (!result)
		return (free(rest), NULL);
	i = -1;
	while (rest[++i])
		result[i] = rest[i];
	j = 0;
	while (buffer[j])
		result[i++] = buffer[j++];
	result[i] = '\0';
	return (free(rest), result);
}
