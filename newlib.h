/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newlib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:39:21 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/07/01 16:52:19 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NEWLIB_H
# define NEWLIB_H
# include <unistd.h>

void	free_str_array(char **str_array, size_t elemnbr);
void	ft_sort_int_tab(int *tab, int size);
#endif // !NEWLIB_H
