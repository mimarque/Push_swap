/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimarque <mimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 21:15:51 by mimarque          #+#    #+#             */
/*   Updated: 2022/05/16 14:05:18 by mimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief The true return - magic happens here
 * 
 * @param s string or char to print 
 * @param fd file descriptor (1 default)
 * @param len ammount of chars to print
 */
void	ft_print(char *s, int len)
{
	if (!s)
		return ;
	write(1, s, len);
}

/**
 * @brief prints n "with" characters
 * 
 * @param n number of characters to pad
 * @param with chars to pad with
 */
void	pad(int n, char with)
{
	if (n > 0)
	{
		while (n > 0)
		{
			ft_print(&with, 1);
			n--;
		}
	}
}
