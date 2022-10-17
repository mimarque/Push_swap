/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimarque <mimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 02:25:14 by mimarque          #+#    #+#             */
/*   Updated: 2022/10/17 12:58:15 by mimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief Checks if string is an int
/// 1) Skips whitespace
/// 2) Checks sign + or -
/// 3) checks if after the sign there's a digit
/// 4) For each char checks if its a digit
/// 4.1) Multiplies previous value by 10 and
///		 adds current positional value
/// 4.2) Checks if that value is greater or
///		 smaller than what INT can hold
/// 5) If there is a char break and return false
bool	is_intnumber(char *str)
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
		return (false);
	while (*str && ft_isdigit(*str))
	{
		sum = sum * 10 + *str - '0';
		str++;
		if (sum * s > INT_MAX)
			return (false);
		else if (sum * s < INT_MIN)
			return (false);
	}
	if (*str == 0)
		return (true);
	return (false);
}

/// @brief verifies if array has duplicates
///	array must be null terminated
/// 1) checks size of array
/// 2) goes over each char checking if
///	   subsequent chars are equal if so 
///    returns false
/// @param arr 
/// @return bool
bool	has_duplicates(int *arr)
{
	int	i;
	int	j;
	int	c;

	c = 0;
	while (arr[c])
		c++;
	i = 0;
	while (i < c - 1)
	{
		j = i + 1;
		while (j < c)
		{
			if (arr[i] == arr[j])
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

/// @brief callback function to delete
/// linked list contents made to run with ft_lstclear
/// @param a content to delete
void	del_stk(void *a)
{
	t_stack	*item;

	item = (t_stack *)a;
	free(item);
	item = NULL;
}

/// @brief absolute value
/// @param n value
/// @return absolute value
int	ft_abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

/// @brief checks if stack a is ordered
/// @param argc 
/// @param s_a 
/// @return bool
bool	is_sa_ordered(int argc, t_list *stack)
{
	int		a;
	int		b;
	int		size;
	t_list	*current;

	size = ft_lstsize(stack);
	if (size != argc - 1)
		return (false);
	if (size == 1)
		return (true);
	current = stack;
	while (current->next != NULL)
	{
		a = ((t_stack *) current->content)->value;
		b = ((t_stack *) current->next->content)->value;
		if (a > b)
			return (false);
		current = current->next;
	}
	return (true);
}