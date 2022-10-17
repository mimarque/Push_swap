/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimarque <mimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 21:12:05 by mimarque          #+#    #+#             */
/*   Updated: 2022/10/16 21:12:32 by mimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//ROTATE
/// @brief Top number goes to bottom of stack
/// @param stack sa or sb
void	rotate(t_list **stack)
{
	t_list	*temp;
	t_list	*last;

	if ((*stack) == NULL)
		return ;
	temp = (*stack)->next;
	last = ft_lstlast(*stack);
	last->next = *stack;
	(*stack)->next = NULL;
	*stack = temp;
}

void	ra(t_list **s_a)
{
	rotate(s_a);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_list **s_b)
{
	rotate(s_b);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_list **s_a, t_list **s_b)
{
	rotate(s_a);
	rotate(s_b);
	ft_putstr_fd("rr\n", 1);
}