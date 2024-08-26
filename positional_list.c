/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positional_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:09:22 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/08/26 15:09:32 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
