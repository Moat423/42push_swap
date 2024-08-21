/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:59:16 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/08/20 17:50:35 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/lib_printf/ft_printf.h"
#include "push_swap.h"

int	sorting_back(t_stack *stack_a, t_stack *stack_b, t_dlist **output)
{
	t_stack	targets;
	t_dlist	*new_path;
	int	index_min;

	if (!(ft_push_if_sorted(stack_a, stack_b, &new_path)))
		return (1);
	while (stack_b->len > 0)
	{
		new_path = NULL;
		if (-1 == ft_find_optimal_push(stack_a, stack_b, &targets, &new_path))
		{
			free(targets.list);
			return (0);
		}
		ft_dlstadd_back(output, new_path);
		free(targets.list);
	}
	index_min = ft_index_of_min(stack_a->list, stack_a->len);
	ft_printf("A sorted but not at right pos:\n");
	ft_printf_int_array(stack_a->list, stack_a->len);
	ft_printf("index_min: %d\n", index_min);
	while (index_min != 0 && index_min < stack_a->len / 2)
		ra(output, stack_a);
	while (index_min != 0 && index_min > stack_a->len / 2)
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
int	ft_find_optimal_push(t_stack *stack_a, t_stack *stack_b, t_stack *targets, t_dlist **new_path)
{
	t_moves	moves_best;
	t_moves	moves_tmp;
	int		min_moves;
	int		move_count2;
	int		best_index;
	int		i;
	int	prev;
	int	next;
	int	min_of_list;
	int	max_of_list;

	*targets = ft_find_targets(stack_a, stack_b);
	if (!(targets->list))
		return (-1);
	i = 1;
	best_index = 0;
	min_moves = ft_calcmoves(0, targets, stack_a->len, &moves_best);
	while (i < targets->len)
	{
		if (min_moves == 0)
			break;
		move_count2 = ft_calcmoves(i, targets, stack_a->len, &moves_tmp);
		if (move_count2 < min_moves)
		{
			moves_best = moves_tmp;
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
				moves_best = moves_tmp;
				min_moves = move_count2;
				best_index = i;
			}
		}
		i++;
	}
	ft_printf("min_moves:%d\n", min_moves);
	ft_printf("best_index:%d\n", best_index);
	ft_exec_moves(stack_a, stack_b, &moves_best, new_path);
	pa(new_path, stack_a, stack_b);
	return (best_index);
}

/* //neg movecount is rra/rrb, positive is ra/rb */
/* int	ft_movecount(t_stack *stack_a, t_stack *stack_b, t_stack *targets) */
/* { */
/* 	int	movecount_a; */
/* 	int	movecount_b; */
/* 	int	movecount; */
/* 	int	pushobj; */
/* 	int	i; */
/**/
/* 	movecount_a = 0; */
/* 	movecount_b = 0; */
/* 	i = 0; */
/* 	pushobj = 0; */
/* 	while (i < targets->len) */
/* 	{ */
/* 		if (i < stack_b->len / 2) */
/* 			movecount_b = i; */
/* 		else */
/* 			movecount_b = -(stack_b->len - i); */
/* 		if (targets->list[i] < targets->len / 2) */
/* 			movecount_a = targets->list[i]; */
/* 		else */
/* 			movecount_a = -(targets->len - targets->list[i]); */
/* 		if (movecount_a >= 0 && movecount_b >= 0) */
/**/
/* 		if (i <= (stack_b->len / 2) && targets->list[i] <= stack_a->len / 2) */
/* 			movecount = i - targets->list[i]; */
/* 		if (i <= (stack_b->len / 2) && targets->list[i] <= stack_a->len / 2) */
/* 			movecount = i + targets->list[i] + 1; */
/* 		if (ABS(movecount_a - movecount_b) < movecount_a + movecount_b) */
/* 		movecount = min(movecount_a, movecount_b) + max(movecount_a, movecount_b) - min(movecount_a, movecount_b); */
/* 	} */
/* 	return (pushobj); */
/* } */

int	ft_calcmoves(int index, t_stack *targets, int len_a, t_moves *moves)
{
	int	pushobj;

	ft_null_moves(moves);
	ft_memset(moves, 0, sizeof(&moves));
	index = 0;
	pushobj = 0;
	if (index <= targets->len / 2)
		moves->rb = index;
	else
		moves->rrb = (targets->len - index);
	if (targets->list[index] <= len_a / 2)
		moves->ra = targets->list[index];
	else
		moves->rra = (len_a - targets->list[index]);
	ft_make_double_op(moves);
	return (ft_countmoves(moves));
}

/* // compare movecount and factors to decide for shortest and optimal path */
/* int ft_find_min_moves(t_stack *stack_a, t_stack *stack_b, t_stack *targets, t_dlist **min_path) */
/* { */
/* 	t_dlist	*path2; */
/* 	int		min_moves; */
/* 	int		move_count2; */
/* 	int		best_index; */
/* 	int	i; */
/* 	int	prev; */
/* 	int	next; */
/* 	int	min_of_list; */
/* 	int	max_of_list; */
/**/
/**/
/* 	i = 1; */
/* 	min_moves = ft_find_moves(stack_a, stack_b, 0, targets->list[0], min_path); */
/* 	best_index = 0; */
/* 	while (i < targets->len) */
/* 	{ */
/* 		move_count2 = ft_find_moves(stack_a, stack_b, i, targets->list[i], &path2); */
/* 		if (move_count2 < min_moves) */
/* 		{ */
/* 			min_path = &path2; */
/* 			min_moves = move_count2; */
/* 			best_index = i; */
/* 		} */
/* 		// put this stupid else into a different function, its too long! */
/* 		else if (move_count2 == min_moves) */
/* 		{ */
/* 			min_of_list = ft_min_of_lst(stack_a->list, stack_a->len); */
/* 			max_of_list = ft_max_of_lst(stack_a->list, stack_a->len); */
/* 			next = stack_a->list[targets->list[i]]; */
/* 			prev = stack_a->list[(targets->list[i] - 1 + stack_a->len) % stack_a->len]; */
/* 			if (ft_optimal_pos(stack_b->list[i], prev, next, max_of_list, min_of_list) >\ */
/* 				ft_optimal_pos(stack_b->list[best_index], \ */
/* 				   stack_a->list[targets->list[best_index]], \ */
/* 				   stack_a->list[(targets->list[best_index] - 1 + stack_a->len)\ */
/* 				   % stack_a->len], max_of_list, min_of_list)) */
/* 			{ */
/* 				min_path = &path2; */
/* 				min_moves = move_count2; */
/* 				best_index = i; */
/* 			} */
/* 		} */
/* 		if (min_moves == 1) */
/* 			break; */
/* 	} */
/* 	return (best_index); */
/* } */
/**/
/* // returns number of moves and saves moves needed to path */
/* int	ft_find_moves(t_stack *stack_a, t_stack *stack_b, int curr_index, int target_index, t_dlist **path) */
/* { */
/* 	int	moves_b; */
/* 	int	moves_a; */
/* 	int	moves_count; */
/* 	t_dlist	*curr_node; */
/**/
/* 	if (curr_index > (stack_b->len / 2)) */
/* 		moves_b = stack_b->len - curr_index; */
/* 	else */
/* 		moves_b = curr_index; */
/* 	if (target_index > (stack_a->len / 2)) */
/* 		moves_a = stack_a->len - target_index; */
/* 	else */
/* 		moves_a = target_index; */
/* 	curr_node = *path; */
/* 	if (curr_index <= (stack_b->len / 2) && target_index <= stack_a->len / 2) */
/* 	{ */
/* 		moves_count = curr_index - target_index; */
/* 		while (moves_count--) */
/* 		{ */
/* 			curr_node = ft_createaddback(&curr_node, "rb"); */
/* 			if (!curr_node) */
/* 				return (0); */
/* 		} */
/* 		while (target_index--) */
/* 		{ */
/* 			curr_node = ft_createaddback(&curr_node, "rb"); */
/* 			if (!curr_node) */
/* 				return (0); */
/* 		} */
/* 	} */
/* 	if (curr_index > (stack_b->len / 2) && target_index > stack_a->len / 2) */
/* 	{ */
/* 		moves_count = curr_index + target_index + 1; */
/* 		while (curr_index--) */
/* 		{ */
/* 			curr_node = ft_createaddback(&curr_node, "rb"); */
/* 			if (!curr_node) */
/* 				return (0); */
/* 		} */
/* 		while (target_index--) */
/* 		{ */
/* 			curr_node = ft_createaddback(&curr_node, "rb"); */
/* 			if (!curr_node) */
/* 				return (0); */
/* 		} */
/* 	} */
/* 	assert(moves_count == ft_dlstsize(*path)); */
/* 	return (1); */
/* } */

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
