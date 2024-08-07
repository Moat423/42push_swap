/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:58:34 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/08/07 16:55:20 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//does swap on stack_a and adds sa into operation tree
void	sa(t_dlist **node, t_stack *stack)
{
	swap(stack);
	ft_dlstadd_back(node, ft_dlstnew("sa"));
}

void	sb(t_dlist **node, t_stack *stack)
{
	swap(stack);
	ft_dlstadd_back(node, ft_dlstnew("sb"));
}

void	ra(t_dlist **node, t_stack *stack)
{
	rotate(stack);
	ft_dlstadd_back(node, ft_dlstnew("ra"));
}

void	rb(t_dlist **node, t_stack *stack)
{
	rotate(stack);
	ft_dlstadd_back(node, ft_dlstnew("rb"));
}

void	rra(t_dlist **node, t_stack *stack)
{
	reverse_rotate(stack);
	ft_dlstadd_back(node, ft_dlstnew("rra"));
}

void	rrb(t_dlist **node, t_stack *stack)
{
	reverse_rotate(stack);
	ft_dlstadd_back(node, ft_dlstnew("rrb"));
}

void	pa(t_dlist **node,  t_stack *stack_a, t_stack *stack_b)
{
	push_to_2(stack_a, stack_b);
	ft_dlstadd_back(node, ft_dlstnew("pa"));
}

void	pb(t_dlist **node, t_stack *stack_a, t_stack *stack_b)
{
	push_to_2(stack_b, stack_a);
	ft_dlstadd_back(node, ft_dlstnew("pb"));
}
