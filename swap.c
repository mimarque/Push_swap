/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimarque <mimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 21:11:04 by mimarque          #+#    #+#             */
/*   Updated: 2022/10/16 21:11:07 by mimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//SWAP OPERATIONS
/// @brief Swaps top two items in stack
/// swaps the values and indexes 
/// without swapping the nodes
/// see: t_stack typedef
/// int	temp;
/// 
/// if (stack == NULL || stack->next == NULL)
/// 	return ;
/// temp = ((t_stack *)stack->content)->value;
/// ((t_stack *)stack->content)->value = ((t_stack *)
/// 		stack->next->content)->value;
/// ((t_stack *)stack->next->content)->value = temp;
/// temp = ((t_stack *)stack->content)->index;
/// ((t_stack *)stack->content)->index = ((t_stack *)
/// 		stack->next->content)->index;
/// ((t_stack *)stack->next->content)->index = temp;
/// @param stack sa or sb
void	swap(t_list **stack)
{
	t_list	*temp;

	if ((*stack) == NULL || (*stack)->next == NULL)
		return ;
	temp = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	temp->next = (*stack);
	(*stack) = temp;
}

void	sa(t_list **s_a)
{
	swap(s_a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_list **s_b)
{
	swap(s_b);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_list **s_a, t_list **s_b)
{
	swap(s_a);
	swap(s_b);
	ft_putstr_fd("ss\n", 1);
}
