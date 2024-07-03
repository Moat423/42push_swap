/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:39:02 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/07/01 16:57:00 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "newlib.h"

char *const	*ft_split_or_1(unsigned int *listlen, char *argv[]);
int const	*ft_array_atoi(const unsigned int listlen, char *const *charlist);

int	main(int argc, char *argv[])
{
	char *const		*charlist;
	int const		*list_a;
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
	//make a while loop to print out charlist to test it
	unsigned int i = 0;
	while (i < listlen)
	{
		ft_printf("n%d: %s", i, charlist[i]);
		i++;
	}
	if (charlist)
		free_str_array((char **) charlist, listlen);
	charlist = NULL;
	// take above testing code out
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
	while (*charlist != NULL)
	{
		(*listlen)++;
	}
	(*listlen)--;
	return (charlist);
}

// creates a list of ints, does isint checking, calls atoi on each numstring element in list 
int	const	*ft_array_atoi(const unsigned int listlen, char *const *charlist)
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

//questions: is my ft_array atoi giving a constant pointer to ints,
