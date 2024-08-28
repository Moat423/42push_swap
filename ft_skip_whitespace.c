/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_whitespace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:39:01 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/08/26 17:39:09 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// returns the amount of spaces that need to be skipped (according to isspace)
int	skip_whitespace(const char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	return (i);
}
