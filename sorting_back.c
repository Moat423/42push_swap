/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:59:16 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/08/09 17:15:47 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//decide for element to push to A
// -1 means error
int	ft_find_optimal_push(t_stack *stack_a, t_stack *stack_b, t_dlist **new_path)
{
	t_stack	targets;
	int		index_to_push;

	ft_find_targets(stack_a, stack_b, &targets);
	if (targets.list)
		return (-1);
	index_to_push = ft_find_min_moves(stack_a, stack_b, &targets, new_path);
	return (index_to_push);
}

// compare movecount and factors to decide for shortest and optimal path
int ft_find_min_moves(t_stack *stack_a, t_stack *stack_b, t_stack *targets, t_dlist **min_path)
{
	t_dlist	*path2;
	int		min_moves;
	int		move_count2;
	int		best_index;
	int	i;
	int	prev;
	int	next;
	int	min_of_list;
	int	max_of_list;


	i = 1;
	min_moves = ft_find_moves(stack_a, stack_b, targets->list[0], min_path);
	best_index = 0;
	while (i < targets->len)
	{
		move_count2 = ft_find_moves(stack_a, stack_b, targets->list[i], &path2);
		if (move_count2 < min_moves)
		{
			min_path = &path2;
			min_moves = move_count2;
			best_index = i;
		}
		// put this stupid else into a different function, its too long!
		else if (move_count2 == min_moves)
		{
			min_of_list = ft_min_of_lst(stack_a->list, stack_a->len);
			max_of_list = ft_max_of_lst(stack_a->list, stack_a->len);
			next = stack_a->list[targets->list[i]];
			prev = stack_a->list[(targets->list[i] - 1 + stack_a->len) % stack_a->len];
			if (ft_optimal_pos(stack_b->list[i], prev, next, max_of_list, min_of_list) >\
				ft_optimal_pos(stack_b->list[best_index], \
				   stack_a->list[targets->list[best_index]], \
				   stack_a->list[(targets->list[best_index] - 1 + stack_a->len)\
				   % stack_a->len], max_of_list, min_of_list))
			{
				min_path = &path2;
				min_moves = move_count2;
				best_index = i;
			}
		}
	}
	return (best_index);
}


// returns number of moves and saves moves needed to path
int	ft_find_moves(t_stack *stack_a, t_stack *stack_b, int target_i, t_dlist **path)
{
	int	moves_count;

	moves_count = 0;
	return (moves_count);
}

// create target for every index, return list of targets
// tries to prefer that both use the same turn direction
void	ft_find_targets(t_stack *stack_a, t_stack *stack_b, t_stack *targets)
{
	int	i;

	targets->len = stack_b->len;
	targets->list = malloc(stack_b->len * sizeof(int));
	if (!targets->list)
		return ;
	i = 0;
	while (i < stack_b->len / 2)
		targets->list[i] = ft_get_target_i(stack_a->list, stack_a->len, stack_b->list[i], 0);
	while (i < stack_b->len)
		targets->list[i] = ft_get_target_i(stack_a->list, stack_a->len, stack_b->list[i], 1);
	return ;
}

int	ft_get_target_i(int *stack, int len, int nb, int pref_bot)
{
	int	top;
	int	bottom;

	top = 0;
	while (top < (len / 2) && stack[top] < nb)
		top++;
	bottom = len - 1;
	while (bottom >= 0 && stack[bottom] < nb)
		bottom--;
	if (bottom > top + 1)
		return (bottom);
	else if (bottom <= top)
		return (top);
	else
	{
		if (pref_bot == 1)
			return (bottom);
		else
			return (top);
	}
}

// returns 0 if number right between prev and next
// else returns lowest distance from next or prev 
int	ft_optimal_pos(const int nb, const int prev, const int next, const int	max, const int min)
{
	int	dist_prev;
	int	dist_next;

	if (prev == max)
		dist_prev = 1;
	else
		dist_prev = nb - prev;
	if (next == min)
		dist_next = 1;
	else
		dist_next = next - nb;
	if (dist_prev == 1 && dist_next == 1)
		return (0);
	if (dist_prev < dist_next)
		return (dist_prev);
	else
		return (dist_next);
}

// finds index of number <= nb, ret. pos if close to top, neg. if close to bot
int	ft_rot_or_revrot(int *stack, int len, int nb)
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

//fkt to add optimal moves to list and executing optimal path
//gets index of element to move

// make new list and add moves to get to position element should be in
//int	find_moves_to_pos(t_dlist	**moves, int *stack, int len, t_stack *targets)
