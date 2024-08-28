/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_dupl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 08:24:41 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/08/28 08:53:31 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_find_dup(int *list, int listlen);

int	main(void)
{
	int	nodup[5] = {1, 2, 3, 4, 5};
	int	dup[5] = {1, 4, 1, 3, 4};
	int	lst[3] = {1, 1, 4};

	printf("nodup returned %d\n", ft_find_dup(nodup, 5));
	printf("dup returned %d\n", ft_find_dup(dup, 5));
	printf("{1, 1, 4} returned %d\n", ft_find_dup(lst, 3));
	return (0);
}
