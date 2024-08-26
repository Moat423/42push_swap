/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:00:57 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/08/26 15:42:56 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_targets_i(t_stack *stack_a, int value)
{
	int	i;
	int	prev_index;

	i = 0;
	if (value > ft_max_of_lst(stack_a->list, stack_a->len))
		return (ft_index_of_max(stack_a->list, stack_a->len));
	if (value < ft_min_of_lst(stack_a->list, stack_a->len))
		return (ft_index_of_min(stack_a->list, stack_a->len));
	while (i < stack_a->len)
	{
		prev_index = ((i - 1 + stack_a->len) % stack_a->len);
		if (value < stack_a->list[i] && value > stack_a->list[prev_index])
			return (i);
		i++;
	}
	return (-1);
}

t_stack	ft_find_targets(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	targets;
	int		i;

	i = 0;
	targets.list = malloc(stack_b->len * sizeof(int));
	if (!targets.list)
	{
		free(targets.list);
		targets.len = 0;
		return (targets);
	}
	targets.len = stack_b->len;
	while (i < stack_b->len)
	{
		targets.list[i] = ft_get_targets_i(stack_a, stack_b->list[i]);
		i++;
	}
	return (targets);
}
