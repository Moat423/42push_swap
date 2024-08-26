/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_sorted.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:08:34 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/08/26 14:08:36 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if (stack[i] + 1 == stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

// sort 2 elements ascending (swap if in reverse) record in moves
void	sort_2_a(t_dlist **moves, t_stack *stack)
{
	if (stack->list[0] > stack->list[1])
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
