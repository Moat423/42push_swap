/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:58:34 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/08/26 15:54:41 by lmeubrin         ###   ########.fr       */
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
