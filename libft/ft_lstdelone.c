/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efembock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 20:18:52 by efembock          #+#    #+#             */
/*   Updated: 2024/09/15 20:39:53 by efembock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	if (lst->content)
		del(lst->content);
	free(lst);
}
/*
#include <stdio.h>

void	del_content(void *content)
{
	if (content)
		free(content);
}

int	main(void)
{
	t_list	*node;

	node = ft_lstnew(malloc(20));
	if (!node || !node->content)
		printf("Failed to allocate memory for node or content.\n");
	ft_lstdelone(node, del_content);
	sprintf((char *)node->content, "Example Content");
	printf("Content before deletion: %s\n", (char *)node->content);
	ft_lstdelone(node, del_content);
	return (0);
}*/
