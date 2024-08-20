/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:57:33 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/08/20 17:02:14 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_exec_moves(t_stack *stack_a, t_stack *stack_b, t_moves *moves, t_dlist **lst)
{
	while (moves->sa)
		sa(lst, stack_a);
	while (moves->sb)
		sb(lst, stack_a);
	while (moves->ra--)
		ra(lst, stack_a);
	while (moves->rb--)
		rb(lst, stack_a);
	while (moves->rra--)
		rra(lst, stack_a);
	while (moves->rrb--)
		rrb(lst, stack_a);
	while (moves->rr--)
	{
		rr(stack_a, stack_b);
		ft_dlstadd_back(lst, ft_dlstnew("rr"));
	}
	while (moves->rrr--)
	{
		rrr(stack_a, stack_b);
		ft_dlstadd_back(lst, ft_dlstnew("rrr"));
	}
	return (1);
}
