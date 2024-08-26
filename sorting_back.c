/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:59:16 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/08/26 14:06:44 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorting_back(t_stack *stack_a, t_stack *stack_b, t_dlist **output)
{
	t_stack	targets;
	t_dlist	*new_path;
	int	index_min;

	new_path = NULL;
	if (!(ft_push_if_sorted(stack_a, stack_b, &new_path)))
		return (1);
	while (stack_b->len > 0)
	{
		if (-1 == ft_find_optimal_push(stack_a, stack_b, &targets, &new_path))
		{
			free(targets.list);
			return (0);
		}
		ft_dlstadd_back(output, new_path);
		free(targets.list);
		new_path = NULL;
	}
	index_min = ft_index_of_min(stack_a->list, stack_a->len);
	/* ft_printf("A-----------after sorting back\n"); */
	/* ft_printf_int_array(stack_a->list, stack_a->len); */
	/* ft_printf("B-----------after sorting back\n"); */
	/* ft_printf_int_array(stack_b->list, stack_b->len); */
	while (index_min != 0 && index_min <= stack_a->len / 2)
	{
		ra(output, stack_a);
		index_min = ft_index_of_min(stack_a->list, stack_a->len);
	}
	while (ft_index_of_min(stack_a->list, stack_a->len) > stack_a->len / 2)
		rra(output, stack_a);
	return (1);
}

//simple check returning 0 if a and b are sorted, 1 if b is sorted, and 2 if none
int	ft_push_if_sorted(t_stack *stack_a, t_stack *stack_b, t_dlist **path)
{
	if (ft_sorted_descending(stack_b->list, stack_b->len))
	{
		if (ft_sorted_ascending(stack_a->list, stack_a->len))
		{
			while (stack_b->len > 0)
				pa(path, stack_a, stack_b);
			return (0);
		}
		return (1);
	}
	return (2);
}

//decide for element to push to A
// -1 means error
int	ft_find_optimal_push(t_stack *a, t_stack *b, t_stack *targ, t_dlist **path)
{
	t_moves	moves_best;
	t_moves	moves_tmp;
	int		min_moves;
	int		move_count2;
	int		best_index;
	int		i;

	*targ = ft_find_targets(a, b);
	if (!(targ->list))
		return (-1);
	i = 1;
	best_index = 0;
	min_moves = ft_calcmoves(0, targ, a->len, &moves_best);
	while (i < targ->len)
	{
		move_count2 = ft_calcmoves(i, targ, a->len, &moves_tmp);
		if (move_count2 < min_moves)
		{
			moves_best = moves_tmp;
			min_moves = move_count2;
			best_index = i;
		}
		i++;
	}
	ft_exec_moves(a, b, &moves_best, path);
	pa(path, a, b);
	return (best_index);
}

int	ft_calcmoves(int index, t_stack *targets, int len_a, t_moves *moves)
{
	int	cost[4];

	ft_null_moves(moves);
	ft_memset(moves, 0, sizeof(&moves));
	index = 0;
	if (targets->list[index] == -1)
	{
		ft_printf("invalid target for i = %d\n", index);
		exit (1);
	}
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

int	ft_calcmoves_tob(int index, t_stack *targets, int len_b, t_moves *moves)
{
	ft_null_moves(moves);
	ft_memset(moves, 0, sizeof(&moves));
	index = 0;
	if (index <= targets->len / 2)
		moves->ra = index;
	else
		moves->rra = (targets->len - index);
	if (targets->list[index] <= len_b / 2)
		moves->rb = targets->list[index];
	else
		moves->rrb = (len_b - targets->list[index]);
	ft_make_double_op(moves);
	return (ft_countmoves(moves));
}

//returns a positive number or 0 if i should rotate and negative if reverse rotate
int	ft_rot_or_revrot_of_i(int *stack, int len, int nb)
{
	int	top;
	int	bottom;

	top = 0;
	while (top < (len / 2) && stack[top] < nb )
		top++;
	bottom = len - 1;
	while (bottom >= 0 && stack[bottom] < nb)
		bottom--;
	bottom = len - bottom - 1;
	return (bottom - top);
}

