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

void	sort_3_a(t_trie **begin, int *stack, int	len);

void	sorting_frame(int *stack_a, int elemnb)
{
	//char	**operations;
	int		*stack_b;
	int		len_b;
	int		len_a;
	t_trie	*begin;

	len_a = elemnb;
	len_b = 0;
	begin = NULL;
	stack_b = malloc(elemnb * sizeof(int));
	if (!stack_b)
		return ;
	begin = malloc(sizeof(int));
	if (len_a == 3)
		sort_3_a(&begin, stack_a, len_a);
	if (len_b == 3)
		sort_3_desc(stack_b, len_b);
}

//check!
//sort 3 numbers in ascending order
void	sort_3_a(t_trie **begin, int *stack, int len)
{
	int	i;

	i = 0;
	if (stack[0] > stack[1])
	{
		if (stack[0] > stack[2] && stack[0] < stack[1])
			ra(begin, stack, len);
		else
			sa(begin, stack, len);
	}
}

//check!
// returns the index of the first item, smaller than the previous or length
int	check_ascending(int *stack, int len)
{
	int	i;

	i = 0;
	while (stack[i + 1])
	{
		if (stack[i] > stack[i + 1])
			return (i);
	}
	return (i + 1);
}

// check!
// returns the index of the first item bigger than the previous or length
int	check_descending(int *stack, int len)
{
	int	i;

	i = 0;
	while (stack[i + 1])
	{
		if (stack[i] < stack[i + 1])
			return (i);
	}
	return (i + 1);
}

