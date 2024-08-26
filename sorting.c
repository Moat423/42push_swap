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
	/* ft_printf("A-----------before storing back\n"); */
	/* ft_printf_int_array(stack_a->list, stack_a->len); */
	/* ft_printf("B-----------before storing back\n"); */
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
	ft_dlstclear(&output);
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

void	ft_handle_stack_operations(t_dlist **moves, t_stack *stack_a, t_stack *stack_b, int splitpoint)
{
	if (stack_a->list[0] < splitpoint)
	{
		pb(moves, stack_a, stack_b);
		return ;
	}
	else if (stack_a->list[1] < splitpoint)
		ra(moves, stack_a);
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
	int	chunk_size;

	/* splitpoint = 3 / 80 * stack_a->len + 25 / 4; */
	chunk_size = 19;
	splitpoint = chunk_size;
	while (stack_b->len < splitpoint && stack_a->len > 3)
	{
        /* if (splitpoint > stack_a->len - 3) */
        /*     splitpoint = elemnbr - 3; */
        while (stack_b->len < splitpoint && stack_a->len > 3)
            ft_handle_stack_operations(moves, stack_a, stack_b, splitpoint + 1);
		splitpoint += chunk_size;
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
