/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimarque <mimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 18:27:38 by mimarque          #+#    #+#             */
/*   Updated: 2021/11/08 14:01:17 by mimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*old;

	if (lst && del)
	{
		while (*lst)
		{
			del((*lst)->content);
			old = *lst;
			*lst = (*lst)->next;
			free(old);
		}
		*lst = NULL;
	}
}
