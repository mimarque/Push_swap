/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimarque <mimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 19:21:18 by mimarque          #+#    #+#             */
/*   Updated: 2022/03/23 18:50:33 by mimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief The memchr() function locates the first occurrence
	of c (converted to an unsigned char) in string s.
	returns a pointer to the byte located,
	or NULL if no such byte exists within n bytes.
 * 
 * @param s string to look through
 * @param c char to look for
 * @param n max lenght to search
 * @return void* 
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*src;
	size_t			i;

	i = 0;
	src = (unsigned char *)s;
	while (i < n)
	{
		if (src[i] == (unsigned char)c)
			return ((void *)(src + i));
		i++;
	}
	return (NULL);
}
