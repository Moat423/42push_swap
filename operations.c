/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:07:53 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/07/31 12:28:40 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Swap the first 2 elements at the top of stack a.
//Do nothing if there is only one or no elements.
void	swap(int	*list, int listlen)
{
	int	buffer;

	if (listlen <= 1)
		return ;
	buffer = list[0];
	list[0] = list[1];
	list[1] = buffer;
	return ;
}

//Shift up all elements of stack a by 1.
// The first element becomes the last one.
void	rotate(int *list, int listlen)
{
	int	buffer;
	int	i;

	i = 0;
	buffer = list[0];
	while (i + 1 < listlen)
	{
		list[i] = list[i + 1];
		i++;
	}
	list[listlen - 1] = buffer;
	return ;
}

// Shift down all elements of stack a by 1.
// The last element becomes the first one.
void	reverse_rotate(int *list, int listlen)
{
	int	buffer;
	int	i;

	i = 0;
	buffer = list[listlen--];
	while (i < listlen)
	{
		list[i] = list[i + 1];
		i++;
	}
	list[0] = buffer;
	return ;
}

// Take the first element at the top of 1 and put it at the top of 2.
// Do nothing if 1 is empty.
void	push_to_2(int *list_1, int *list_2, int listlen_1, int listlen_2)
{
	int	i;

	if (listlen_1 == 0)
		return ;
	i = 0;
	while (i < listlen_2)
	{
		list_2[i] = list_2[i + 1];
		i++;
	}
	list_2[0] = list_1[0];
	i = 0;
	while (i + 1 < listlen_1)
	{
		list_1[i] = list_1[i + 1];
		i++;
	}
	return ;
}
