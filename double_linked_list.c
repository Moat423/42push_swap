/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_linked_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 10:17:05 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/08/07 13:51:25 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


t_dlist	*ft_dlstnew(char *content)
{
	t_dlist	*new_node;

	new_node = malloc(sizeof(t_dlist));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

t_dlist	*ft_dlstfirst(t_dlist *lst)
{
	if (lst)
	{
		while (lst->prev)
			lst = lst->prev;
	}
	return (lst);
}

// Counts the number of nodes in a list. give it any node.
//returns the length of the list
int	ft_dlstsize(t_dlist *lst)
{
	int	size;

	size = 0;
	lst = ft_dlstfirst(lst);
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

// Returns the last node of the list.
t_dlist	*ft_dlstlast(t_dlist *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
	}
	return (lst);
}

void	ft_dlstadd_back(t_dlist **lst, t_dlist *new_node)
{
	t_dlist	*tmp;

	if (!lst || !new_node)
		return ;
	if (!(*lst))
	{
		(*lst) = new_node;
	}
	else
	{
		tmp = *lst;
		while ((tmp)->next)
			(tmp) = (tmp)->next;
		(tmp)->next = new_node;
	}
}

void	ft_printf_dlst(t_dlist **lst)
{
	t_dlist	*cur;

	cur = ft_dlstfirst(*lst);
	while (cur)
	{
		printf("%s\n", cur->content);
		cur = cur->next;
	}
}

// gets to the first item and frees till the end;
void	ft_dlstclear(t_dlist *lst)
{
	t_dlist	*cur;

	lst = ft_dlstfirst(lst);
	while (lst)
	{
		cur = lst->next;
		free(lst);
		lst = cur;
	}
}

t_dlist	*ft_createaddback(t_dlist **lst, void *content)
{
	t_dlist	*node;

	node = ft_dlstnew(content);
	if (!node)
		return (NULL);
	ft_dlstadd_back(lst, node);
	return (node);
}
