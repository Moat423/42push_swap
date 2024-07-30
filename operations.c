/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:07:53 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/07/23 16:21:46 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "newlib.h"
//not correct, needs to rotate down!!!!!!!1
void	ra(int *list, int listlen)
{
	int	buffer;

	buffer = list[0];
	list[0] = list[listlen - 1];
	list[listlen - 1] = buffer;
}

void	sa(int	*list)
{
	int	buffer;

	buffer = list[0];
	list[0] = list[1];
	list[1] = buffer;
}

void	rra(int *list, int listlen)
{

}
