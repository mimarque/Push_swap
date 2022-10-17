/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimarque <mimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 02:16:16 by mimarque          #+#    #+#             */
/*   Updated: 2022/10/17 02:16:41 by mimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//REVERSE ROTATE
/// @brief Bottom number goes on top of the stack
/// @param stack 
void	reverse_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*nd_last;

	if ((*stack) == NULL)
		return ;
	last = ft_lstlast(*stack);
	nd_last = ft_lstpenultimate(stack);
	if (nd_last == NULL)
		return ;
	last->next = (*stack);
	(*stack) = last;
	nd_last->next = NULL;
}

void	rra(t_list **s_a)
{
	reverse_rotate(s_a);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_list **s_b)
{
	reverse_rotate(s_b);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_list **s_a, t_list **s_b)
{
	reverse_rotate(s_a);
	reverse_rotate(s_b);
	ft_putstr_fd("rrr\n", 1);
}
