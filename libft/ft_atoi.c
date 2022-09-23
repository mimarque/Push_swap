/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimarque <mimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 20:41:36 by mimarque          #+#    #+#             */
/*   Updated: 2022/07/07 23:43:41 by mimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long	sum;
	long	s;

	sum = 0;
	s = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			s = -1;
	if (!ft_isdigit(*str))
		return (0);
	while (*str && ft_isdigit(*str))
	{
		if (sum * s > INT_MAX)
			return (-1);
		else if (sum * s < INT_MIN)
			return (0);
		sum = sum * 10 + *str - '0';
		str++;
	}
	return ((int)(sum * s));
}
