/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newlib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:11:26 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/07/01 16:47:23 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "newlib.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

//free an array of string (future: elemnbr isn't neccessary because NULL-term)
void	free_str_array(char **str_array, size_t elemnbr)
{
	size_t	i;

	if (str_array == NULL)
		return ;
	i = 0;
	while (i < elemnbr)
	{
		if (str_array[i])
			free(str_array[i]);
		i++;
	}
	free(str_array);
	return ;
}
/*
// test for free_str_array
int	main(void)
{
	char	**charray;
	size_t	size;
	size_t	i;

	size = 5;
	charray = (char **) malloc((size + 1) * sizeof(char *));
	if (charray == NULL)
	{
		printf("Memory allocation of charray failed");
		return (1);
	}
	i = 0;
	while (i < size)
	{
		charray[i] = ft_strdup("Hello");
		i++;
	}
	charray[size] = NULL;
	i = 0;
	printf("original strings:\n");
	while (i < size)
	{
		printf("i: %lu in array: %s\n", i, charray[i]);
		i++;
	}
	free_str_array(charray, size);
	charray = NULL;
	return (0);
}
*/
