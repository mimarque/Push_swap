/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimarque <mimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 00:50:53 by mimarque          #+#    #+#             */
/*   Updated: 2021/10/29 01:00:57 by mimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	int				isdiff;
	unsigned char	*src1;
	unsigned char	*src2;

	i = -1;
	isdiff = 0;
	src1 = (unsigned char *)s1;
	src2 = (unsigned char *)s2;
	while (!isdiff && ++i < n)
		isdiff = src1[i] - src2[i];
	return (isdiff);
}
