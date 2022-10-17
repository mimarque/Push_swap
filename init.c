/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimarque <mimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 02:18:09 by mimarque          #+#    #+#             */
/*   Updated: 2022/10/17 02:22:11 by mimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief Initializes stack a with value and index (see: t_stack struct)
/// calls store_valid... that validates input and creates array with values
/// then calls sort_values that creates another array with *sorted* values
/// then calls init_stack that creates stack a by reading the array with values
/// then calls values_to_index to assign indexes to the values in stack a
/// then frees both arrays as they are no longer needed.
/// @param argc number of arguments to know size of array
/// @param argv array of strings with the values 
/// @param s_a Stack a
void	initialize(int argc, char **argv, t_list **s_a)
{
	int		*arr;
	int		*iarr;
	int		size;

	size = argc - 1;
	arr = store_validate_data(argc, argv);
	iarr = sort_values(argc, arr);
	init_stack(argc, arr, s_a);
	index_values(arr, iarr, size, s_a);
	free(iarr);
	free(arr);
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

/// @brief creates a new array with the same values as the original
/// and then sorts it using bubble sort.
/// @param argc 
/// @param arr 
/// @return 
int	*sort_values(int argc, int *arr)
{
	int	i;
	int	j;
	int	t;
	int	*iarr;

	iarr = ft_calloc(argc, sizeof(int));
	ft_memcpy(iarr, arr, (sizeof(int) * argc - 1));
	i = 0;
	while (i < argc - 1)
	{
		j = 0;
		while (j < argc - i - 2)
		{
			if (iarr[j] > iarr[j + 1])
			{
				t = iarr[j];
				iarr[j] = iarr[j + 1];
				iarr[j + 1] = t;
			}
			j++;
		}
		i++;
	}
	return (iarr);
}

/// @brief initiates stack a
/// with the values in arr in reverse order
/// by creating and initialising struct t_stack and
/// passing it to lstnew that creates a node and then
/// passing it to lstadd_front (in reverse order)
/// @param argc 
/// @param arr 
/// @param s_a 
void	init_stack(int argc, int *arr, t_list **s_a)
{
	t_list	*temp;
	t_stack	*item;
	int		i;

	i = argc - 2;
	while (i >= 0)
	{
		item = malloc(sizeof(t_stack));
		if (!item)
		{
			ft_lstclear(s_a, del_stk);
			free(arr);
			write(2, "Error\n", 6);
			exit(3);
		}
		*item = (t_stack){0};
		item->value = arr[i];
		temp = ft_lstnew(item);
		ft_lstadd_front(s_a, temp);
		i--;
	}
}

/// @brief uses a unsorted (inputed values) and a sorted array to find 
/// the index of the value.
/// Go through unsorted array then go through sorted array until you find a
/// match (arr[i] == iarr[j]), Keep the index of the match (j). 
/// Then go through stack a until you find a value match again (arr[i]).
/// Put the index (of the sorted array index (j)) in the index field.
/// Example:
/// unsorted array: 	[12][30][15][08][07][40][18]
/// sorted array:		[07][08][12][15][18][30][40]
/// sorted arr index:	[ 0][ 1][ 2][ 3][ 4][ 5][ 6]
/// [12]->[30]->[15]->[08]->[07]->[40]->[18]
/// [ 0]  [ 0]  [ 0]  [ 0]  [ 0]  [ 0]  [ 0]
///
/// unsorted array: 	 [12]
/// sorted array:		 [07][08][12]
/// sorted arr index (j):		 [ 2]
/// Stack a:
/// [12]->[30]->[...]
/// [ 2]  [ 0]  [ 0 ]  
///
/// [12]->[30]->[15]->[08]->[07]->[40]->[18]
/// [ 2]  [ 5]  [ 3]  [ 1]  [ 0]  [ 6]  [ 4]
/// @param arr unsorted array
/// @param iarr sorted array
/// @param size size of arrays
/// @param s_a stack a
void	index_values(int *arr, int *iarr, int size, t_list **s_a)
{
	t_list	*stk;
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = -1;
		while (++j < size)
			if (arr[i] == iarr[j])
				break ;
		stk = *s_a;
		while (((t_stack *)stk->content)->value != arr[i])
			stk = stk->next;
		((t_stack *)stk->content)->index = j;
		i++;
	}
}
