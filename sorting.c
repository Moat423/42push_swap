/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:51:30 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/07/31 17:23:01 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(int *stack);

void	sorting_frame(int *stack_a, int elemnb)
{
	//char	**operations;
	int	*stack_b;
	int	len_b;
	int	len_a;

	len_a = elemnb;
	len_b = 0;
	stack_b = malloc(elemnb * sizeof(int));
	if (!stack_b)
		return ;
	if (len_a == 3)
		sort_3(stack_a);
	if (len_b == 3)
		sort_3(stack_b);
}
