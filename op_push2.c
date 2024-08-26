/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:48:17 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/08/26 15:48:51 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb(t_dlist **node, t_stack *stack)
{
	reverse_rotate(stack);
	ft_dlstadd_back(node, ft_dlstnew("rrb"));
}

void	pa(t_dlist **node,  t_stack *stack_a, t_stack *stack_b)
{
	push_to_2(stack_b, stack_a);
	ft_createaddback(node, "pa");
	/* ft_dlstadd_back(node, ft_dlstnew("pa")); */
}

void	pb(t_dlist **node, t_stack *stack_a, t_stack *stack_b)
{
	push_to_2(stack_a, stack_b);
	ft_dlstadd_back(node, ft_dlstnew("pb"));
}

void	do_ss(t_dlist **node,  t_stack *stack_a, t_stack *stack_b)
{
	ss(stack_a, stack_b);
	ft_dlstadd_back(node, ft_dlstnew("ss"));
}
