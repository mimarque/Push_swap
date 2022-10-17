/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimarque <mimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:38:24 by mimarque          #+#    #+#             */
/*   Updated: 2022/10/17 12:44:48 by mimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief assigns a position to every element from top to
/// bottom in ascending order. See: t_stack position
/// used to calculate the cost of moving an item to a certain position
/// @param stack 
void	get_position(t_list *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		((t_stack *)stack->content)->pos = i;
		stack = stack->next;
		i++;
	}
}

/// Picks the best target position in stack A for the given index of
/// an element in stack B. First checks if the index of the B element can
/// be placed somewhere in between elements in stack A, by checking whether
/// there is an element in stack A with a bigger index. If not, it finds the
/// element with the smallest index in A and assigns that as the target position.
/// --- Example:
/// 	target_pos starts at INT_MAX
/// 	B index: 3
/// 	A contains indexes: 9 4 2 1 0
/// 	9 > 3 && 9 < INT_MAX 	: target_pos updated to 9
/// 	4 > 3 && 4 < 9 			: target pos updated to 4
/// 	2 < 3 && 2 < 4			: no update!
/// So target_pos needs to be the position of index 4, since it is
/// the closest index.
/// --- Example:
/// 	target_pos starts at INT_MAX
/// 	B index: 20
/// 	A contains indexes: 16 4 3
/// 	16 < 20					: no update! target_pos = INT_MAX
/// 	4  < 20					: no update! target_pos = INT_MAX
/// 	3  < 20					: no update! target_pos = INT_MAX
/// ... target_pos stays at INT MAX, need to switch strategies.
/// 	16 < 20					: target_pos updated to 20
/// 	4  < 20					: target_pos updated to 4
/// 	3  < 20					: target_pos updated to 3
/// So target_pos needs to be the position of index 3, since that is
/// the "end" of the stack.
/// for each node in b (in caller function)
/// go through each node in a 
/// if index of node in a is greater than index of node in b 
/// and if that index is smaller than previous max idex
/// update target index and targuet position (gpt_vars())
/// edge-case:
/// if list is stupidly large and tindex is not between two values
/// tidx is INT_MAX still put it next to the smallest value
void	get_target(t_list *a, t_list *b, int *tidx, int *tpos)
{
	t_list	*tmp_a;

	tmp_a = a;
	while (tmp_a)
	{
		if (((t_stack *)tmp_a->content)->index > ((t_stack *)b->content)->index
			&& ((t_stack *)tmp_a->content)->index < *tidx)
			gtp_vars(tmp_a, tidx, tpos);
		tmp_a = tmp_a->next;
	}
	if (*tidx != INT_MAX)
		return ;
	tmp_a = a;
	while (tmp_a)
	{
		if (((t_stack *)tmp_a->content)->index < *tidx)
			gtp_vars(tmp_a, tidx, tpos);
		tmp_a = tmp_a->next;
	}
	return ;
}

/// not enough lines left in get_target
/// just assigns vars
void	gtp_vars(t_list *tmp_a, int *tidx, int *tpos)
{
	(*tidx) = ((t_stack *)tmp_a->content)->index;
	(*tpos) = ((t_stack *)tmp_a->content)->pos;
}

/// @brief Returns highest index on the stack
/// but not highest value (see: t_stack struct)
/// @param stack 
/// @return 
int	get_highest_index(t_list *stack)
{
	int	value;

	value = ((t_stack *)stack->content)->index;
	while (stack)
	{
		if (((t_stack *)stack->content)->index > value)
			value = ((t_stack *)stack->content)->index;
		stack = stack->next;
	}
	return (value);
}

/// @brief gets the position of the element with the lowest index
/// on the stack provided.
/// @param stack stack where to find the lowest index
/// @return 
int	get_lowest_index_position(t_list *stack)
{
	int		l_index;
	int		l_pos;

	get_position(stack);
	l_index = INT_MAX;
	l_pos = ((t_stack *)stack->content)->pos;
	while (stack)
	{
		if (((t_stack *)stack->content)->index < l_index)
		{
			l_index = ((t_stack *)stack->content)->index;
			l_pos = ((t_stack *)stack->content)->pos;
		}
		stack = stack->next;
	}
	return (l_pos);
}
