/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpenultimate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimarque <mimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 21:57:03 by mimarque          #+#    #+#             */
/*   Updated: 2022/10/10 15:23:03 by mimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
t_list	*ft_lstpenultimate(t_list *lst)
{
	t_list	*current;

	current = lst;
	if (!current || current->next == NULL)
		return (NULL);
	while (current->next->next != NULL)
		current = current->next;
	return (current);
}
*/
t_list	*ft_lstpenultimate(t_list **lst)
{
	t_list	*current;
	t_list	*previous;

	if (!*lst || !(*lst)->next)
		return (NULL);
	current = *lst;
	while (current->next)
	{
		previous = current;
		current = current->next;
	}
	return (previous);
}
