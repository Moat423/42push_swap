/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:39:02 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/08/27 16:57:12 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "newlib.h"

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
		free_str_array((char **) charlist, stack_a.len);
	}
	else
		list_a = ft_array_atoi(stack_a.len, &argv[1]);
	if (ft_errorcheck_array(list_a, stack_a.len) > 0)
	{
		free(list_a);
		return (1);
	}
	stack_a.list = get_position(stack_a.len, list_a);
	free(list_a);
	sorting_frame(&stack_a);
	free(stack_a.list);
	return (0);
}

int	ft_errorcheck_array(int *list_a, int len)
{
	if (!list_a || ft_find_dup(list_a, len))
		return (write(2, "Error\n", 6));
	if (len <= 1)
		return (1);
	else
		return (0);
}

//modiefies listlen in main, splits numstrings
char	**ft_split_or_1(int *listlen, char *argv[])
{
	char	**charlist;
	int		len;

	charlist = ft_split(argv[1], ' ');
	if (!charlist)
		return (NULL);
	len = 0;
	while (charlist[len] != NULL)
		len++;
	if (len)
		*listlen = len;
	else
	{
		*listlen = 0;
		free(charlist);
		exit(0);
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
