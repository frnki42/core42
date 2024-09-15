/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efembock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 20:40:38 by efembock          #+#    #+#             */
/*   Updated: 2024/09/15 20:49:07 by efembock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
#include <stdio.h>
#include <stdlib.h>

static void	print_content(void *content)
{
	if (content)
		printf("%s\n", (char *)content);
}

int	main(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	tmp;

	node1 = ft_lstnew(ft_strdup("Node 1"));
	node2 = ft_lstnew(ft_strdup("Node 2"));
	node3 = ft_lstnew(ft_strdup("Node 3"));
	node1->next = node2;
	node2->next = node3;
	ft_lstiter(node1, print_content);
	while (node1)
	{
		tmp = node1;
		node1 = node1->next;
		free(tmp->content);
		free(tmp);
	}
	return (0);
}*/
