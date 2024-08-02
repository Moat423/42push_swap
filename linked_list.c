/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:17:45 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/07/31 17:22:51 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_trie	*getlastchild(t_trie *trie)
{
	if (trie)
	{
		while (trie->child)
			trie = trie->next;
	}
	return (trie);
}

t_trie	*getnextfromback(t_trie *trie)
{
	if (trie)
	{
		while (trie->prev && trie->next == NULL)
			trie = trie->prev;
	}
	return (trie);
}

//deletes the current trie path from last returning first node on path that has next
t_trie	*delpath(t_trie *last)
{
	t_trie *current;

	if (!last)
		return (NULL);
	while (last && last->next == NULL)
	{
		current = last->prev;
		free(last);
		last = current;
		last->child = NULL;
	}
	return (last);
}

t_trie *getnextend(t_trie *trie)
{
	if (!trie)
		return (NULL);
	trie = getlastchild(getnextfromback(trie));
	return (trie);
}

void	printops_path(t_trie *cur)
{
	if (!cur)
		return ;
	if (cur->prev)
		printops_path(cur->prev);
	ft_printf("%s\n", cur->op);
}
