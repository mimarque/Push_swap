/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimarque <mimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:31:28 by mimarque          #+#    #+#             */
/*   Updated: 2022/03/31 23:44:37 by mimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define INT_DIGITS 19

char	*ft_itoa(int n)
{
	static char	buf[INT_DIGITS + 2];
	char		*p;

	p = buf + INT_DIGITS + 1;
	if (n >= 0)
	{
		*--p = '0' + (n % 10);
		n /= 10;
		while (n != 0)
		{
			*--p = '0' + (n % 10);
			n /= 10;
		}
		return (p);
	}
	else
	{
		while (n != 0)
		{
			*--p = '0' - (n % 10);
			n /= 10;
		}
		*--p = '-';
	}
	return (p);
}
