/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:44:32 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/08/26 18:25:55 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// remove all entries for rotatios that are not part of the minimum case
void	ft_clean_moves(int rot_case, t_moves *moves)
{
	if (rot_case != 0)
	{
		moves->rr = 0;
		if (rot_case >= 2)
			moves->ra = 0;
		if (rot_case <= 2)
			moves->rrr = 0;
		if (rot_case != 2)
			moves->rb = 0;
		else
			moves->rrb = 0;
		if (rot_case == 1)
			moves->rra = 0;
	}
	else
	{
		moves->rra = 0;
		moves->rrb = 0;
		moves->rrr = 0;
	}
}
