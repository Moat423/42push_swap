/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_true_sorted.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 18:31:35 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/08/27 18:33:30 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// returns 1 if the array is sorted and 0 if there is a number unsorted inside
int	ft_sorted_true_ascending(int *stack, int len)
{
	int	i;

	i = 0;
	while (i + 1 < len)
	{
		if (stack[i] + 1 != stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

// returns the index of the first item bigger than the previous or length
int	ft_sorted_true_descending(int *stack, int len)
{
	int	i;

	i = 0;
	while (i + 1 < len)
	{
		if (stack[i] < stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}
