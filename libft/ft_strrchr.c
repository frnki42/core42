/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efembock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:12:40 by efembock          #+#    #+#             */
/*   Updated: 2024/09/04 16:48:58 by efembock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	const char	*ptr;

	i = 0;
	ptr = NULL;
	while (s[i])
	{
		if (s[i] == c)
			ptr = &s[i];
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return ((char *)ptr);
}
/*
int	main(void)
{
	int	ch;

	ch = 100;
	printf("%s\n", ft_strrchr("Supdawg?", ch));
	return (0);
}*/
