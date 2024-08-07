/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:51:30 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/08/07 17:11:13 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/lib_printf/ft_printf.h"
#include "push_swap.h"

//call other sorting funcitons from here
int	sorting_frame(t_stack *stack_a)
{
	t_stack	stack_b;
	int	elemnbr;
	t_stack	targets;
	t_dlist	*output;

	elemnbr = stack_a->len;
	if (stack_a->len <= 1 || ft_is_sorted(stack_a->list, stack_a->len))
		return (0);
	ft_printf("not sorted, doing algorithm..................\n");
	stack_b.len = 0;
	stack_b.list = malloc(stack_a->len * sizeof(int));
	if (!stack_b.list)
		return (1);
	ft_printf("print inside frame:\n");
	ft_printf_int_array(stack_a->list, stack_a->len);
	if (stack_a->len == 2)
		sa(&output, stack_a);
	if (stack_a->len == 3)
		sort_3_a(&output, stack_a);
	if (stack_b.list)
		free(stack_b.list);
	return (0);
}

// returns 1 if the array is sorted and 0 if there is a number unsorted inside
int	ft_is_sorted(int *stack, int len)
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

//fkt to add optimal moves to list and executing optimal path
//gets index of element to move

// make new list and add moves to get to position element should be in
//int	find_moves_to_pos(t_dlist	**moves, int *stack, int len, t_stack *targets)
/*
void	midpoint(t_moves *moves, t_stack *stack_a, t_stack *stack_b)
{
	int	midpoint;
}
*/

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

// //check!
// // returns the index of the first item, smaller than the previous or length
// int	check_ascending(int *stack, int len)
// {
// 	int	i;
//
// 	i = 0;
// 	while (stack[i + 1])
// 	{
// 		if (stack[i] > stack[i + 1])
// 			return (i);
// 	}
// 	return (i + 1);
// }
//
// // check!
// // returns the index of the first item bigger than the previous or length
// int	check_descending(int *stack, int len)
// {
// 	int	i;
//
// 	i = 0;
// 	while (stack[i + 1])
// 	{
// 		if (stack[i] < stack[i + 1])
// 			return (i);
// 	}
// 	return (i + 1);
// }
//
