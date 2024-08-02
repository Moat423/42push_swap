/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:58:34 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/08/02 16:33:26 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//does swap on stack_a and adds sa into operation tree
void	sa(t_trie **node, int *stack, int len)
{
	swap(stack, len);
	trie_addnext(node, trie_new("sa"));
}

void	sb(t_trie **node, int *stack, int len)
{
	swap(stack, len);
	trie_addnext(node, trie_new("sb"));
}

void	ra(t_trie **node, int *stack, int len)
{
	rotate(stack, len);
	trie_addnext(node, trie_new("ra"));
}

void	rb(t_trie **node, int *stack, int len)
{
	rotate(stack, len);
	trie_addnext(node, trie_new("rb"));
}

void	rra(t_trie **node, int *stack, int len)
{
	reverse_rotate(stack, len);
	trie_addnext(node, trie_new("rra"));
}

void	rrb(t_trie **node, int *stack, int len)
{
	reverse_rotate(stack, len);
	trie_addnext(node, trie_new("rrb"));
}

void	pa(t_trie **node, int *stack_a, int len_a, int *stack_b, int len_b)
{
	push_to_2(stack_a, stack_b, len_a, len_b);
	trie_addnext(node, trie_new("pa"));
}

void	pb(t_trie **node, int *stack_a, int len_a, int *stack_b, int len_b)
{
	push_to_2(stack_b, stack_a, len_b, len_a);
	trie_addnext(node, trie_new("pb"));
}
