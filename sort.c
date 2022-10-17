/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimarque <mimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:32:30 by mimarque          #+#    #+#             */
/*   Updated: 2022/10/17 12:54:52 by mimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief Sorts 3 and only 3 nodes
///    Case		    actions
/// a) 1 2 3		=> no action
/// b) 1 3 2		-> rra -> 2 1 3 -> sa  -> 1 2 3 => 2 actions
/// c) 2 1 3		-> sa  -> 1 2 3 => 1 action
/// d) 2 3 1		-> rra -> 1 2 3 => 1 action
/// e) 3 1 2		-> ra  -> 1 2 3 => 1 action
/// f) 3 2 1		-> ra  -> 2 1 3 -> sa  -> 1 2 3 => 2 actions
/// Note that we don't need a cycle to go trough all combinations
/// also note that (2 1 3) can happen 3 out of 6 times (final check)
/// [b) d) e) f)] we either use ra or rra
/// 2nd *if* checks if 1st node is the biggest [e) f)]
/// *if* not check if 2nd node is the biggest [b) d)]
/// Then check if the 2 first nodes are swapped [2 1 3]
/// @param s_a stack a 
void	mini_sort(t_list **s_a)
{
	int	hi;

	if (is_sorted(*s_a))
		return ;
	hi = get_highest_index(*s_a);
	if (((t_stack *)(*s_a)->content)->index == hi)
		ra(s_a);
	else if (((t_stack *)(*s_a)->next->content)->index == hi)
		rra(s_a);
	if (((t_stack *)(*s_a)->content)->index >
		((t_stack *)(*s_a)->next->content)->index)
		sa(s_a);
}

/// @brief The Magic happens here
/// pushes all but 3 values to s_b then orders those 3 values
/// then while there are elements in b find where they need to be
/// then determine how costly is to move them then do cheapest move
/// after everything is in a check if it is ordered if not shift elements
/// @param s_a 
/// @param s_b 
void	sort(t_list **s_a, t_list **s_b)
{
	push_to_b(s_a, s_b);
	mini_sort(s_a);
	while (*s_b)
	{
		get_target_position(*s_a, *s_b);
		get_cost(*s_a, *s_b);
		do_cheapest_move(s_a, s_b);
	}
	if (!is_sorted(*s_a))
		shift_stack(s_a);
}