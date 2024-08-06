/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:51:30 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/08/02 16:33:25 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//call other sorting funcitons from here
int	sorting_frame(t_stack *stack_a)
{
	//char	**operations;
	t_stack	b_value;
	t_stack	*stack_b;
	t_trie	*begin;

	stack_b = &b_value;
	stack_b->len = 0;
	begin = NULL;
	stack_b->list = malloc(stack_a->len * sizeof(int));
	if (!stack_b->list)
		return (1);
	begin = malloc(sizeof(int));
	if (!begin)
		return (1);
	ft_printf("print inside frame:\n");
	ft_printf_int_array(stack_a->list, stack_a->len);
	if (stack_a->len == 3)
		sort_3_a(&begin, stack_a);
	// if (stack_b->len == 3)
		//sort_3_desc(stack_b, stack_b->len);
	if (stack_b->list)
		free(stack_b->list);
	return (0);
}

//sort 3 numbers in ascending order
void	sort_3_a(t_trie **begin, t_stack *stack)
{
	int	i;
	begin = NULL;

	i = 0;
	if (stack->list[0] < stack->list[1] && stack->list[1] < stack->list[2])
		return ;
	if (stack->list[0] > stack->list[1])
	{
		if (stack->list[0] > stack->list[1] && stack->list[1] > stack->list[2])
		{
			if (stack->list[1] > stack->list[2])
			{
				swap(stack);
				reverse_rotate(stack);
			}
			else
				rotate(stack);
		}
	}
	else if (stack->list[1] > stack->list[2])
	{
		if (stack->list[0] > stack->list[2])
			reverse_rotate(stack);
		else
		{
			swap(stack);
			rotate(stack);
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
