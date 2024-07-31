/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:28:34 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/07/31 13:09:39 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sa and sb at the same time.
void	ss(int *list_a, int *list_b, int listlen_a, int listlen_b)
{
	swap(list_a, listlen_a);
	swap(list_b, listlen_b);
	return ;
}

// ra and rb at the same time.
void	rr(int *list_a, int *list_b, int listlen_a, int listlen_b)
{
	rotate(list_a, listlen_a);
	rotate(list_b, listlen_b);
	return ;
}

// rra and rrb at the same time.
void	rrr(int *list_a, int *list_b, int listlen_a, int listlen_b)
{
	reverse_rotate(list_a, listlen_a);
	reverse_rotate(list_b, listlen_b);
	return ;
}
