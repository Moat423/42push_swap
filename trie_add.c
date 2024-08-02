/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:02:56 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/08/02 14:11:34 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//returns a new node with moves inside
t_trie	*trie_new(char *op)
{
	t_trie	*new_node;
	new_node = malloc(sizeof(t_trie));
	if (!new_node)
		return (NULL);
	ft_strlcpy(new_node->op, op, 3);
	new_node->next = NULL;
	new_node->child = NULL;
	new_node->prev = NULL;
	new_node->moves = 0;
	return (new_node);
}

//adds a new path of moves, branching off from tree at last node
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
		while ((tmp)->next)
			tmp = tmp->next;
		tmp->child = new_node;
		new_node->prev = tmp->prev;
		new_node->moves = tmp->moves;
	}
	return ;
}

//make new child !after cur node (branching off)
void	trie_insertchild(t_trie *cur, t_trie *new_node)
{

	if (!cur || !new_node)
		return ;
	cur->next->child = new_node;
	new_node->prev = cur;
	new_node->moves = cur->moves + 1;
}

// adds next new_node to end
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
		while ((tmp)->next)
			tmp = tmp->next;
		tmp->next = new_node;
		new_node->prev = tmp;
		new_node->moves = tmp->moves + 1;
	}
	return ;

}

// inserts next !after cur
void	trie_insertnext(t_trie *cur, t_trie *new_node)
{
	t_trie	*tmp;

	if (!cur || !new_node)
		return ;
	tmp = cur->next;
	cur->next = new_node;
	new_node->prev = cur;
	new_node->next = tmp;
	new_node->moves = tmp->moves + 1;
	while ((tmp)->next)
	{
		tmp->moves++;
		tmp = tmp->next;
	}
	tmp->next = new_node;
}
