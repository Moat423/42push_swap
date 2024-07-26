/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:54:42 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/02/08 18:16:43 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	buffer;
	int	j;

	i = 1;
	while (i < size)
	{
		buffer = tab[i];
		j = i - 1;
		while (j >= 0 && tab[j] > buffer)
		{
			tab[j + 1] = tab[j];
			j--;
		}
		tab[j + 1] = buffer;
		i++;
	}
}
