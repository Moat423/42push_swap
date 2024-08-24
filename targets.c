/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:00:57 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/08/23 15:32:44 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_targets_i(t_stack *stack_a, int value)
{
	int i;
	int	prev_index;

	i = 0;
	if (value > ft_max_of_lst(stack_a->list, stack_a->len))
		return (ft_index_of_max(stack_a->list, stack_a->len));
	if (value < ft_min_of_lst(stack_a->list, stack_a->len))
		return (ft_index_of_min(stack_a->list, stack_a->len));
	while (i < stack_a->len)
	{
		prev_index = ((i - 1 + stack_a->len) % stack_a->len);
		if (value < stack_a->list[i] && value > stack_a->list[prev_index])
	  		return (i);
		i++;
	}
	return (-1);
}

t_stack ft_find_targets(t_stack *stack_a, t_stack *stack_b)
{
	t_stack targets;
	int i;

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
		/* if (targets.list[i] == -1) */
		/* { */
		/* 	ft_printf("invalid target for i = %d\n", i); */
		/* 	exit (1); */
		/* } */
		i++;
	}
	/* ft_printf("targets:\n"); */
	/* ft_printf_int_array(targets.list, targets.len); */
	return (targets);
}

/* // create target for every index, return list of targets */
/* // tries to prefer that both use the same turn direction */
/* void	ft_find_targets(t_stack *stack_a, t_stack *stack_b, t_stack *targets) { */
/* 	int	i; */
/**/
/* 	targets->len = stack_b->len; */
/* 	targets->list = malloc(stack_b->len * sizeof(int)); */
/* 	if (!targets->list) */
/* 		return ; */
/* 	i = 0; */
/* 	while (i < stack_b->len / 2) */
/* 	{ */
/* 		targets->list[i] = ft_getbettertarget_i(stack_a, stack_b->list[i], 0); */
/* 		i++; */
/* 	} */
/* 	while (i < stack_b->len) */
/* 	{ */
/* 		targets->list[i] = ft_getbettertarget_i(stack_a, stack_b->list[i], 1); */
/* 		i++; */
/* 	} */
/* 	return ; */
/* } */

/* int	ft_get_target_i(t_stack *stack, int nb, int pref_bot) */
/* { */
/* 	int	top; */
/* 	int	bottom; */
/**/
/* 	top = 0; */
/* 	while (top < (stack->len / 2) && stack->list[top] < nb) */
/* 		top++; */
/* 	bottom = stack->len - 1; */
/* 	while (bottom >= 0 && stack->list[bottom] < nb) */
/* 		bottom--; */
/* 	if (bottom > top + 1) */
/* 		return (bottom); */
/* 	else if (bottom <= top) */
/* 		return (top); */
/* 	else */
/* 	{ */
/* 		if (pref_bot == 1) */
/* 			return (bottom); */
/* 		else */
/* 			return (top); */
/* 	} */
/* } */
/**/
/* // get a target index to sort nb at good position into stack */
/* int	ft_getbettertarget_i(t_stack *stack, int nb, int pref_bot) */
/* { */
/* 	long	top; */
/* 	long	bottom; */
/* 	long	number; */
/**/
/* 	//top = ft_index_of_min(stack->list, stack->len); */
/* 	number = nb; */
/* 	if (number < stack->list[top]) */
/* 		return (top); */
/* 	top = 0; */
/* 	while (top < stack->len) */
/* 	{ */
/* 		if (stack->list[top] == number + 1 && stack->list[(top + stack->len - 1) % stack->len] == number - 1) */
/* 			return ((top) % stack->len); */
/* 		top++; */
/* 	} */
/* 	top = 0; */
/* 	while (top < (stack->len / 2) && stack->list[top] < number) */
/* 		top++; */
/* 	bottom = stack->len - 1; */
/* 	while (bottom >= 0 && stack->list[bottom] < number) */
/* 		bottom--; */
/* 	if (stack->len - bottom < top + 1) */
/* 		return (bottom); */
/* 	else if (stack->len - bottom > top + 1) */
/* 		return (top); */
/* 	else if (pref_bot == 1) */
/* 		return (bottom); */
/* 	else */
/* 		return (top); */
/* } */

/*
// cmp whether index 1 is at optimal position
int	ft_cmp_inbetween(t_stack *stack_a, t_stack *stack_b, t_stack *targets, int index1, int index2)
{
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
}
*/
