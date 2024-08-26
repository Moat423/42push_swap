
#include "push_swap.h"

int	ft_pushsort_to_b(t_stack *stack_a, t_stack *stack_b, t_stack *targets, t_dlist **new_path)
{
	t_moves	moves_best;
	t_moves	moves_tmp;
	int		min_moves;
	int		move_count2;
	int		best_index;
	int		i;
	/* int	prev; */
	/* int	next; */
	/* int	min_of_list; */
	/* int	max_of_list; */

	*targets = ft_find_targets(stack_b, stack_a);
	if (!(targets->list))
		return (-1);
	ft_printf("TARGETS inside pushsorttoB\n");
	ft_printf_int_array(targets->list, targets->len);
	i = 1;
	best_index = 0;
	min_moves = ft_calcmoves_tob(0, targets, stack_b->len, &moves_best);
	while (i < targets->len)
	{
		if (min_moves == 0)
			break;
		move_count2 = ft_calcmoves_tob(i, targets, stack_b->len, &moves_tmp);
		if (move_count2 < min_moves)
		{
			moves_best = moves_tmp;
			min_moves = move_count2;
			best_index = i;
		}
		// put this stupid else into a different function, its too long!
		/* else if (move_count2 == min_moves) */
		/* { */
		/* 	min_of_list = ft_min_of_lst(stack_a->list, stack_a->len); */
		/* 	max_of_list = ft_max_of_lst(stack_a->list, stack_a->len); */
		/* 	next = stack_a->list[targets->list[i]]; */
		/* 	prev = stack_a->list[(targets->list[i] - 1 + stack_a->len) % stack_a->len]; */
		/* 	if (ft_optimal_pos(stack_b->list[i], prev, next, max_of_list, min_of_list) >\ */
		/* 		ft_optimal_pos(stack_b->list[best_index], \ */
		/* 		   stack_a->list[targets->list[best_index]], \ */
		/* 		   stack_a->list[(targets->list[best_index] - 1 + stack_a->len)\ */
		/* 		   % stack_a->len], max_of_list, min_of_list)) */
		/* 	{ */
		/* 		moves_best = moves_tmp; */
		/* 		min_moves = move_count2; */
		/* 		best_index = i; */
		/* 	} */
		/* } */
		i++;
	}
	ft_exec_moves(stack_a, stack_b, &moves_best, new_path);
	pb(new_path, stack_a, stack_b);
	return (best_index);
}

