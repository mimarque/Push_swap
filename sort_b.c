/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimarque <mimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:54:06 by mimarque          #+#    #+#             */
/*   Updated: 2022/10/20 14:43:09 by mimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// while (size > 6 && i < size && pushed < size / 2)
/// @brief push all nodes (but 3) in a to b in a minamilly ordered way
/// if stack a size is bigger than 6 then send all the numbers smaller
/// than the median to stack b (see: t_stack struct index) and if they
/// are bigger than the median rotate a.
/// After send all but 3 to b.
/// @param s_a stack a 
/// @param s_b stack b
void	push_to_b(t_list **s_a, t_list **s_b)
{
	int	size;
	int	pushed;
	int	i;

	size = ft_lstsize(*s_a);
	pushed = 0;
	i = 0;
	while (size > 6 && i < size && pushed < size / 2)
	{
		if (((t_stack *)(*s_a)->content)->index <= size / 2)
		{
			pb(s_a, s_b);
			pushed++;
		}
		else
			ra(s_a);
		i++;
	}
	while (size - pushed > 3)
	{
		pb(s_a, s_b);
		pushed++;
	}
}

/// Assigns a target position in stack A to each element of stack A.
/// The target position is the spot the element in B needs to
/// get to in order to be sorted correctly. This position will
/// be used to calculate the cost of moving each element to
/// its target position in stack A.
void	get_target_position(t_list *a, t_list *b)
{
	t_list	*tmp_b;
	int		tpos;
	int		tidx;

	tmp_b = b;
	get_position(a);
	get_position(b);
	tpos = 0;
	tidx = INT_MAX;
	while (tmp_b)
	{
		get_target(a, tmp_b, &tidx, &tpos);
		((t_stack *)tmp_b->content)->target_pos = tpos;
		tmp_b = tmp_b->next;
	}
}

/// Calculates the cost of moving each element of stack B into the correct
/// position in stack A.
/// Two costs are calculated:
/// 	cost_b represents the cost of getting the element to the top of the s_b
/// 	cost_a represents the cost of getting to the right position in stack A.
/// If the element is in the bottom half of the stack, the cost will be negative
/// if it is in the top half, the cost is positive. 
/// cost b = position on the stack except the last values all decrease by 1
/// from the last until the middle value
/// cost a = position on the stack except the last values all decrease by 1
/// from the last until the  middle value
///		s_b->cost_b = s_b->pos;
///		if (s_b->pos > size_b / 2)
///			s_b->cost_b = (size_b - s_b->pos) * -1;
///
///		s_b->cost_a = s_b->target_pos;
/// 	if (s_b->target_pos > size_a / 2)
/// 		s_b->cost_a = (size_a - s_b->target_pos) * -1;
/// @brief Calculates the cost of moving each element from stack b to final pos.
/// @param s_a stack a
/// @param s_b stack b
void	get_cost(t_list *s_a, t_list *s_b)
{
	int		size_a;
	int		size_b;

	size_a = ft_lstsize(s_a);
	size_b = ft_lstsize(s_b);
	while (s_b)
	{
		((t_stack *)s_b->content)->cost_b = ((t_stack *)s_b->content)->pos;
		if (((t_stack *)s_b->content)->pos > size_b / 2)
			((t_stack *)s_b->content)->cost_b
				= (size_b - ((t_stack *)s_b->content)->pos) * -1;
		((t_stack *)s_b->content)->cost_a
			= ((t_stack *)s_b->content)->target_pos;
		if (((t_stack *)s_b->content)->target_pos > size_a / 2)
			((t_stack *)s_b->content)->cost_a
				= (size_a - ((t_stack *)s_b->content)->target_pos) * -1;
		s_b = s_b->next;
	}
}

/// @brief finds the element in stack b with less movements required and
/// moves it to stack a
/// @param s_a stack a 
/// @param s_b stack b
void	do_cheapest_move(t_list **s_a, t_list **s_b)
{
	t_list	*tmp;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	tmp = *s_b;
	cheapest = INT_MAX;
	while (tmp)
	{
		if (ft_abs(((t_stack *)tmp->content)->cost_a)
			+ ft_abs(((t_stack *)tmp->content)->cost_b) < cheapest)
		{
			cheapest = ft_abs(((t_stack *)tmp->content)->cost_b)
				+ ft_abs(((t_stack *)tmp->content)->cost_a);
			cost_a = ((t_stack *)tmp->content)->cost_a;
			cost_b = ((t_stack *)tmp->content)->cost_b;
		}
		tmp = tmp->next;
	}
	do_move(s_a, s_b, cost_a, cost_b);
}

/// After the bulk of the stack is sorted, shifts stack a until the lowest
/// value is at the top. If it is in the bottom half of the stack, reverse
/// rotate it into position, otherwise rotate until it is at the top of the
/// stack.
void	shift_stack(t_list **s_a)
{
	int	lowest_pos;
	int	stack_size;

	stack_size = ft_lstsize(*s_a);
	lowest_pos = get_lowest_index_position(*s_a);
	if (lowest_pos > stack_size / 2)
	{
		while (lowest_pos < stack_size)
		{
			rra(s_a);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			ra(s_a);
			lowest_pos--;
		}
	}
}
