/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:57:33 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/08/27 16:32:45 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_exec_moves(t_stack *a, t_stack *b, t_moves *moves, t_dlist **lst)
{
	while ((moves->sa)--)
		sa(lst, a);
	while ((moves->sb)--)
		sb(lst, a);
	while ((moves->ra)--)
		ra(lst, a);
	while ((moves->rb)--)
		rb(lst, a);
	while ((moves->rra)--)
		rra(lst, a);
	while ((moves->rrb)--)
		rrb(lst, a);
	while ((moves->rr)--)
	{
		rr(a, b);
		ft_dlstadd_back(lst, ft_dlstnew("rr"));
	}
	while ((moves->rrr)--)
	{
		rrr(a, b);
		ft_dlstadd_back(lst, ft_dlstnew("rrr"));
	}
	return (1);
}
