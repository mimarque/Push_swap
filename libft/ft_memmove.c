/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimarque <mimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 19:20:57 by mimarque          #+#    #+#             */
/*   Updated: 2021/11/09 15:56:12 by mimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* check if dest adress is left or right of src,
	then either copy from the beguining or the end */
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*cs1;
	const unsigned char	*cs2;

	if (dst < src)
		return (ft_memcpy(dst, src, len));
	if (!len || (dst == src))
		return (dst);
	cs1 = (unsigned char *)dst;
	cs2 = (const unsigned char *)src;
	while (len--)
		cs1[len] = cs2[len];
	return (dst);
}

/*void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	const char	*lasts;
	char		*lastd;

	d = dest;
	s = src;
	if (d < s)
		while (n--)
			*d++ = *s++;
	else
	{
		lasts = s + (n - 1);
		lastd = d + (n - 1);
		while (n--)
			*lastd-- = *lasts--;
	}
	return (dest);
}*/