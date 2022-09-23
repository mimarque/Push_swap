/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_setup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimarque <mimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 21:28:41 by mimarque          #+#    #+#             */
/*   Updated: 2022/05/16 14:05:25 by mimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Setting up for the several types
*/

//uses memchar so it can lookup up till precision chars
//and corrects if precision is larger than actual lenght
void	s_setup(t_args *a)
{
	char	*p;

	if (a->precision >= 0)
	{
		p = ft_memchr(a->cp, 0, (size_t)a->precision);
		if (p != NULL)
		{
			a->size = p - a->cp;
			if (a->size > a->precision)
				a->size = a->precision;
		}
		else
			a->size = a->precision;
	}
	else
		a->size = ft_strlen(a->cp);
}

void	csp_setup(t_args *a)
{	
	if (*a->type == 'c')
		a->size = 1;
	else if (*a->type == 's')
		s_setup(a);
	else if (*a->type == 'p')
	{
		a->base = 16;
		a->hash = 1;
		a->pref = "0x";
	}
}

void	dioux_setup(t_args *a)
{
	if (*a->type == 'd' || *a->type == 'i')
		a->base = 10;
	else if (*a->type == 'u')
		a->base = 10;
	else if (*a->type == 'o')
	{
		a->base = 8;
		a->pref = "0";
	}
	else if (*a->type == 'x')
	{
		a->base = 16;
		a->pref = "0x";
	}	
	else if (*a->type == 'X')
	{
		a->base = 16;
		a->caps = 16;
		a->pref = "0X";
	}
}
