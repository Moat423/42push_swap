/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:49:22 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/08/02 14:34:46 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "libft/lib_ft/libft.h"
# include "libft/get_next_line/get_next_line.h"
# include "libft/lib_printf/ft_printf.h"

typedef struct s_trie
{
	int				moves;
	struct s_trie	*prev;
	struct s_trie	*child;
	struct s_trie	*next;
	char			op[3];
} t_trie;

typedef struct s_stack
{
	int	len;
	int	*list;
} t_stack;

# ifndef SA
#  define SA swap(stack_a, listlen_a)
# endif //SA

# ifndef RA
#  define RA rotate(stack_a, listlen_a)
# endif //RA

# ifndef RRA
#  define RRA reverse_rotate(stack_a, listlen_a)
# endif //RRA

# ifndef SB
#  define SB swap(stack_b)
# endif //SB

# ifndef RB
#  define RB rotate(stack_b, listlen_b)
# endif //RB

# ifndef RRB
#  define RRB reverse_rotate(stack_b, listlen_b)
# endif //RRB

# ifndef PA
#  define PA push_to_b(stack_a, stack_b, listlen_a, listlen_b)
# endif //PA

# ifndef PB
#  define PB push_to_b(stack_b, stack_a, listlen_b, listlen_a)
# endif //PB

void	swap(t_stack *stack);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);
void	push_to_2(t_stack *stack_1, t_stack *stack_2);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);

char *const	*ft_split_or_1(int *listlen, char *argv[]);
int			ft_find_dup(int *list, int listlen);
void		ft_printf_int_array(const int *array, const int len);
void		ft_printf_char_array(char *const *array, const int len);
int			*get_position(const int listlen, int *list_in);
int			*ft_insertion_sort_int_list(const int *list, const int listlen);
int			*ft_array_atoi(const int listlen, char *const *charlist);
int	sorting_frame(t_stack *stack_a);
void	sort_3_a(t_trie **begin, t_stack *stack);

void	trie_insertnext(t_trie *cur, t_trie *new_node);
void	trie_addnext(t_trie **trie, t_trie *new_node);
void	trie_insertchild(t_trie *cur, t_trie *new_node);
void	trie_addchild(t_trie **trie, t_trie *new_node);
t_trie	*trie_new(char *op);

t_trie	*getlastchild(t_trie *trie);
t_trie	*getnextfromback(t_trie *trie);
t_trie	*delpath(t_trie *last);
t_trie *getnextend(t_trie *trie);
void	printops_path(t_trie *cur);
#endif // PUSH_SWAP_H
