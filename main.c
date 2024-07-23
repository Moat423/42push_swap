/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:39:02 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/07/23 13:25:57 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "newlib.h"

char *const	*ft_split_or_1(unsigned int *listlen, char *argv[]);
int	*ft_array_atoi(const unsigned int listlen, char *const *charlist);
int	*ft_insertion_sort_int_list(int *list, const unsigned int listlen);

int	main(int argc, char *argv[])
{
	char *const		*charlist;
	int *list_a;
	unsigned int	listlen;

	if (argc == 1)
		return (0);
	listlen = argc - 1;
	if (argc == 2)
	{
		charlist = ft_split_or_1(&listlen, argv);
		list_a = ft_array_atoi(listlen, charlist);
	}
	else
		list_a = ft_array_atoi(listlen, argv);
	// //make a while loop to print out charlist to test it
	// unsigned int i = 0;
	// while (i < listlen)
	// {
	// 	ft_printf("n%d: %s", i, charlist[i]);
	// 	i++;
	// }
	// if (charlist)
	// 	free_str_array((char **) charlist, listlen);
	// charlist = NULL;
	// // take above testing code out
	if (!list_a)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	free((void *) list_a);
	return (1);
}

//modiefies listlen in main, splits numstrings
char *const	*ft_split_or_1(unsigned int *listlen, char *argv[])
{
	char	**charlist;

	charlist = ft_split(argv[1], ' ');
	if (!charlist)
		return NULL;
	while (*charlist != NULL)
	{
		(*listlen)++;
	}
	(*listlen)--;
	return (charlist);
}

//creates a const int pointer to ints(a list), atois each *char element in list
int	*ft_array_atoi(const unsigned int listlen, char *const *charlist)
{
	int				*stack_a;
	unsigned int	i;

	stack_a = malloc(listlen * sizeof(int));
	i = 0;
	while (i++ < listlen)
	{
		stack_a[i] = ft_atoi(charlist[i]);
	}
	return (stack_a);
}

// sorts list_in locally and returns a list where each index is assigned its ultimate
// index it should have if the list was sorted
// returns a !!malloced positional list
int	*get_position(const unsigned int listlen, int *list_in)
{
	unsigned int	*pos_list;
	int				*sorted_list;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	pos_list = malloc (listlen * sizeof(unsigned int));
	if (!pos_list)
		return (NULL);
	//where do i assign memory for sorted list, or is it ok to just take the list from the sort function scope?
	sorted_list = ft_insertion_sort_int_list(list_in, listlen);
	while (i < listlen)
	{
		j = 0;
		while (j < listlen && list_in[i] != sorted_list[j])
			j++;
		pos_list[i] = j;
		i++;
	}
}

//question, do i need to malloc the returned list here? can i just return the local list?
int	*ft_insertion_sort_int_list(int *list, const unsigned int listlen)
{
	int	i;
	int	j;
	int	key;

	i = 1;
	while (i < listlen)
	{
		key = list[i];
		j = i - 1;
		while (j >= 0 && list[j] > key)
		{
			list[j + 1] = list[j];
			j--;
		}
		list[i] = key;
		i++;
	}
	return (list);
}
