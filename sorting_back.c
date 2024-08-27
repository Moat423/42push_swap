/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:59:16 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/08/27 14:14:38 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorting_back(t_stack *stack_a, t_stack *stack_b, t_dlist **output)
{
	t_stack	targets;
	t_dlist	*new_path;
	int		min;

	new_path = NULL;
	if (!(ft_push_if_sorted(stack_a, stack_b, &new_path)))
		return (1);
	while (stack_b->len > 0)
	{
		if (-1 == ft_find_optimal_push(stack_a, stack_b, &targets, &new_path))
		{
			free(targets.list);
			return (0);
		}
		ft_dlstadd_back(output, new_path);
		free(targets.list);
		new_path = NULL;
	}
	min = ft_min_of_lst(stack_a->list, stack_a->len);
	ft_rotate_nb_to_top(min, stack_a, output);
	/* index_min = ft_index_of_min(stack_a->list, stack_a->len); */
	/* while (index_min != 0 && index_min <= stack_a->len / 2) */
	/* { */
	/* 	ra(output, stack_a); */
	/* 	index_min = ft_index_of_min(stack_a->list, stack_a->len); */
	/* } */
	/* while (ft_index_of_min(stack_a->list, stack_a->len) > stack_a->len / 2) */
	/* 	rra(output, stack_a); */
	return (1);
}

void	ft_rotate_nb_to_top(int nb, t_stack *stack_a, t_dlist **output)
{
	int	index_nb;

	index_nb = ft_index_of_nb(nb, stack_a->list, stack_a->len);
	while (index_nb > 0 && index_nb <= stack_a->len / 2)
	{
		ra(output, stack_a);
		index_nb--;
	}
	while (ft_index_of_nb(nb, stack_a->list, stack_a->len) \
			&& index_nb > stack_a->len / 2)
		rra(output, stack_a);
}

//decide for element to push to A
// -1 means error
int	ft_find_optimal_push(t_stack *a, t_stack *b, t_stack *targ, t_dlist **path)
{
	t_moves	moves_best;
	int		best_index;

	*targ = ft_find_targets(a, b);
	if (!(targ->list))
		return (-1);
	/* ft_printf("\nTARGETS\n"); */
	/* ft_printf_int_array(targ->list, targ->len); */
	/* ft_printf("A>>>>>>>>>>>>>before move exec\n"); */
	/* ft_printf_int_array(a->list, a->len); */
	/* ft_printf("B>>>>>>>>>>>>>before move exec\n"); */
	/* ft_printf_int_array(b->list, b->len); */
	best_index = ft_find_optimal_move(targ, a->len, &moves_best);
	ft_exec_moves(a, b, &moves_best, path);
	pa(path, a, b);
	/* ft_printf("A>>>>>>>>>>>>>after move exec\n"); */
	/* ft_printf_int_array(a->list, a->len); */
	/* ft_printf("B>>>>>>>>>>>>>after move exec\n"); */
	/* ft_printf_int_array(b->list, b->len); */
	return (best_index);
}

int	ft_find_optimal_move(t_stack *targ, int len_a, t_moves *moves_best)
{
	t_moves	moves_tmp;
	int		min_moves;
	int		move_count2;
	int		best_index;
	int		i;

	i = 1;
	best_index = 0;
	min_moves = ft_calcmoves(0, targ, len_a, moves_best);
	while (i < targ->len)
	{
		move_count2 = ft_calcmoves(i, targ, len_a, &moves_tmp);
		if (move_count2 < min_moves)
		{
			*moves_best = moves_tmp;
			min_moves = move_count2;
			best_index = i;
		}
		i++;
	}
	return (best_index);
}
