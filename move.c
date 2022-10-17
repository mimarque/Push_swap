/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimarque <mimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 02:27:20 by mimarque          #+#    #+#             */
/*   Updated: 2022/10/17 02:27:55 by mimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// Reverse rotates both stack A and B until one of them is in position.
/// The given cost is negative since both positions are in the bottom half
/// of their respective stacks. The cost is increased as the stacks are
/// rotated, when one reaches 0, the stack has been rotated as far as possible
/// and the top position is correct.
void	rr_both(t_list **a, t_list **b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		rrr(a, b);
	}
}


/// Rotates both stack A and B until one of them is in position.
/// The given cost is positive since both positions are in the top half
/// of their respective stacks. The cost is decreased as the stacks are
/// rotated, when one reaches 0, the stack has been rotated as far as possible
/// and the top position is correct.
void	r_both(t_list **a, t_list **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		rr(a, b);
	}
}

/// Rotates stack A until it is in position. If the cost is negative,
/// the stack will be reverse rotated, if it is positive, it will be 
/// rotated.
void	r_a(t_list **a, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			ra(a);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rra(a);
			(*cost)++;
		}
	}
}

/// Rotates stack B until it is in position. If the cost is negative,
/// the stack will be reverse rotated, if it is positive, it will be 
/// rotated.
void	r_b(t_list **b, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			rb(b);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rrb(b);
			(*cost)++;
		}
	}
}

/// Chooses which move to make to get the B stack element to the correct
/// position in stack A.
/// If the costs of moving stack A and B into position match (i.e. both negative
/// of both positive), both will be	rotated or reverse rotated at the same time.
/// They might also be rotated separately, before finally pushing the top B elem
/// to the top stack A.
void	do_move(t_list **a, t_list **b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		rr_both(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		r_both(a, b, &cost_a, &cost_b);
	r_a(a, &cost_a);
	r_b(b, &cost_b);
	pa(a, b);
}