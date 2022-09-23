/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimarque <mimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:05:17 by mimarque          #+#    #+#             */
/*   Updated: 2022/09/23 15:50:08 by mimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;


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

/// @brief Validates arguments and spits an array with
/// all values if there are no errors
/// 1) Alocates memmory for number of arguments
///	  (elements + \0) as array arr
/// 2) if it looks like int convert 'string' to int
/// 3) check if it has any repeated values
/// 4) if 2 or 3 are false free array, spit error & GTFO
int	*store_validate_data(int argc, char *argv[])
{
	int	*arr;
	int	i;

	arr = ft_calloc(argc, sizeof(int));
	i = 0;
	while (i < argc - 1)
	{
		if (is_intnumber(argv[i + 1]))
			arr[i] = ft_atoi(argv[i + 1]);
		else
		{
			write(2, "Error\n", 6);
			free(arr);
			exit(2);
		}
		i++;
	}
	if (has_duplicates(arr))
	{
		write(2, "Error\n", 6);
		free(arr);
		exit(3);
	}
	return (arr);
}

void	ll_add_front(void)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
}

int	main(int argc, char *argv[])
{
	int		*arr;

	arr = store_validate_data(argc, argv);
	for(int i = 0; i < argc - 1; i++)
		ft_printf("%d\n", arr[i]);
	free(arr);
}