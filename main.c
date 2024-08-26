/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:39:02 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/08/26 12:05:52 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "newlib.h"
#include <errno.h>

// TODO take out printfs, shorten function
int	main(int argc, char *argv[])
{
	char *const		*charlist;
	int				*list_a;
	t_stack			stack_a;

	if (argc == 1)
		return (0);
	stack_a.len = argc - 1;
	if (argc == 2)
	{
		charlist = ft_split_or_1(&stack_a.len, argv);
		list_a = ft_array_atoi(stack_a.len, charlist);
	}
	else
		list_a = ft_array_atoi(stack_a.len, &argv[1]);
	if (argc == 2)
		free_str_array((char **) charlist, stack_a.len);
	if (!list_a || ft_find_dup(list_a, stack_a.len))
		return (write(2, "Error\n", 6));
	if (stack_a.len <= 1)
		return (0);
	stack_a.list = get_position(stack_a.len, list_a);
	free(list_a);
	sorting_frame(&stack_a);
	free(stack_a.list);
	return (0);
}

//modiefies listlen in main, splits numstrings
char *const	*ft_split_or_1(int *listlen, char *argv[])
{
	char	**charlist;

	charlist = ft_split(argv[1], ' ');
	if (!charlist)
		return (NULL);
	while (charlist[*listlen] != NULL)
	{
		(*listlen)++;
	}
	return (charlist);
}

//creates a const int pointer to ints(a list), atois each *char element in list
int	*ft_array_atoi(const int listlen, char *const *charlist)
{
	int		*stack_a;
	int		i;
	char	*errorptr;

	errno = 0;
	stack_a = malloc(listlen * sizeof(int));
	if (!stack_a)
		return (NULL);
	i = 0;
	while (i < listlen)
	{
		stack_a[i] = ft_strtoimax(charlist[i], &errorptr, 10);
		i++;
	}
	return (stack_a);
}

// returns !!malloced positional list where each index is assigned its ultimate
// index it should have if the list was sorted
int	*get_position(const int listlen, int *list_in)
{
	int				*pos_list;
	int				*sorted_list;

	pos_list = malloc (listlen * sizeof(int));
	if (!pos_list)
		return (NULL);
	sorted_list = ft_insertion_sort_int_list(list_in, listlen);
	if (!sorted_list || (sorted_list[0] == -1 && sorted_list[1] == -1))
	{
		free(pos_list);
		if (!sorted_list)
			return (NULL);
		return (sorted_list);
	}
	ft_assign_index_pos(listlen, list_in, sorted_list, pos_list);
	free(sorted_list);
	return (pos_list);
}

//assigns indexes to all list items
void	ft_assign_index_pos(const int len, int *list_in, int *slist, int *plist)
{
	int				i;
	int				j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len && list_in[i] != slist[j])
			j++;
		plist[i] = j;
		i++;
	}
}
