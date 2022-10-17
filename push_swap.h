/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimarque <mimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:42:50 by mimarque          #+#    #+#             */
/*   Updated: 2022/10/17 13:14:18 by mimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
/// @brief 
/// value: the integer to sort,
/// index: its index in the list of all values that must be sorted,
/// pos: its current position in its stack,
/// target_pos: for elements in stack B, 
///				the target position in stack A where it should be,
/// cost_a: how many actions it would cost to ROTATE stack A
///			so that the element at the current position gets to the top of s_A,
/// cost_b: how many actions it would cost to ROTATE stack B 
///			so that this element gets to the top of stack B,
/// next: pointer to the next element in the list.
///
typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
}	t_stack;

//get.c
void	get_position(t_list *stack);
void	get_target(t_list *a, t_list *b, int *tidx, int *tpos);
void	gtp_vars(t_list *tmp_a, int *tidx, int *tpos);
int		get_highest_index(t_list *stack);
int		get_lowest_index_position(t_list *stack);
//init.c
void	initialize(int argc, char **argv, t_list **s_a);
int		*store_validate_data(int argc, char *argv[]);
int		*sort_values(int argc, int *arr);
void	init_stack(int argc, int *arr, t_list **s_a);
void	index_values(int *arr, int *iarr, int size, t_list **s_a);
//move.c
void	rr_both(t_list **a, t_list **b, int *cost_a, int *cost_b);
void	r_both(t_list **a, t_list **b, int *cost_a, int *cost_b);
void	r_a(t_list **a, int *cost);
void	r_b(t_list **b, int *cost);
void	do_move(t_list **a, t_list **b, int cost_a, int cost_b);
//push_swap.c
bool	is_sorted(t_list *stack);
void	push_swap(t_list **s_a, t_list **s_b);
//push.c
void	push(t_list **src, t_list **dest);
void	pa(t_list **s_a, t_list **s_b);
void	pb(t_list **s_a, t_list **s_b);
//reverse_rotate.c
void	reverse_rotate(t_list **stack);
void	rra(t_list **s_a);
void	rrb(t_list **s_b);
void	rrr(t_list **s_a, t_list **s_b);
//rotate.c
void	rotate(t_list **stack);
void	ra(t_list **s_a);
void	rb(t_list **s_b);
void	rr(t_list **s_a, t_list **s_b);
//sort_b.c
void	push_to_b(t_list **s_a, t_list **s_b);
void	get_target_position(t_list *a, t_list *b);
void	get_cost(t_list *s_a, t_list *s_b);
void	do_cheapest_move(t_list **s_a, t_list **s_b);
void	shift_stack(t_list **s_a);
//sort.c
void	sort(t_list **s_a, t_list **s_b);
void	mini_sort(t_list **s_a);
//swap.c
void	swap(t_list **stack);
void	sa(t_list **s_a);
void	sb(t_list **s_b);
void	ss(t_list **s_a, t_list **s_b);
//utils.c
bool	is_intnumber(char *str);
bool	has_duplicates(int *arr);
void	del_stk(void *a);
int		ft_abs(int n);
bool	is_sa_ordered(int argc, t_list *stack);
#endif