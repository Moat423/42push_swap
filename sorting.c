/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:51:30 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/08/09 15:07:59 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/lib_printf/ft_printf.h"
#include "push_swap.h"

//call other sorting funcitons from here
int	sorting_frame(t_stack *stack_a)
{
	t_stack	stack_b;
	// int	elemnbr;
	t_dlist	*output;

	output = NULL;
	// elemnbr = stack_a->len;
	if (stack_a->len <= 1 || ft_sorted_ascending(stack_a->list, stack_a->len))
		return (0);
	ft_printf("not sorted, doing algorithm..................\n");
	stack_b.len = 0;
	stack_b.list = malloc(stack_a->len * sizeof(int));
	if (!stack_b.list)
		return (1);
	ft_midpoint(&output, stack_a, &stack_b);
	ft_printf("print after midpoint:A\n");
	ft_printf_int_array(stack_a->list, stack_a->len);
	ft_printf("print after midpoint:B\n");
	ft_printf_int_array(stack_b.list, stack_b.len);
	if (stack_a->len == 2)
		sa(&output, stack_a);
	if (stack_a->len == 3)
		sort_3_a(&output, stack_a);
	ft_printf("print sort2 and 3 :A\n");
	ft_printf_int_array(stack_a->list, stack_a->len);
	ft_printf_dlst(&output);
	sorting_back(stack_a, &stack_b, &output);
	if (stack_b.list)
		free(stack_b.list);
	ft_printf("output after sorting_back:\n");
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
			if (stack_a->list[0] < midpoint)
				pb(moves, stack_a, stack_b);
			else if (stack_a->list[1] < midpoint)
			{
			//maybe optimize if sa is needed
				ra(moves, stack_a);
				pb(moves, stack_a, stack_b);
			}
			else if (stack_a->list[stack_a->len - 1] < midpoint)
			{
				rra(moves, stack_a);
				pb(moves, stack_a, stack_b);
			}
			else
			{
				if (ft_rot_or_revrot(stack_a->list, stack_a->len, midpoint) >= 0)
					ra(moves, stack_a);
				else
					rra(moves, stack_a);
			}
		}
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

