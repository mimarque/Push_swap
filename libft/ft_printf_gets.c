/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_gets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimarque <mimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 21:25:05 by mimarque          #+#    #+#             */
/*   Updated: 2022/05/16 14:05:09 by mimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Convert the numbers from string to int
 * 		  return the value as int
 * 
 * @param format pos of the first number
 * @return int 
 */
int	get_value(char **format)
{
	int	n;

	n = 0;
	if (ft_isdigit(**format))
	{
		while (ft_isdigit(**format))
		{
			n = 10 * n + ((**format) - '0');
			++*format;
		}
		--*format;
		if (n < 0)
			n = -1;
	}
	return (n);
}

/**
 * @brief Gets the value of '*'
 * 
 * @param a the struct used in this program
 * @param args vareadic list
 * @return * void 
 * 
 * ``A negative field width argument is taken as a
 *	- flag followed by a positive field width.''
 *	-- ANSI X3J11
 */
void	get_star(t_args *a, va_list args)
{
	a->width = va_arg(args, int);
	if (a->width < 0)
	{
		a->width = -a->width;
		a->dash = !a->dash;
	}
}

/**
 * @brief Get precision gets the value after '.'.
	If * is passed as a negative argument then
	precision is ignored
 * 
 * @param a the struct used in this program
 * @param format position of the dot
 * @param args vareadic list
 * @return * void 
 */
void	get_precision(t_args *a, char **format, va_list *args)
{
	int	n;

	n = 0;
	a->dot = 1;
	if (*(++*format) == '*')
	{
		a->precision = va_arg(*args, int);
		if (a->precision < 0)
			a->precision = -1;
	}
	else
	{
		if (ft_isdigit(**format))
		{
			while (ft_isdigit(**format))
			{
				n = 10 * n + ((**format) - '0');
				++*format;
			}
			if (n < 0)
				n = -1;
		}
		--*format;
		a->precision = n;
	}
}

/**
 * @brief Loop to get the flags 
 * 
 * @param fmt format passed by reference
 * @param a the struct used in this program
 * @param args variadic list
 * 
 * "If the space and + flags both appear,
 * the space flag will be ignored."
 */
void	get_flags(char **fmt, t_args *a, va_list *args)
{
	while (*fmt != a->type && **fmt != '\0')
	{
		if (**fmt == '#')
			a->hash = 1;
		else if (**fmt == '-')
			a->dash = 1;
		else if (**fmt == '+')
			a->sign = '+';
		else if (**fmt == ' ' && a->sign == 0)
			a->sign = ' ';
		else if (**fmt == '0')
			a->zero = 1;
		else if (**fmt == '.')
			get_precision(a, fmt, args);
		else if (**fmt == '*')
			get_star(a, *args);
		else if (**fmt == '1' || **fmt == '2' || **fmt == '3'
			|| **fmt == '4' || **fmt == '5' || **fmt == '6'
			|| **fmt == '7' || **fmt == '8' || **fmt == '9')
			a->width = get_value(fmt);
		++*fmt;
	}
}

/**
 * @brief Get the type values from vareadic args
 * 
 * @param a the struct used in this program
 * @param args vareadic list
 */
void	get_type_values(t_args *a, va_list *args)
{
	if (*a->type == '%')
	{
		a->cp = "%";
		a->size = 1;
	}
	else if (*a->type == 'c')
	{
		a->c = va_arg(*args, int);
		a->cp = &a->c;
	}
	else if (*a->type == 's')
	{
		a->cp = va_arg(*args, char *);
		if (a->cp == NULL)
			a->cp = "(null)";
	}
	else if (*a->type == 'p')
		a->ulval = (U_LONG) va_arg(*args, void *);
	else if (*a->type == 'd' || *a->type == 'i')
		a->ulval = (U_LONG) va_arg(*args, int);
	else if (ft_substrpbrk(a->type, 1, MY_UNSIGNED))
		a->ulval = (U_LONG) va_arg(*args, unsigned int);
}
