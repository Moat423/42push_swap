/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:14:50 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/08/20 15:59:40 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_min_of_lst(int *list, int len)
{
	int	i;
	int	min;

	i = 1;
	min = list[0];
	while (i < len)
	{
		if (list[i] < min)
			min = list[i];
		i++;
	}
	return (min);
}

int	ft_max_of_lst(int *list, int len)
{
	int	i;
	int	max;

	i = 1;
	max = list[0];
	while (i < len)
	{
		if (list[i] > max)
			max = list[i];
		i++;
	}
	return (max);
}
