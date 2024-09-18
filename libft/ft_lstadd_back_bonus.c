/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efembock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 19:59:26 by efembock          #+#    #+#             */
/*   Updated: 2024/09/15 20:18:20 by efembock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}
/*
static void	print_list(t_list *lst)
{
	while (lst)
	{
		printf("%s -> ", (char *)lst->content);
		lst = lst->next;
	}
	printf("NULL\n");
}

int	main(void)
{
	t_list	*head;
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	*tmp;

	head = NULL;
	node1 = ft_lstnew("Node 1");
	ft_lstadd_back(&head, node1);
	print_list(head);
	node2 = ft_lstnew("Node 2");
	ft_lstadd_back(&head, node2);
	print_list(head);
	node3 = ft_lstnew("Node 3");
	ft_lstadd_back(&head, node3);
	print_list(head);
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	return (0);
}*/
