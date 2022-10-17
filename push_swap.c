/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimarque <mimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:05:17 by mimarque          #+#    #+#             */
/*   Updated: 2022/10/17 12:55:13 by mimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief checks if stack a is ordered
/// @param stack 
/// @return bool
bool	is_sorted(t_list *stack)
{
	int		a;
	int		b;

	while (stack->next != NULL)
	{
		a = ((t_stack *) stack->content)->value;
		b = ((t_stack *) stack->next->content)->value;
		if (a > b)
			return (false);
		stack = stack->next;
	}
	return (true);
}

/// @brief Decides what course to take
/// if 2 elements but not ordered do *sa*
/// if 3 elements but not ordered do mini_sort
/// if more than 3 elem not ordered do sort
/// @param s_a 
/// @param s_b 
void	push_swap(t_list **s_a, t_list **s_b)
{
	int		size;
	bool	o;

	size = ft_lstsize(*s_a);
	o = is_sorted(*s_a);
	if (size == 2 && !o)
		sa(s_a);
	else if (size == 3)
		mini_sort(s_a);
	else if (size > 3 && !o)
		sort(s_a, s_b);
}

int	main(int argc, char *argv[])
{
	t_list	*s_a;
	t_list	*s_b;

	s_a = NULL;
	s_b = NULL;
	if (argc < 2)
		return (0);
	initialize(argc, argv, &s_a);
	push_swap(&s_a, &s_b);
	ft_lstclear(&s_a, del_stk);
}
