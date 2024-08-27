/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_linked_list2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:40:25 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/08/27 16:40:54 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_printf_dlst(t_dlist **lst)
{
	t_dlist	*cur;

	if (!lst || !(*lst))
		return ;
	cur = ft_dlstfirst(*lst);
	while (cur)
	{
		if (cur->content)
			printf("%s\n", cur->content);
		cur = cur->next;
	}
}

// gets to the first item and frees till the end;
void	ft_dlstclear(t_dlist **lst)
{
	t_dlist	*cur;
	t_dlist	*next;

	if (!lst || !(*lst))
		return ;
	cur = ft_dlstfirst(*lst);
	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	*lst = NULL;
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
