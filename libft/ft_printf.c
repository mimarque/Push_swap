/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimarque <mimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 20:33:40 by mimarque          #+#    #+#             */
/*   Updated: 2022/05/16 14:05:32 by mimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Converts a value from base 10
 * 		to any other base up till 16
 * 		also turns int into char *
 * 
 * @param cp pointer to the buffer
 * @param value value to convert
 * @param base base to convert it to
 * @param a the struct used in this program
 * @return char* 
 */
char	*print_base(char *cp, U_LONG value,
					unsigned int base, t_args *a)
{
	char	*buffer;
	char	*xdigs;

	buffer = cp;
	xdigs = "0123456789abcdef0123456789ABCDEF";
	*--buffer = xdigs[value % base + a->caps];
	value /= base;
	while (value != 0)
	{
		*--buffer = xdigs[value % base + a->caps];
		value /= base;
	}
	if ((a->hash != 0) && (base == 8))
	{
		*--buffer = '0';
		a->hash = 0;
	}
	return (buffer);
}

void	adjustments(t_args *a)
{
	if (ft_substrpbrk(a->type, 1, MY_DIU))
		if (a->dot && a->zero)
			a->zero = 0;
	if (ft_substrpbrk(a->type, 1, NO_SIGN_TYPE))
		a->sign = '\0';
	if (ft_substrpbrk(a->type, 1, MY_DIU))
	{
		if ((*a->type == 'd' || *a->type == 'i')
			&& (((long)a->ulval) < 0))
		{
			a->ulval = -a->ulval;
			a->sign = '-';
		}
	}
}

/**
 * @brief function to properly print acording to printf
 * 			right-adjusting blank padding,
 * 			prefix,
 * 			right-adjusting zero padding,
 * 			leading zeroes from decimal precision,
 * 			the string or number proper,
 * 			finally, adjust return value, 
 * 
 * @param a the struct used in this program
 * @return int 
 */
int	print_formating(t_args *a)
{
	if (a->dprec > a->size)
		a->realsz = a->dprec;
	else
		a->realsz = a->size;
	if (a->sign)
		a->realsz++;
	else if (a->hash && (a->ulval != 0 || *a->type == 'p'))
		a->realsz += 2;
	if (a->width > a->realsz)
		a->prsize = a->width;
	else
		a->prsize = a->realsz;
	if ((a->zero == 0) && (a->dash == 0))
		pad(a->width - a->realsz, ' ');
	if (a->sign)
		ft_print(&a->sign, 1);
	else if (a->hash && (a->ulval != 0 || *a->type == 'p'))
		ft_print(a->pref, 2);
	if (a->dash == 0 && a->zero == 1)
		pad(a->width - a->realsz, '0');
	pad(a->dprec - a->size, '0');
	ft_print(a->cp, a->size);
	if (a->dash)
		pad(a->width - a->realsz, ' ');
	return (a->prsize);
}

/**
 * @brief Collection of functions that didn't fit in ft_printf
 * 		returns number of printed chars.
 * 		if * is passed as a negative argument then
 *		- flag gets flipped and width is made positive
 *		"... diouXx conversions ... if a precision is specified,
 *		the 0 flag will be ignored."
 * 
 * @param fmt format string
 * @param a the struct used in this program
 * @param args vareadic list
 * @param buf buffer
 * @return int
 */
int	function_colection(char **fmt, t_args *a, va_list *args, char *buf)
{
	int	counter;

	counter = 0;
	a->type = ft_strpbrk(*fmt, MY_TYPES);
	get_flags(fmt, a, args);
	get_type_values(a, args);
	adjustments(a);
	if (ft_substrpbrk(a->type, 1, "csp"))
		csp_setup(a);
	else if (ft_substrpbrk(a->type, 1, MY_DIU))
		dioux_setup(a);
	if (ft_substrpbrk(a->type, 1, MY_DIUP))
	{
		a->dprec = a->precision;
		if (a->precision >= 0)
			a->zero = 0;
		a->cp = buf + BUF;
		if (a->ulval != 0 || a->precision != 0)
			a->cp = print_base(a->cp, a->ulval, a->base, a);
		a->size = buf + BUF - a->cp;
	}
	counter += print_formating(a);
	return (counter);
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	t_args			a;
	size_t			counter;
	char			buf[BUF];
	char			*fmt;

	fmt = (char *)format;
	va_start(args, format);
	counter = 0;
	while (*fmt != '\0')
	{
		if (*fmt != '%')
		{
			ft_print(fmt, 1);
			fmt++;
			counter++;
			continue ;
		}
		fmt++;
		a = (t_args){0, 0, 0, '\0', 0, 0, 0, 0, 0, 0, 0,
			-1, -1, 0, 0, 0, 0, 0, 0};
		counter += function_colection(&fmt, &a, &args, buf);
		fmt = ++a.type;
	}
	return (counter);
}
