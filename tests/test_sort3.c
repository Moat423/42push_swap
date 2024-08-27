/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sort3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:24:49 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/08/27 15:01:07 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

/*
cc tests/test_sort3.c helpers_print.c op_push.c helpers_sorted.c op_push2.c push_swap.h libft/libft.a dlist_helpers.c double_linked_list.c operations.c operations2.c -g
*/

void	sort_3_a(t_dlist **moves, t_stack *stack);

int	main(void)
{
	t_stack	s;
	int	arr[3] = {2, 1, 3};
	t_dlist *moves;

	s.len = 3;
	s.list = arr;
	printf("ARRAY 1:\n");
	ft_printf_int_array(s.list, s.len);
	sort_3_a(NULL, &s);
	printf("sorted:\n");
	ft_printf_int_array(s.list, s.len);

	s.list[0] = 2;
	s.list[1] = 3;
	s.list[2] = 1;
	printf("ARRAY 2:\n");
	ft_printf_int_array(s.list, s.len);
	sort_3_a(NULL, &s);
	printf("sorted:\n");
	ft_printf_int_array(s.list, s.len);

	s.list[0] = 3;
	s.list[1] = 2;
	s.list[2] = 1;
	printf("ARRAY 3:\n");
	ft_printf_int_array(s.list, s.len);
	sort_3_a(NULL, &s);
	printf("sorted:\n");
	ft_printf_int_array(s.list, s.len);

	s.list[0] = 3;
	s.list[1] = 1;
	s.list[2] = 2;
	printf("ARRAY 4:\n");
	ft_printf_int_array(s.list, s.len);
	sort_3_a(NULL, &s);
	printf("sorted:\n");
	ft_printf_int_array(s.list, s.len);
	
	s.list[0] = 1;
	s.list[1] = 3;
	s.list[2] = 2;
	printf("ARRAY 5:\n");
	ft_printf_int_array(s.list, s.len);
	sort_3_a(NULL, &s);
	printf("sorted:\n");
	ft_printf_int_array(s.list, s.len);
	return (0);
}
