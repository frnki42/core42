/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efembock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 19:24:33 by efembock          #+#    #+#             */
/*   Updated: 2024/09/15 19:58:47 by efembock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
/*
int	main(void)
{
	t_list	*head;
	t_list	*last;
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	*tmp;

	head = NULL;
	last = ft_lstlast(head);
	printf("Last node of empty list: %p\n", last);
	node1 = ft_lstnew("Node 1");
	head = node1;
	last = ft_lstlast(head);
	printf("Last node (should be 'Node 1'): %s\n", (char *)last->content);
	node2 = ft_lstnew("Node 2");
	node3 = ft_lstnew("Node 3");
	node1->next = node2;
	node2->next = node3;
	last = ft_lstlast(head);
	printf("Last node (should be 'Node 3'): %s\n", (char *)last->content);
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	return (0);
}*/
