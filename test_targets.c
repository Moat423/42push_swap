/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_targets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:19:37 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/08/21 12:20:43 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	main(void)
{
	t_stack targets;
    // Create sample stack_a
    t_stack stack_a;
    stack_a.list = (int[]){10, 20, 30, 40, 50};
    stack_a.len = 5;

    // Create sample stack_b
    t_stack stack_b;
    stack_b.list = (int[]){15, 25, 35, 45};
    stack_b.len = 4;

    // Print initial stacks
    ft_printf("Stack A\n");
    ft_printf_int_array(stack_a.list, stack_a.len);
    ft_printf("Stack B\n");
    ft_printf_int_array(stack_b.list, stack_b.len);

    // Call ft_find_targets
    targets = ft_find_targets(&stack_a, &stack_b);

    // Print results
    ft_printf("Targets found:\n");
    for (int i = 0; i < targets.len; i++) {
        ft_printf("For B[%d] = %d, target in A is index %d\n", i, stack_b.list[i], targets.list[i]);
    }

    // Free allocated memory
    free(targets.list);

    return 0;
}
