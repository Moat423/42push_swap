/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:49:22 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/08/27 18:43:09 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include "libft/lib_ft/libft.h"
# include "libft/get_next_line/get_next_line.h"
# include "libft/lib_printf/ft_printf.h"
# include "newlib.h"

typedef struct s_trie
{
	int				moves;
	struct s_trie	*prev;
	struct s_trie	*child;
	struct s_trie	*next;
	char			op[3];
}	t_trie;

typedef struct s_stack
{
	int	len;
	int	*list;
}	t_stack;

typedef struct s_moves
{
	int	sa;
	int	sb;
	int	ss;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	pa;
	int	pb;
}	t_moves;

typedef struct s_dlist
{
	char			*content;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}	t_dlist;

typedef struct s_costs
{
	int		t_i;
	int		cost;
	char	type;
}	t_costs;

//main.c
int		ft_errorcheck_array(int *list_a, int len);
int		*ft_array_atoi(const int listlen, char *const *charlist);
char	**ft_split_or_1(int *listlen, char *argv[]);

//helpers_print.c
void	ft_print_moves(t_moves *moves);
void	testing_operations(t_stack *stack_a);
void	ft_printf_int_array(const int *array, const int len);
void	ft_printf_char_array(char *const *array, const int len);

//dlist_helpers.c
int		ft_exec_moves(t_stack *a, t_stack *b, t_moves *moves, t_dlist **lst);

//helpers
int		ft_index_of_nb(int nb, int *list, int len);
int		ft_index_of_max(int *list, int len);
int		ft_index_of_min(int *list, int len);
int		ft_min_of_lst(int *list, int len);
int		ft_max_of_lst(int *list, int len);

//helpers_sorted.c
int		ft_sorted_ascending(int *stack, int len);
int		ft_sorted_descending(int *stack, int len);
void	sort_2_a(t_dlist **moves, t_stack *stack);
void	sort_3_a(t_dlist **moves, t_stack *stack);

//helpers_true_sorted.c
int		ft_sorted_true_descending(int *stack, int len);
int		ft_sorted_true_ascending(int *stack, int len);

//helpers2.c
int		min(int a, int b);
int		max(int a, int b);
int		ft_find_dup(int *list, int listlen);

//sorting.c
int		sorting_frame(t_stack *stack_a);
void	ft_midpoint(t_dlist **moves, t_stack *stack_a, t_stack *stack_b);
void	ft_handle_operations(t_dlist **moves, t_stack *a, t_stack *b, int splt);
void	ft_splitpoint(t_dlist **moves, t_stack *stack_a, t_stack *stack_b);
int		ft_rot_or_revrot(int *stack, int len, int nb);

//sorting_back.c
int		sorting_back(t_stack *stack_a, t_stack *stack_b, t_dlist **output);
void	ft_rotate_nb_to_top(int nb, t_stack *stack_a, t_dlist **output);
int		ft_find_optimal_push(t_stack *a, t_stack *b, t_stack *t, t_dlist **p);
int		ft_find_optimal_move(t_stack *targ, int len_a, t_moves *moves_best);

// targets.c
int		ft_get_targets_i(t_stack *stack_a, int value);
t_stack	ft_find_targets(t_stack *stack_a, t_stack *stack_b);
int		ft_rot_or_revrot_of_i(int *stack, int len, int nb);
int		ft_calcmoves(int index, t_stack *targets, int len_a, t_moves *moves);
int		ft_push_if_sorted(t_stack *stack_a, t_stack *stack_b, t_dlist **path);

//double_linked_list.c
t_dlist	*ft_dlstnew(char *content);
t_dlist	*ft_dlstfirst(t_dlist *lst);
int		ft_dlstsize(t_dlist *lst);
t_dlist	*ft_dlstlast(t_dlist *lst);
void	ft_dlstadd_back(t_dlist **lst, t_dlist *new_node);

//double_linked_list2.c
void	ft_printf_dlst(t_dlist **lst);
void	ft_dlstclear(t_dlist **lst);
t_dlist	*ft_createaddback(t_dlist **lst, void *content);

//moves.c
void	ft_null_moves(t_moves *moves);
int		ft_countmoves(t_moves *moves);
t_dlist	*ft_rotate_moves_to_list(t_moves *moves, t_dlist *curr_node);
t_dlist	*ft_reverse_moves_to_list(t_moves *moves, t_dlist *curr_node);
void	ft_make_rrr(t_moves *moves);

//moves2.c
void	ft_clean_moves(int rot_case, t_moves *moves);

//moves_double.c
void	ft_make_rrr(t_moves *moves);
void	ft_make_ss(t_moves *moves);
void	ft_make_rr(t_moves *moves);
void	ft_make_double_op(t_moves *moves);

//operations.c
void	swap(t_stack *stack);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);
void	push_to_2(t_stack *stack_1, t_stack *stack_2);

//operations2.c
void	ss(t_stack *stack_a, t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);

//op_push.c
void	sa(t_dlist **node, t_stack *stack);
void	sb(t_dlist **node, t_stack *stack);
void	ra(t_dlist **node, t_stack *stack);
void	rb(t_dlist **node, t_stack *stack);
void	rra(t_dlist **node, t_stack *stack);

//op_push2.c
void	rrb(t_dlist **node, t_stack *stack);
void	pa(t_dlist **node, t_stack *stack_a, t_stack *stack_b);
void	pb(t_dlist **node, t_stack *stack_a, t_stack *stack_b);
void	do_ss(t_dlist **node, t_stack *stack_a, t_stack *stack_b);

//positional_list.c
int		*get_position(const int listlen, int *list_in);
void	ft_assign_index_pos(const int len, int *lst_in, int *slist, int *plist);
#endif // PUSH_SWAP_H
