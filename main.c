/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:39:02 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/07/31 12:59:52 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/lib_printf/ft_printf.h"
#include "push_swap.h"
#include "newlib.h"

char *const	*ft_split_or_1(int *listlen, char *argv[]);
int			ft_find_dup(int *list, int listlen);
void		ft_printf_int_array(const int *array, const int len);
void		ft_printf_char_array(char *const *array, const int len);
int			*get_position(const int listlen, int *list_in);
int			*ft_insertion_sort_int_list(const int *list, const int listlen);
int			*ft_array_atoi(const int listlen, char *const *charlist);

void	testing_operations(t_stack *stack_a);
//TODO check if the unsigned int was neccessary somewhere
//try funciton again

// TODO take out printfs, shorten function
int	main(int argc, char *argv[])
{
	char *const		*charlist;
	int *list_a;
	t_stack	stack_a;

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
	if (!list_a || ft_find_dup(list_a, stack_a.len))
		return (write(2, "Error\n", 6));
	if (argc == 2)
	{
		ft_printf("charlist array:\n");
		ft_printf_char_array(charlist, stack_a.len);
		free_str_array((char **) charlist, stack_a.len);
	}
	ft_printf("int list_a:\n");
	ft_printf_int_array(list_a, stack_a.len);
	stack_a.list = get_position((int) stack_a.len, list_a);
	ft_printf("positional array:\n");
	ft_printf_int_array(stack_a.list, stack_a.len);
	//testing_operations(&stack_a);
	free((void *) list_a);
	sorting_frame(&stack_a);
	ft_printf("array after sort:\n");
	ft_printf_int_array(stack_a.list, stack_a.len);
	free(stack_a.list);
	return (1);
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
	// (*listlen)--;
	return (charlist);
}

//creates a const int pointer to ints(a list), atois each *char element in list
int	*ft_array_atoi(const int listlen, char *const *charlist)
{
	int		*stack_a;
	int		i;
	char	*errorptr;

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
	int	i;
	int	j;

	i = 0;
	pos_list = malloc (listlen * sizeof(int));
	if (!pos_list)
		return (NULL);
	sorted_list = ft_insertion_sort_int_list(list_in, listlen);
	if (!sorted_list)
		return (NULL);
	if (sorted_list[0] == -1 && sorted_list[1] == -1)
		return (sorted_list);
	while (i < listlen)
	{
		j = 0;
		while (j < listlen && list_in[i] != sorted_list[j])
			j++;
		pos_list[i] = j;
		i++;
	}
	return (pos_list);
}

// use insertion sort to sort list and return a new malloced list
int	*ft_insertion_sort_int_list(const int *list, const int listlen)
{
	int	i;
	int	j;
	// int	key;
	int	*sorted_list;

	sorted_list = malloc(listlen * sizeof(int));
	if (!sorted_list)
		return (NULL);
	i = 1;
	j = 0;
	while (j < listlen)
	{
		sorted_list[j] = list[j];
		j++;
	}
	ft_sort_int_tab(sorted_list, listlen);
	// while (i < listlen)
	// {
	// 	key = sorted_list[i];
	// 	j = i - 1;
	// 	while (j >= 0 && sorted_list[j] > key)
	// 	{
	// 		sorted_list[j + 1] = sorted_list[j];
	// 		j--;
	// 	}
	// 	sorted_list[j + 1] = key;
	// 	i++;
	// }
	return (sorted_list);
}

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

//while loop to print out charlist to test it
void	ft_printf_char_array(char *const *array, const int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		ft_printf("n%d: %s\n", i, array[i]);
		i++;
	}
}

void	testing_operations(t_stack *stack_a)
{
	ft_printf("before\n");
	ft_printf_int_array(stack_a->list, stack_a->len);
	ft_printf("swap\n");
	swap(stack_a);
	ft_printf_int_array(stack_a->list, stack_a->len);
	ft_printf("rotate\n");
	rotate(stack_a);
	ft_printf_int_array(stack_a->list, stack_a->len);
	ft_printf("reverse_rotate\n");
	reverse_rotate(stack_a);
	ft_printf_int_array(stack_a->list, stack_a->len);
}

int	ft_find_dup(int *list, int listlen)
{
	int	i;
	int	j;

	i = 0;
	while (i < listlen)
	{
		j = i + 1;
		while (j < listlen)
		{
			if (list[i] == list[j])
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}
