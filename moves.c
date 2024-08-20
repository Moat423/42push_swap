/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:34:53 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/08/20 17:01:39 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_countmoves(t_moves *moves)
{
	 return (moves->sa + moves->sb + moves->ra + moves->rb + moves->rra +\
		moves->rrb + moves->ss + moves->rr + moves->rrr);
}

t_dlist	*ft_rotate_moves_to_list(t_moves *moves, t_dlist *curr_node)
{
	while (moves->ra--)
	{
		curr_node = ft_createaddback(&curr_node, "ra");
		if (!curr_node)
			return (0);
	}
	while (moves->rb--)
	{
		curr_node = ft_createaddback(&curr_node, "rb");
		if (!curr_node)
			return (0);
	}
	while (moves->rr--)
	{
		curr_node = ft_createaddback(&curr_node, "rr");
		if (!curr_node)
			return (0);
	}
	return (curr_node);
}

t_dlist *ft_reverse_moves_to_list(t_moves *moves, t_dlist *curr_node)
{
	while (moves->rra--)
	{
		curr_node = ft_createaddback(&curr_node, "rra");
		if (!curr_node)
			return (0);
	}
	while (moves->rrb--)
	{
		curr_node = ft_createaddback(&curr_node, "rrb");
		if (!curr_node)
			return (0);
	}
	while (moves->rrr--)
	{
		curr_node = ft_createaddback(&curr_node, "rrr");
		if (!curr_node)
			return (0);
	}
	return (curr_node);
}

// combine rra and rrb into rrr
void	ft_make_rrr(t_moves *moves)
{
	if (moves->rra && moves->rrb)
	{
		if (moves->rra - moves->rrb < 0)
		{
			moves->rrr = moves->rra;
			moves->rrb = -(moves->rra - moves->rrb);
			moves->rra = 0;
		}
		else
		{
			moves->rrr = moves->rrb;
			moves->rra = (moves->rra - moves->rrb);
			moves->rrb = 0;
		}
	}
}
// combine sa and sb into ss
void	ft_make_ss(t_moves *moves)
{
	if (moves->sa && moves->sb) {
        if (moves->sa - moves->sb < 0) {
            moves->ss = moves->sa;
            moves->sb = -(moves->sa - moves->sb);
            moves->sa = 0;
        } else {
            moves->ss = moves->sb;
            moves->sa = (moves->sa - moves->sb);
            moves->sb = 0;
        }
    }
}
// Combine ra and rb into rr
void	ft_make_rr(t_moves *moves)
{
    if (moves->ra && moves->rb) {
        if (moves->ra - moves->rb < 0) {
            moves->rr = moves->ra;
            moves->rb = -(moves->ra - moves->rb);
            moves->ra = 0;
        } else {
            moves->rr = moves->rb;
            moves->ra = (moves->ra - moves->rb);
            moves->rb = 0;
        }
    }
}

void	ft_make_double_op(t_moves *moves)
{
	ft_make_ss(moves);
	ft_make_rr(moves);
	ft_make_rrr(moves);
}
