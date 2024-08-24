/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:51:30 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/08/23 14:43:51 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//call other sorting funcitons from here
int	sorting_frame(t_stack *stack_a)
{
	t_stack	stack_b;
	// int	elemnbr;
	t_dlist	*output;
	/* t_stack	targets; */

	output = NULL;
	// elemnbr = stack_a->len;
	if (stack_a->len <= 1 || ft_sorted_ascending(stack_a->list, stack_a->len))
		return (0);
	stack_b.len = 0;
	stack_b.list = malloc(stack_a->len * sizeof(int));
	if (!stack_b.list)
		return (1);
	/* while (stack_a->len > 3) */
	/* { */
	/* 	if (-1 == ft_pushsort_to_b(stack_a, &stack_b, &targets, &output)) */
	/* 		{ */
	/* 			free(targets.list); */
	/* 			return (1); */
	/* 		} */
	/* 		free(targets.list); */
	/* } */
	/* ft_printf("output before sorting back:\n"); */
	/* ft_printf_dlst(&output); */
	ft_splitpoint(&output, stack_a, &stack_b);
	/* ft_printf("A-----------before sorting back\n"); */
	/* ft_printf_int_array(stack_a->list, stack_a->len); */
	/* ft_printf("B-----------before sorting back\n"); */
	/* ft_printf_int_array(stack_b.list, stack_b.len); */
	if (stack_a->len == 2)
		sa(&output, stack_a);
	if (stack_a->len == 3)
		sort_3_a(&output, stack_a);
	sorting_back(stack_a, &stack_b, &output);
	if (stack_b.list)
		free(stack_b.list);
	/* ft_printf("output after sorting back:\n"); */
	ft_printf_dlst(&output);
	return (0);
}

void	ft_midpoint(t_dlist **moves, t_stack *stack_a, t_stack *stack_b)
{
	int	midpoint;
	int	elemnbr;

	elemnbr = stack_a->len;
	while (stack_a->len > 3)
	{
		midpoint = elemnbr - stack_a->len / 2;
		while (stack_b->len < midpoint && stack_a->len > 3)
		{
			ft_handle_stack_operations(moves, stack_a, stack_b, midpoint);
			/* if (stack_a->list[0] < midpoint) */
			/* 	pb(moves, stack_a, stack_b); */
			/* else if (stack_a->list[1] < midpoint) */
			/* { */
			/* //maybe optimize if sa is needed */
			/* 	ra(moves, stack_a); */
			/* 	pb(moves, stack_a, stack_b); */
			/* } */
			/* else if (stack_a->list[stack_a->len - 1] < midpoint) */
			/* { */
			/* 	rra(moves, stack_a); */
			/* 	pb(moves, stack_a, stack_b); */
			/* } */
			/* else */
			/* { */
			/* 	if (ft_rot_or_revrot(stack_a->list, stack_a->len, midpoint) >= 0) */
			/* 		ra(moves, stack_a); */
			/* 	else */
			/* 		rra(moves, stack_a); */
			/* } */
		}
	}
}

int	ft_pushsort_to_b(t_stack *stack_a, t_stack *stack_b, t_stack *targets, t_dlist **new_path)
{
	t_moves	moves_best;
	t_moves	moves_tmp;
	int		min_moves;
	int		move_count2;
	int		best_index;
	int		i;
	/* int	prev; */
	/* int	next; */
	/* int	min_of_list; */
	/* int	max_of_list; */

	*targets = ft_find_targets(stack_b, stack_a);
	if (!(targets->list))
		return (-1);
	ft_printf("TARGETS inside pushsorttoB\n");
	ft_printf_int_array(targets->list, targets->len);
	i = 1;
	best_index = 0;
	min_moves = ft_calcmoves_tob(0, targets, stack_b->len, &moves_best);
	while (i < targets->len)
	{
		if (min_moves == 0)
			break;
		move_count2 = ft_calcmoves_tob(i, targets, stack_b->len, &moves_tmp);
		if (move_count2 < min_moves)
		{
			moves_best = moves_tmp;
			min_moves = move_count2;
			best_index = i;
		}
		// put this stupid else into a different function, its too long!
		/* else if (move_count2 == min_moves) */
		/* { */
		/* 	min_of_list = ft_min_of_lst(stack_a->list, stack_a->len); */
		/* 	max_of_list = ft_max_of_lst(stack_a->list, stack_a->len); */
		/* 	next = stack_a->list[targets->list[i]]; */
		/* 	prev = stack_a->list[(targets->list[i] - 1 + stack_a->len) % stack_a->len]; */
		/* 	if (ft_optimal_pos(stack_b->list[i], prev, next, max_of_list, min_of_list) >\ */
		/* 		ft_optimal_pos(stack_b->list[best_index], \ */
		/* 		   stack_a->list[targets->list[best_index]], \ */
		/* 		   stack_a->list[(targets->list[best_index] - 1 + stack_a->len)\ */
		/* 		   % stack_a->len], max_of_list, min_of_list)) */
		/* 	{ */
		/* 		moves_best = moves_tmp; */
		/* 		min_moves = move_count2; */
		/* 		best_index = i; */
		/* 	} */
		/* } */
		i++;
	}
	ft_exec_moves(stack_a, stack_b, &moves_best, new_path);
	pb(new_path, stack_a, stack_b);
	return (best_index);
}

void	ft_handle_stack_operations(t_dlist **moves, t_stack *stack_a, t_stack *stack_b, int splitpoint)
{
	if (stack_a->list[0] < splitpoint)
	{
		pb(moves, stack_a, stack_b);
		return ;
	}
	//maybe optimize if sa is needed
	else if (stack_a->list[1] < splitpoint)
	{
		ra(moves, stack_a);
	}
	else if (stack_a->list[stack_a->len - 1] < splitpoint)
		rra(moves, stack_a);
	else
	{
		if (ft_rot_or_revrot(stack_a->list, stack_a->len, splitpoint) >= 0)
			ra(moves, stack_a);
		else
			rra(moves, stack_a);
		return ;
	}
	pb(moves, stack_a, stack_b);
	return ;
}

void	ft_splitpoint(t_dlist **moves, t_stack *stack_a, t_stack *stack_b)
{
	int	splitpoint;
	int	elemnbr;
	int	chunk_size;

	/* splitpoint = 3 / 80 * stack_a->len + 25 / 4; */
	elemnbr = stack_a->len;
	chunk_size = 20;
	splitpoint = chunk_size;
	while (stack_a->len > 3)
	{
		while (stack_b->len < splitpoint && stack_a->len > 3)
		{
			ft_handle_stack_operations(moves, stack_a, stack_b, splitpoint);
		}
		splitpoint += chunk_size;
		/* splitpoint += 3 / 80 * stack_a->len + 25 / 4; */
	}
}


// finds index of number <= nb, ret. pos if close to top, neg. if close to bot
int	ft_rot_or_revrot(int *stack, int len, int nb)
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
// sort 2 elements ascending (swap if in reverse) record in moves
void	sort_2_a(t_dlist **moves, t_stack *stack)
{
	if (stack->list[0]>stack->list[1])
		sa(moves, stack);
	return ;
}

//sort 3 numbers in ascending order
void	sort_3_a(t_dlist **moves, t_stack *stack)
{
	if (stack->list[0] > stack->list[1])
	{
		if (stack->list[0] > stack->list[1] && stack->list[1] > stack->list[2])
		{
			if (stack->list[1] > stack->list[2])
			{
				sa(moves, stack);
				rra(moves, stack);
			}
			else
				ra(moves, stack);
		}
	}
	else if (stack->list[1] > stack->list[2])
	{
		if (stack->list[0] > stack->list[2])
			rra(moves, stack);
		else
		{
			sa(moves, stack);
			ra(moves, stack);
		}
	}
}

// returns 1 if the array is sorted and 0 if there is a number unsorted inside
int	ft_sorted_ascending(int *stack, int len)
{
	int	i;

	i = 0;
	while (i + 1 < len)
	{
		if (stack[i] > stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

// check!
// returns the index of the first item bigger than the previous or length
int	ft_sorted_descending(int *stack, int len)
{
	int	i;

	i = 0;
	while (i + 1 < len)
	{
		if (stack[i]  + 1 == stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

