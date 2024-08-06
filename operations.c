/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations->c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student->42berlin->       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:07:53 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/07/31 12:28:40 by lmeubrin         ###   ########->fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Swap the first 2 elements at the top of stack a.
//Do nothing if there is only one or no elements.
void	swap(t_stack *stack)
{
	int	buffer;

	if (stack->len <= 1)
		return ;
	buffer = stack->list[0];
	stack->list[0] = stack->list[1];
	stack->list[1] = buffer;
	return ;
}

//Shift up all elements of stack a by 1.
// The first element becomes the last one.
void	rotate(t_stack *stack)
{
	int	buffer;
	int	i;

	i = 0;
	buffer = stack->list[0];
	while (i + 1 < stack->len)
	{
		stack->list[i] = stack->list[i + 1];
		i++;
	}
	stack->list[stack->len - 1] = buffer;
	return ;
}

// Shift down all elements of stack a by 1.
// The last element becomes the first one.
void	reverse_rotate(t_stack *stack)
{
	int	buffer;
	int	i;

	i = stack->len - 1;
	buffer = stack->list[i];
	while (i > 0)
	{
		stack->list[i] = stack->list[i - 1];
		i--;
	}
	stack->list[0] = buffer;
	return ;
}

// Take the first element at the top of 1 and put it at the top of 2.
// Do nothing if 1 is empty.
void	push_to_2(t_stack *stack_1, t_stack *stack_2)
{
	int	i;

	if (stack_1->len == 0)
		return ;
	i = 0;
	while (i <= stack_2->len)
	{
		stack_2->list[i] = stack_2->list[i + 1];
		i++;
	}
	stack_2->list[0] = stack_1->list[0];
	i = 0;
	while (i + 1 <= stack_1->len)
	{
		stack_1->list[i] = stack_1->list[i + 1];
		i++;
	}
	return ;
}
