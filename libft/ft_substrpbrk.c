/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substrpbrk.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimarque <mimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 23:30:30 by mimarque          #+#    #+#             */
/*   Updated: 2022/03/31 23:45:34 by mimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Does the same as strpbrk but for len ammount of chars
 * 
 * @param s string to go through
 * @param len the limit amount of chars to go through (positive)
 * @param accept list of chars to find in 's'
 * @return char* 
 */
char	*ft_substrpbrk(char *s, size_t len, char *accept)
{
	char	*a;
	char	*l;

	if (len < 0)
		return (NULL);
	l = s + len;
	while (s != l)
	{
		a = accept;
		while (*a != '\0')
			if (*a++ == *s)
				return ((char *) s);
		++s;
	}
	return (NULL);
}
