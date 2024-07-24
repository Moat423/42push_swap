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
void		ft_printf_int_array(const int *array, const unsigned int len);
void		ft_printf_char_array(char *const *array, const unsigned int len);
int			*get_position(const unsigned int listlen, int *list_in);
int			*ft_insertion_sort_int_list(const int *list, const int listlen);
int			*ft_array_atoi(const unsigned int listlen, char *const *charlist);

int	main(int argc, char *argv[])
{
	char *const		*charlist;
	int *list_a;
	unsigned int	listlen;
	int	*stack_a;
	//int	*stack_b;

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
	if (!list_a)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	ft_printf("charlist array:\n");
	ft_printf_char_array(charlist, listlen);
	if (charlist)
		free_str_array((char **) charlist, listlen);
	stack_a = get_position((int) listlen, list_a);
	ft_printf("positional array:\n");
	ft_printf_int_array(stack_a, listlen);
	free((void *) list_a);
	free(stack_a);
	//free(stack_b);
	return (1);
}

//modiefies listlen in main, splits numstrings
char *const	*ft_split_or_1(unsigned int *listlen, char *argv[])
{
	char	**charlist;

	charlist = ft_split(argv[1], ' ');
	if (!charlist)
		return (NULL);
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
//TODO replace atoi with strtoi for error checking, write strtoi
	}
	return (stack_a);
}

// returns !!malloced positional list where each index is assigned its ultimate
// index it should have if the list was sorted
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
	sorted_list = ft_insertion_sort_int_list(list_in, listlen);
	while (i < listlen)
	{
		j = 0;
		while (j < listlen && list_in[i] != sorted_list[j])
			j++;
		pos_list[i] = j;
		i++;
	}
	return (sorted_list);
}

// use insertion sort to sort list and return a new malloced list
int	*ft_insertion_sort_int_list(const int *list, const int listlen)
{
	int	i;
	int	j;
	int	key;
	int	*sorted_list;

	sorted_list = malloc(listlen * sizeof(int));
	if (!sorted_list)
		return (NULL);
	j = 0;
	while (j++ < listlen)
		sorted_list[j] = list[j];
	i = 1;
	while (i < listlen)
	{
		key = sorted_list[i];
		j = i - 1;
		while (j >= 0 && sorted_list[j] > key)
		{
			sorted_list[j + 1] = sorted_list[j];
			j--;
		}
		sorted_list[i] = key;
		i++;
	}
	return (sorted_list);
}

void	ft_printf_int_array(const int *array, const unsigned int len)
{
	unsigned int	i;

	i = 0;
	while (i++ < len)
		ft_printf("n%d: %i", i, array[i]);
}

//while loop to print out charlist to test it
void	ft_printf_char_array(char *const *array, const unsigned int len)
{
	unsigned int	i;

	i = 0;
	while (i++ < len)
		ft_printf("n%d: %s", i, array[i]);
}
