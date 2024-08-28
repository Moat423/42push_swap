/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:51:30 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/08/28 09:21:52 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//call other sorting funcitons from here
int	sorting_frame(t_stack *stack_a)
{
	t_stack	stack_b;
	t_dlist	*output;

	output = NULL;
	stack_b.list = NULL;
	if (stack_a->len <= 1 || ft_sorted_ascending(stack_a->list, stack_a->len))
		return (0);
	stack_b.len = 0;
	stack_b.list = calloc(stack_a->len, sizeof(int));
	if (!stack_b.list)
		return (1);
	ft_splitpoint(&output, stack_a, &stack_b);
	if (stack_a->len == 2)
		sa(&output, stack_a);
	if (stack_a->len == 3 && !ft_sorted_ascending(stack_a->list, stack_a->len))
		sort_3_a(&output, stack_a);
	sorting_back(stack_a, &stack_b, &output);
	if (stack_b.list)
		free(stack_b.list);
	ft_printf_dlst(&output);
	ft_dlstclear(&output);
	return (0);
}

// alternatative way to get to b
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
			ft_handle_operations(moves, stack_a, stack_b, midpoint);
		}
	}
}

// does the operations needed for one element to move to b
void	ft_handle_operations(t_dlist **moves, t_stack *a, t_stack *b, int splt)
{
	if (a->list[0] < splt)
	{
		pb(moves, a, b);
		return ;
	}
	else if (a->list[1] < splt)
		ra(moves, a);
	else if (a->list[a->len - 1] < splt)
		rra(moves, a);
	else
	{
		if (ft_rot_or_revrot(a->list, a->len, splt) >= 0)
			ra(moves, a);
		else
			rra(moves, a);
		return ;
	}
	pb(moves, a, b);
	return ;
}

void	ft_splitpoint(t_dlist **moves, t_stack *stack_a, t_stack *stack_b)
{
	int	splitpoint;
	int	chunk_size;

	chunk_size = 19;
	splitpoint = chunk_size;
	while (stack_b->len < splitpoint && stack_a->len > 3)
	{
		while (stack_b->len < splitpoint && stack_a->len > 3)
			ft_handle_operations(moves, stack_a, stack_b, splitpoint + 1);
		splitpoint += chunk_size;
	}
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
