/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newlib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:11:26 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/08/26 17:45:04 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "newlib.h"
#include "push_swap.h"

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

//creates (with malloc) new string and copies str1 and then str2 inside
char	*ft_newstrjoin(char *str1, char *str2)
{
	int		len1;
	int		len2;
	char	*res;

	if (!str1 || !str2)
		return (NULL);
	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	res = malloc(len1 + len2 + 1);
	if (!res)
		return (NULL);
	ft_strlcpy(res, str1, len1 + 1);
	ft_strlcpy(res + len1, str2, len2 + 1);
	return (res);
}
