/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:02:56 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/07/31 17:23:03 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_trie	*trienew(char *op, int	moves)
{
	t_trie	*new_node;
	new_node = malloc(sizeof(t_trie));
	if (!new_node)
		return (NULL);
	ft_strlcpy(new_node->op, op, 3);
	new_node->next = NULL;
	new_node->child = NULL;
	new_node->prev = NULL;
	new_node->moves = moves;
	return (new_node);
}

void	trie_curaddchild(t_trie *cur, t_trie *new_node)
{
	t_trie	*tmp;

	if (!cur || !new_node)
		return ;
	tmp = cur;
	while (tmp->child)
		tmp = tmp->child;
	tmp->child = new_node;
	new_node->prev = cur->prev;
}

void	trie_addnext(t_trie **trie, t_trie *new_node)
{
	t_trie	*tmp;

	if (!new_node || !trie)
		return ;
	if (!(*trie))
		*trie = new_node;
	else
	{
		tmp = *trie;
		while ((tmp)->child)
			tmp = tmp->child;
		tmp->next = new_node;
		new_node->prev = tmp->prev;
	}
	return ;

}

void	trie_curaddnext(t_trie *cur, t_trie *new_node)
{
	t_trie	*tmp;

	if (!cur || !new_node)
		return ;
	tmp = cur;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_node;
	new_node->prev = cur->prev;
}

void	trie_addchild(t_trie **trie, t_trie *new_node)
{
	t_trie	*tmp;

	if (!new_node || !trie)
		return ;
	if (!(*trie))
		*trie = new_node;
	else
	{
		tmp = *trie;
		while ((tmp)->child)
			tmp = tmp->child;
		tmp->child = new_node;
		new_node->prev = tmp;
	}
	return ;
}
