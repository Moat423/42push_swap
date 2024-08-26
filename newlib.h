/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newlib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:39:21 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/08/26 17:40:09 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NEWLIB_H
# define NEWLIB_H
# include <unistd.h>

void	free_str_array(char **str_array, size_t elemnbr);
void	ft_sort_int_tab(int *tab, int size);
int		ft_strtoimax(const char *nptr, char **endptr, int base);
int		skip_whitespace(const char *str);
int		ft_atoi_base_e(const char *nptr, char ***endptr, int base, int sign);
int		determine_sign(const char *nptr);
char	*ft_newstrjoin(char *str1, char *str2);
int		skip_whitespace(const char *str);
#endif // !NEWLIB_H
