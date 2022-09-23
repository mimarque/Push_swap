/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimarque <mimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 18:26:59 by mimarque          #+#    #+#             */
/*   Updated: 2021/11/24 16:28:20 by mimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*size_t	strlcpy(char *destination, const char *source, size_t size)
{
	char *d = destination;
	const char *s = source;
	size_t n = size;
	
	if (n > 0)
		while (--n != 0)
			if ((*d++ = *s++) == '\0')
				break;
	if (n == 0) {
		if (size != 0)
			*d = '\0';
		while (*s++)
			;
	}
	return(s - source - 1);
}*/

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!dstsize)
		return (ft_strlen(src));
	while (src[i] != '\0' && i < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize <= ft_strlen(src))
		dst[dstsize - 1] = '\0';
	else
		dst[i] = '\0';
	return (ft_strlen(src));
}
