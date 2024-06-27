/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:39:02 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/06/27 16:16:32 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
	char * const * charlist;
	char * const * listA;

	if	(argc = 1)
		return (0);
	else if (argc = 2)
	{
		charlist = ft_split_or_1(argv[]);
		listA = ft_array_atoi(charlist);
	}
	else
		listA = ft_array_atoi(argv[]);
	if (!listA)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}
