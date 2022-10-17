/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimarque <mimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 02:15:00 by mimarque          #+#    #+#             */
/*   Updated: 2022/10/17 02:15:03 by mimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//PUSH OPERATIONS
/// @brief Send item on top of stack to the top of the other
/// @param src sa or sb
/// @param dest sa or sb
void	push(t_list **src, t_list **dest)
{
	t_list	*temp;

	if (*src == NULL)
		return ;
	temp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = temp;
}

void	pa(t_list **s_a, t_list **s_b)
{
	push(s_b, s_a);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_list **s_a, t_list **s_b)
{
	push(s_a, s_b);
	ft_putstr_fd("pb\n", 1);
}
