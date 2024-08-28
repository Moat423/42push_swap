/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_linked_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 10:17:05 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/08/27 16:41:14 by lmeubrin         ###   ########.fr       */
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
	t_dlist	*last;

	if (!lst || !new_node)
		return ;
	if (!(*lst))
		(*lst) = new_node;
	else
	{
		last = ft_dlstlast(*lst);
		last->next = new_node;
		new_node->prev = last;
	}
}
