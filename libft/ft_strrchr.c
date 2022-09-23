/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimarque <mimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 19:23:33 by mimarque          #+#    #+#             */
/*   Updated: 2021/11/24 20:02:04 by mimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	chr;

	i = ft_strlen(s);
	chr = (char)c;
	if (chr == 0)
		return ((char *)(s + i));
	while (i >= 0)
	{
		if (s[i] == chr)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}
