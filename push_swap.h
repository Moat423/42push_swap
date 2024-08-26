/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:49:22 by lmeubrin          #+#    #+#             */
/*   Updated: 2024/08/23 14:41:49 by lmeubrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "libft/lib_ft/libft.h"
# include "libft/get_next_line/get_next_line.h"
# include "libft/lib_printf/ft_printf.h"

# ifndef ABS
#  define ABS(x) (((x) + ((x) >> 31)) ^ ((x) >> 31))
# endif	//ABS

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
} t_moves;

typedef struct s_dlist
{
	char			*content;
	struct s_dlist	*next;
	struct s_dlist	*prev;
} t_dlist;

typedef struct s_costs
{
	int	t_i;
	int	cost;
	char	type;
} t_costs;

//helpers_print.c
void	ft_print_moves(t_moves *moves);
void	testing_operations(t_stack *stack_a);
void	ft_printf_int_array(const int *array, const int len);
void	ft_printf_char_array(char *const *array, const int len);

//dlist_helpers.c
int	ft_exec_moves(t_stack *stack_a, t_stack *stack_b, t_moves *moves, t_dlist **lst);

//helpers
int	min(int a, int b);
int	max(int a, int b);
int	ft_index_of_min(int *list, int len);
int	ft_index_of_max(int *list, int len);
int	ft_max_of_lst(int *list, int len);
int	ft_min_of_lst(int *list, int len);

void	swap(t_stack *stack);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);
void	push_to_2(t_stack *stack_1, t_stack *stack_2);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);


void	sa(t_dlist **node, t_stack *stack);
void	sb(t_dlist **node, t_stack *stack);
void	ra(t_dlist **node, t_stack *stack);
void	rb(t_dlist **node, t_stack *stack);
void	rra(t_dlist **node, t_stack *stack);
void	rrb(t_dlist **node, t_stack *stack);
void	pa(t_dlist **node,  t_stack *stack_a, t_stack *stack_b);
void	pb(t_dlist **node, t_stack *stack_a, t_stack *stack_b);
void	do_ss(t_dlist **node,  t_stack *stack_a, t_stack *stack_b);

char *const	*ft_split_or_1(int *listlen, char *argv[]);
int			ft_find_dup(int *list, int listlen);
void		ft_printf_int_array(const int *array, const int len);
void		ft_printf_char_array(char *const *array, const int len);
int			*get_position(const int listlen, int *list_in);
int			*ft_insertion_sort_int_list(const int *list, const int listlen);
int			*ft_array_atoi(const int listlen, char *const *charlist);

//sorting.c
int	sorting_frame(t_stack *stack_a);
void	ft_midpoint(t_dlist **moves, t_stack *stack_a, t_stack *stack_b);
int	ft_rot_or_revrot(int *stack, int len, int nb);
void	ft_splitpoint(t_dlist **moves, t_stack *stack_a, t_stack *stack_b);
int	ft_pushsort_to_b(t_stack *stack_a, t_stack *stack_b, t_stack *targets, t_dlist **new_path);

//helpers_sorted.c
void	sort_3_a(t_dlist **moves, t_stack *stack);
void	sort_2_a(t_dlist **moves, t_stack *stack);
int	ft_sorted_descending(int *stack, int len);
int	ft_sorted_ascending(int *stack, int len);

//sorting_back.c
int	ft_rot_or_revrot(int *stack, int len, int nb);
int	ft_find_moves(t_stack *stack_a, t_stack *stack_b, int curr_index, int target_index, t_dlist **path);
int	ft_optimal_pos(const int nb, const int prev, const int next, const int	max, const int min);
int ft_find_min_moves(t_stack *stack_a, t_stack *stack_b, t_stack *targets, t_dlist **min_path);
int	ft_rot_or_revrot_of_i(int *stack, int len, int nb);
int	ft_push_if_sorted(t_stack *stack_a, t_stack *stack_b, t_dlist **path);
int	sorting_back(t_stack *stack_a, t_stack *stack_b, t_dlist **output);
int	ft_find_optimal_push(t_stack *stack_a, t_stack *stack_b, t_stack *targets, t_dlist **new_path);
int	ft_calcmoves(int index, t_stack *targets, int len_a, t_moves *moves);
int	ft_calcmoves_tob(int index, t_stack *targets, int len_a, t_moves *moves);
void	ft_handle_stack_operations(t_dlist **moves, t_stack *stack_a, t_stack *stack_b, int splitpoint);

// targets.c
t_stack ft_find_targets(t_stack *stack_a, t_stack *stack_b);
int	ft_get_targets_i(t_stack *stack_a, int value);

//double_linked_list
t_dlist	*ft_dlstnew(char *content);
t_dlist	*ft_dlstfirst(t_dlist *lst);
int	ft_dlstsize(t_dlist *lst);
t_dlist	*ft_dlstlast(t_dlist *lst);
void	ft_dlstadd_back(t_dlist **lst, t_dlist *new_node);
void	ft_printf_dlst(t_dlist **lst);
void	ft_dlstclear(t_dlist **lst);
t_dlist	*ft_createaddback(t_dlist **lst, void *content);

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

//moves.c
void	ft_null_moves(t_moves *moves);
int	ft_countmoves(t_moves *moves);
t_dlist	*ft_rotate_moves_to_list(t_moves *moves, t_dlist *curr_node);
t_dlist *ft_reverse_moves_to_list(t_moves *moves, t_dlist *curr_node);
void	ft_make_rrr(t_moves *moves);
void	ft_make_ss(t_moves *moves);
void	ft_make_rr(t_moves *moves);
void	ft_make_double_op(t_moves *moves);

//moves2.c
void	ft_clean_moves(int rot_case, t_moves *moves);
#endif // PUSH_SWAP_H
