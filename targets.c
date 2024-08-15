// put header here!!!!!!!!!!!!!!!!!!!!!!!!
/*
 *
 */

#include "push_swap.h"

int	sorting_back(t_stack *stack_a, t_stack *stack_b)
{
	t_stack targets;

	if (!targets.list)
		return (0);
	ft_printf("MINIMUM in a: %d\n", ft_min_of_lst(stack_a->list, stack_a->len));
	ft_printf("index of min in a: %d\n", ft_index_of_min(stack_a->list, stack_a->len));
	ft_find_targets(stack_a, stack_b, &targets);
	ft_printf("TARGETS\n");
	ft_printf_int_array(targets.list, targets.len);
	free(targets.list);
	return (1);
}

// create target for every index, return list of targets
// tries to prefer that both use the same turn direction
void	ft_find_targets(t_stack *stack_a, t_stack *stack_b, t_stack *targets) {
	int	i;

	targets->len = stack_b->len;
	targets->list = malloc(stack_b->len * sizeof(int));
	if (!targets->list)
		return ;
	i = 0;
	while (i < stack_b->len / 2)
	{
		targets->list[i] = ft_getbettertarget_i(stack_a, stack_b->list[i], 0);
		i++;
	}
	while (i < stack_b->len)
	{
		targets->list[i] = ft_getbettertarget_i(stack_a, stack_b->list[i], 1);
		i++;
	}
	return ;
}

int	ft_get_target_i(int *stack, int len, int nb, int pref_bot)
{
	int	top;
	int	bottom;

	top = 0;
	while (top < (len / 2) && stack[top] < nb)
		top++;
	bottom = len - 1;
	while (bottom >= 0 && stack[bottom] < nb)
		bottom--;
	if (bottom > top + 1)
		return (bottom);
	else if (bottom <= top)
		return (top);
	else
	{
		if (pref_bot == 1)
			return (bottom);
		else
			return (top);
	}
}

int	ft_getbettertarget_i(t_stack *stack, int nb, int pref_bot)
{
	int	top;
	int	bottom;

	top = ft_index_of_min(stack->list, stack->len);
	if (nb < stack->list[top])
		return (top);
	top = 0;
	while (top < stack->len)
	{
		if (stack->list[top] == nb + 1 && stack->list[(top + stack->len - 1) % stack->len] == nb - 1)
			return ((top) % stack->len);
		top++;
	}
	top = 0;
	while (top < (stack->len / 2) && stack->list[top] < nb)
		top++;
	bottom = stack->len - 1;
	while (bottom >= 0 && stack->list[bottom] < nb)
		bottom--;
	if (stack->len - bottom < top + 1)
		return (bottom);
	else if (stack->len - bottom > top + 1)
		return (top);
	else if (pref_bot == 1)
		return (bottom);
	else
		return (top);
}

int	ft_index_of_min(int *list, int len)
{
	int	i;
	int	min;

	min = ft_min_of_lst(list, len);
	i = 0;
	while (i < len)
	{
		if (list[i] == min)
			return (i);
		i++;
	}
	return (i);
}
/*
// cmp whether index 1 is at optimal position
int	ft_cmp_inbetween(t_stack *stack_a, t_stack *stack_b, t_stack *targets, int index1, int index2)
{
	int	prev;
	int	next;
	int	min_of_list;
	int	max_of_list;


	i = 1;
	min_moves = ft_find_moves(stack_a, stack_b, targets->list[0], min_path);
	best_index = 0;
	while (i < targets->len)
	{
		move_count2 = ft_find_moves(stack_a, stack_b, targets->list[i], &path2);
		if (move_count2 < min_moves)
		{
			min_path = &path2;
			min_moves = move_count2;
			best_index = i;
		}
		// put this stupid else into a different function, its too long!
		else if (move_count2 == min_moves)
		{
			min_of_list = ft_min_of_lst(stack_a->list, stack_a->len);
			max_of_list = ft_max_of_lst(stack_a->list, stack_a->len);
			next = stack_a->list[targets->list[i]];
			prev = stack_a->list[(targets->list[i] - 1 + stack_a->len) % stack_a->len];
			if (ft_optimal_pos(stack_b->list[i], prev, next, max_of_list, min_of_list) >\
				ft_optimal_pos(stack_b->list[best_index], \
				   stack_a->list[targets->list[best_index]], \
				   stack_a->list[(targets->list[best_index] - 1 + stack_a->len)\
				   % stack_a->len], max_of_list, min_of_list))
}
*/
