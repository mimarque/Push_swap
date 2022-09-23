/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimarque <mimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 23:24:21 by mimarque          #+#    #+#             */
/*   Updated: 2022/03/31 23:27:00 by mimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief LibC function to find a character from a list of chars
 * 
 * @param s string to go through
 * @param accept list of chars to find in 's'
 * @return char* 
 */
char	*ft_strpbrk(const char *s, char *accept)
{
	char	*a;

	while (*s != '\0')
	{
		a = accept;
		while (*a != '\0')
			if (*a++ == *s)
				return ((char *) s);
		++s;
	}
	return (NULL);
}
