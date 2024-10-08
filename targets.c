/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:00:57 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/08/28 09:15:01 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/lib_printf/ft_printf.h"
#include "push_swap.h"

int	ft_get_targets_i(t_stack *s_a, int value)
{
	int	i;
	int	dst;
	int	dst_tmp;
	int	best_target;

	i = 0;
	if (value > ft_max_of_lst(s_a->list, s_a->len))
		return (ft_index_of_max(s_a->list, s_a->len) + 1 % s_a->len);
	if (value < ft_min_of_lst(s_a->list, s_a->len))
		return (ft_index_of_min(s_a->list, s_a->len));
	dst = INT_MAX;
	best_target = -1;
	while (i < s_a->len)
	{
		dst_tmp = s_a->list[i] - value;
		if (dst_tmp > 0 && dst_tmp < dst)
		{
			best_target = i;
			dst = dst_tmp;
		}
		i++;
	}
	return (best_target);
}

t_stack	ft_find_targets(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	targets;
	int		i;

	i = 0;
	targets.list = malloc(stack_b->len * sizeof(int));
	if (!targets.list)
	{
		free(targets.list);
		targets.len = 0;
		return (targets);
	}
	targets.len = stack_b->len;
	while (i < stack_b->len)
	{
		targets.list[i] = ft_get_targets_i(stack_a, stack_b->list[i]);
		i++;
	}
	return (targets);
}

//returns nb >= 0 if i should rotate and negative if reverse rotate
int	ft_rot_or_revrot_of_i(int *stack, int len, int nb)
{
	int	top;
	int	bottom;

	top = 0;
	while (top < (len / 2) && stack[top] < nb)
		top++;
	bottom = len - 1;
	while (bottom >= 0 && stack[bottom] < nb)
		bottom--;
	bottom = len - bottom - 1;
	return (bottom - top);
}

// saves cost for all movecombinations in array and returns best moves
int	ft_calcmoves(int index, t_stack *targets, int len_a, t_moves *moves)
{
	int	cost[4];

	ft_null_moves(moves);
	ft_memset(moves, 0, sizeof(&moves));
	index = 0;
	moves->rb = index;
	moves->rrb = (targets->len - index);
	moves->ra = targets->list[index];
	moves->rra = (len_a - targets->list[index]);
	cost[0] = moves->ra + moves->rb - min(moves->ra, moves->rb);
	cost[1] = moves->ra + moves->rrb;
	cost[2] = moves->rra + moves->rb;
	cost[3] = moves->rra + moves->rrb - min(moves->rra, moves->rrb);
	ft_clean_moves(ft_index_of_min(cost, 4), moves);
	return (ft_countmoves(moves));
}

//simple check 0 if a and b are sorted, 1 if b is sorted, and 2 if none
int	ft_push_if_sorted(t_stack *stack_a, t_stack *stack_b, t_dlist **path)
{
	if (!stack_b->list || \
		(ft_sorted_true_descending(stack_b->list, stack_b->len) \
		&& stack_b->list[0] < stack_a->list[0]))
	{
		if (ft_sorted_true_ascending(stack_a->list, stack_a->len))
		{
			while (stack_b->len > 0)
				pa(path, stack_a, stack_b);
			return (0);
		}
		return (1);
	}
	return (2);
}
