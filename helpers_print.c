/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 16:22:48 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/08/09 16:22:58 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_moves(t_moves *moves)
{
	ft_printf("MOVES:\n");
	ft_printf("sa: %d\n", moves->sa);
	ft_printf("sb: %d\n", moves->sb);
	ft_printf("ra: %d\n", moves->ra);
	ft_printf("rb: %d\n", moves->rb);
	ft_printf("rra: %d\n", moves->rra);
	ft_printf("rrb: %d\n", moves->rrb);
	ft_printf("ss: %d\n", moves->ss);
	ft_printf("rr: %d\n", moves->rr);
	ft_printf("rrr: %d\n", moves->rrr);
	ft_printf("pa: %d\n", moves->pa);
	ft_printf("pb: %d\n", moves->pb);
}

void	testing_operations(t_stack *stack_a)
{
	ft_printf("before\n");
	ft_printf_int_array(stack_a->list, stack_a->len);
	ft_printf("swap\n");
	swap(stack_a);
	ft_printf_int_array(stack_a->list, stack_a->len);
	ft_printf("rotate\n");
	rotate(stack_a);
	ft_printf_int_array(stack_a->list, stack_a->len);
	ft_printf("reverse_rotate\n");
	reverse_rotate(stack_a);
	ft_printf_int_array(stack_a->list, stack_a->len);
}

void	ft_printf_int_array(const int *array, const int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		ft_printf("n%d: %i\n", i, array[i]);
		i++;
	}
}

//while loop to print out charlist to test it
void	ft_printf_char_array(char *const *array, const int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		ft_printf("n%d: %s\n", i, array[i]);
		i++;
	}
}


