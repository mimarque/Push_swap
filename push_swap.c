/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimarque <mimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:05:17 by mimarque          #+#    #+#             */
/*   Updated: 2022/10/13 13:13:01 by mimarque         ###   ########.fr       */
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

/// @brief callback function to print
/// linked list contents made to run with ft_lstiter
/// @param a content to print
void	prt(void *a)
{
	t_stack	*item;

	item = (t_stack *)a;
	ft_printf("%d, ", item->value);
}

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

/// @brief checks if stack a is ordered
/// @param stack 
/// @return bool
bool	is_sorted(t_list *stack)
{
	int		a;
	int		b;

	while (stack->next != NULL)
	{
		a = ((t_stack *) stack->content)->value;
		b = ((t_stack *) stack->next->content)->value;
		if (a > b)
			return (false);
		stack = stack->next;
	}
	return (true);
}

//PUSH OPERATIONS
/// @brief Send item on top of stack to the top of the other
/// @param src sa or sb
/// @param dest sa or sb
void	push(t_list **src, t_list **dest)
{
	t_list	*temp;

	if (*src == NULL)
		return ;
	temp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = temp;
}

void	pa(t_list **s_a, t_list **s_b)
{
	push(s_b, s_a);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_list **s_a, t_list **s_b)
{
	push(s_a, s_b);
	ft_putstr_fd("pb\n", 1);
}

//SWAP OPERATIONS
/// @brief Swaps top two items in stack
/// swaps the values and indexes 
/// without swapping the nodes
/// see: t_stack typedef
/// int	temp;
/// 
/// if (stack == NULL || stack->next == NULL)
/// 	return ;
/// temp = ((t_stack *)stack->content)->value;
/// ((t_stack *)stack->content)->value = ((t_stack *)
/// 		stack->next->content)->value;
/// ((t_stack *)stack->next->content)->value = temp;
/// temp = ((t_stack *)stack->content)->index;
/// ((t_stack *)stack->content)->index = ((t_stack *)
/// 		stack->next->content)->index;
/// ((t_stack *)stack->next->content)->index = temp;
/// @param stack sa or sb
void	swap(t_list **stack)
{
	t_list	*temp;

	if ((*stack) == NULL || (*stack)->next == NULL)
		return ;
	temp = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	temp->next = (*stack);
	(*stack) = temp;
}

void	sa(t_list **s_a)
{
	swap(s_a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_list **s_b)
{
	swap(s_b);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_list **s_a, t_list **s_b)
{
	swap(s_a);
	swap(s_b);
	ft_putstr_fd("ss\n", 1);
}

//ROTATE
/// @brief Top number goes to bottom of stack
/// @param stack sa or sb
void	rotate(t_list **stack)
{
	t_list	*temp;
	t_list	*last;

	if ((*stack) == NULL)
		return ;
	temp = (*stack)->next;
	last = ft_lstlast(*stack);
	last->next = *stack;
	(*stack)->next = NULL;
	*stack = temp;
}

void	ra(t_list **s_a)
{
	rotate(s_a);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_list **s_b)
{
	rotate(s_b);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_list **s_a, t_list **s_b)
{
	rotate(s_a);
	rotate(s_b);
	ft_putstr_fd("rr\n", 1);
}

//REVERSE ROTATE
/// @brief Bottom number goes on top of the stack
/// @param stack 
void	reverse_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*nd_last;

	if ((*stack) == NULL)
		return ;
	last = ft_lstlast(*stack);
	nd_last = ft_lstpenultimate(stack);
	if (nd_last == NULL)
		return ;
	last->next = (*stack);
	(*stack) = last;
	nd_last->next = NULL;
}

void	rra(t_list **s_a)
{
	reverse_rotate(s_a);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_list **s_b)
{
	reverse_rotate(s_b);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_list **s_a, t_list **s_b)
{
	reverse_rotate(s_a);
	reverse_rotate(s_b);
	ft_putstr_fd("rrr\n", 1);
}

/// @brief assigns a position to every element from top to
/// bottom in ascending order. See: t_stack position
/// used to calculate the cost of moving an item to a certain position
/// @param stack 
void	get_position(t_list *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		((t_stack *)stack->content)->pos = i;
		stack = stack->next;
		i++;
	}
}

/// @brief Returns highest index on the stack
/// but not highest value (see: t_stack struct)
/// @param stack 
/// @return 
int	get_highest_index(t_list *stack)
{
	int	value;

	value = ((t_stack *)stack->content)->index;
	while (stack)
	{
		if (((t_stack *)stack->content)->index > value)
			value = ((t_stack *)stack->content)->index;
		stack = stack->next;
	}
	return (value);
}

/// @brief Sorts 3 and only 3 nodes
///    Case		    actions
/// a) 1 2 3		=> no action
/// b) 1 3 2		-> rra -> 2 1 3 -> sa  -> 1 2 3 => 2 actions
/// c) 2 1 3		-> sa  -> 1 2 3 => 1 action
/// d) 2 3 1		-> rra -> 1 2 3 => 1 action
/// e) 3 1 2		-> ra  -> 1 2 3 => 1 action
/// f) 3 2 1		-> ra  -> 2 1 3 -> sa  -> 1 2 3 => 2 actions
/// Note that we don't need a cycle to go trough all combinations
/// also note that (2 1 3) can happen 3 out of 6 times (final check)
/// [b) d) e) f)] we either use ra or rra
/// 2nd *if* checks if 1st node is the biggest [e) f)]
/// *if* not check if 2nd node is the biggest [b) d)]
/// Then check if the 2 first nodes are swapped [2 1 3]
/// @param s_a stack a 
void	mini_sort(t_list **s_a)
{
	int	hi;

	if (is_sorted(*s_a))
		return ;
	hi = get_highest_index(*s_a);
	if (((t_stack *)(*s_a)->content)->index == hi)
		ra(s_a);
	else if (((t_stack *)(*s_a)->next->content)->index == hi)
		rra(s_a);
	if (((t_stack *)(*s_a)->content)->index >
		((t_stack *)(*s_a)->next->content)->index)
		sa(s_a);
}

/// while (size > 6 && i < size && pushed < size / 2)
/// @brief push all nodes (but 3) in a to b in a minamilly ordered way
/// if stack a size is bigger than 6 then send all the numbers smaller
/// than the median to stack b (see: t_stack struct index) and if they
/// are bigger than the median rotate a.
/// After send all but 3 to b.
/// @param s_a stack a 
/// @param s_b stack b
void	push_to_b(t_list **s_a, t_list **s_b)
{
	int	size;
	int	pushed;
	int	i;

	size = ft_lstsize(*s_a);
	pushed = 0;
	i = 0;
	while (size > 6 && i < size && pushed < size / 2)
	{
		if (((t_stack *)(*s_a)->content)->index <= size / 2)
		{
			pb(s_a, s_b);
			pushed++;
		}
		else
			ra(s_a);
		i++;
	}
	while (size - pushed > 3)
	{
		pb(s_a, s_b);
		pushed++;
	}
}

/// @brief gets the position of the element with the lowest index
/// on the stack provided.
/// @param stack stack where to find the lowest index
/// @return 
int	get_lowest_index_position(t_list *stack)
{
	int		l_index;
	int		l_pos;

	get_position(stack);
	l_index = INT_MAX;
	l_pos = ((t_stack *)stack->content)->pos;
	while (stack)
	{
		if (((t_stack *)stack->content)->index < l_index)
		{
			l_index = ((t_stack *)stack->content)->index;
			l_pos = ((t_stack *)stack->content)->pos;
		}
		stack = stack->next;
	}
	return (l_pos);
}


/// not enough lines left in get_target
/// just assigns vars
void	gtp_vars(t_list *tmp_a, int *tidx, int *tpos)
{
	(*tidx) = ((t_stack *)tmp_a->content)->index;
	(*tpos) = ((t_stack *)tmp_a->content)->pos;
}

/// Picks the best target position in stack A for the given index of
/// an element in stack B. First checks if the index of the B element can
/// be placed somewhere in between elements in stack A, by checking whether
/// there is an element in stack A with a bigger index. If not, it finds the
/// element with the smallest index in A and assigns that as the target position.
/// --- Example:
/// 	target_pos starts at INT_MAX
/// 	B index: 3
/// 	A contains indexes: 9 4 2 1 0
/// 	9 > 3 && 9 < INT_MAX 	: target_pos updated to 9
/// 	4 > 3 && 4 < 9 			: target pos updated to 4
/// 	2 < 3 && 2 < 4			: no update!
/// So target_pos needs to be the position of index 4, since it is
/// the closest index.
/// --- Example:
/// 	target_pos starts at INT_MAX
/// 	B index: 20
/// 	A contains indexes: 16 4 3
/// 	16 < 20					: no update! target_pos = INT_MAX
/// 	4  < 20					: no update! target_pos = INT_MAX
/// 	3  < 20					: no update! target_pos = INT_MAX
/// ... target_pos stays at INT MAX, need to switch strategies.
/// 	16 < 20					: target_pos updated to 20
/// 	4  < 20					: target_pos updated to 4
/// 	3  < 20					: target_pos updated to 3
/// So target_pos needs to be the position of index 3, since that is
/// the "end" of the stack.
/// for each node in b (in caller function)
/// go through each node in a 
/// if index of node in a is greater than index of node in b 
/// and if that index is smaller than previous max idex
/// update target index and targuet position (gpt_vars())
/// edge-case:
/// if list is stupidly large and tindex is not between two values
/// tidx is INT_MAX still put it next to the smallest value
void	get_target(t_list *a, t_list *b, int *tidx, int *tpos)
{
	t_list	*tmp_a;

	tmp_a = a;
	while (tmp_a)
	{
		if (((t_stack *)tmp_a->content)->index > ((t_stack *)b->content)->index
			&& ((t_stack *)tmp_a->content)->index < *tidx)
			gtp_vars(tmp_a, tidx, tpos);
		tmp_a = tmp_a->next;
	}
	if (*tidx != INT_MAX)
		return ;
	tmp_a = a;
	while (tmp_a)
	{
		if (((t_stack *)tmp_a->content)->index < *tidx)
			gtp_vars(tmp_a, tidx, tpos);
		tmp_a = tmp_a->next;
	}
	return ;
}

/// Assigns a target position in stack A to each element of stack A.
/// The target position is the spot the element in B needs to
/// get to in order to be sorted correctly. This position will
/// be used to calculate the cost of moving each element to
/// its target position in stack A.
void	get_target_position(t_list *a, t_list *b)
{
	t_list	*tmp_b;
	int		tpos;
	int		tidx;

	tmp_b = b;
	get_position(a);
	get_position(b);
	tpos = 0;
	tidx = INT_MAX;
	while (tmp_b)
	{
		get_target(a, b, &tidx, &tpos);
		((t_stack *)tmp_b->content)->target_pos = tpos;
		tmp_b = tmp_b->next;
	}
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


/// Calculates the cost of moving each element of stack B into the correct
/// position in stack A.
/// Two costs are calculated:
/// 	cost_b represents the cost of getting the element to the top of the s_b
/// 	cost_a represents the cost of getting to the right position in stack A.
/// If the element is in the bottom half of the stack, the cost will be negative
/// if it is in the top half, the cost is positive. 
/// cost b = position on the stack except the last values all decrease by 1
/// after the middle value
/// cost a = position on the stack except the last values all decrease by 1
/// after the middle value
/// @brief Calculates the cost of moving each element from stack b to final pos.
/// @param s_a stack a
/// @param s_b stack b
void	get_cost(t_list *s_a, t_list *s_b)
{
	int		size_a;
	int		size_b;

	size_a = ft_lstsize(s_a);
	size_b = ft_lstsize(s_b);
	while (s_b)
	{
		((t_stack *)s_b->content)->cost_b = ((t_stack *)s_b->content)->pos;
		if (((t_stack *)s_b->content)->pos > size_b / 2)
			((t_stack *)s_b->content)->cost_b
				= (size_b - ((t_stack *)s_b->content)->pos) * -1;
		((t_stack *)s_b->content)->cost_a
			= ((t_stack *)s_b->content)->target_pos;
		if (((t_stack *)s_b->content)->target_pos > size_a / 2)
			((t_stack *)s_b->content)->cost_a
				= (size_a - ((t_stack *)s_b->content)->target_pos) * -1;
		s_b = s_b->next;
	}
}


/// Reverse rotates both stack A and B until one of them is in position.
/// The given cost is negative since both positions are in the bottom half
/// of their respective stacks. The cost is increased as the stacks are
/// rotated, when one reaches 0, the stack has been rotated as far as possible
/// and the top position is correct.
void	rr_both(t_list **a, t_list **b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		rrr(a, b);
	}
}


/// Rotates both stack A and B until one of them is in position.
/// The given cost is positive since both positions are in the top half
/// of their respective stacks. The cost is decreased as the stacks are
/// rotated, when one reaches 0, the stack has been rotated as far as possible
/// and the top position is correct.
void	r_both(t_list **a, t_list **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		rr(a, b);
	}
}

/// Rotates stack A until it is in position. If the cost is negative,
/// the stack will be reverse rotated, if it is positive, it will be 
/// rotated.
void	r_a(t_list **a, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			ra(a);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rra(a);
			(*cost)++;
		}
	}
}

/// Rotates stack B until it is in position. If the cost is negative,
/// the stack will be reverse rotated, if it is positive, it will be 
/// rotated.
void	r_b(t_list **b, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			rb(b);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rrb(b);
			(*cost)++;
		}
	}
}

/// Chooses which move to make to get the B stack element to the correct
/// position in stack A.
/// If the costs of moving stack A and B into position match (i.e. both negative
/// of both positive), both will be	rotated or reverse rotated at the same time.
/// They might also be rotated separately, before finally pushing the top B elem
/// to the top stack A.
void	do_move(t_list **a, t_list **b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		rr_both(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		r_both(a, b, &cost_a, &cost_b);
	r_a(a, &cost_a);
	r_b(b, &cost_b);
	pa(a, b);
}

/// @brief finds the element in stack b with less movements required and
/// moves it to stack a
/// @param s_a stack a 
/// @param s_b stack b
void	do_cheapest_move(t_list **s_a, t_list **s_b)
{
	t_list	*tmp;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	tmp = *s_b;
	cheapest = INT_MAX;
	while (tmp)
	{
		if (ft_abs(((t_stack *)tmp->content)->cost_a)
			+ ft_abs(((t_stack *)tmp->content)->cost_b) < cheapest)
		{
			cheapest = ft_abs(((t_stack *)tmp->content)->cost_b)
				+ ft_abs(((t_stack *)tmp->content)->cost_a);
			cost_a = ((t_stack *)tmp->content)->cost_a;
			cost_b = ((t_stack *)tmp->content)->cost_b;
		}
		tmp = tmp->next;
	}
	do_move(s_a, s_b, cost_a, cost_b);
}


/// After the bulk of the stack is sorted, shifts stack a until the lowest
/// value is at the top. If it is in the bottom half of the stack, reverse
/// rotate it into position, otherwise rotate until it is at the top of the
/// stack.
void	shift_stack(t_list **s_a)
{
	int	lowest_pos;
	int	stack_size;

	stack_size = ft_lstsize(*s_a);
	lowest_pos = get_lowest_index_position(*s_a);
	if (lowest_pos > stack_size / 2)
	{
		while (lowest_pos < stack_size)
		{
			rra(s_a);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			ra(s_a);
			lowest_pos--;
		}
	}
}

/// @brief The Magic happens here
/// pushes all but 3 values to s_b then orders those 3 values
/// then while there are elements in b find where they need to be
/// then determine how costly is to move them then do cheapest move
/// after everything is in a check if it is ordered if not shift elements
/// @param s_a 
/// @param s_b 
void	sort(t_list **s_a, t_list **s_b)
{
	push_to_b(s_a, s_b);
	mini_sort(s_a);
	while (*s_b)
	{
		get_target_position(*s_a, *s_b);
		get_cost(*s_a, *s_b);
		do_cheapest_move(s_a, s_b);
	}
	if (!is_sorted(*s_a))
		shift_stack(s_a);
}

/// @brief Decides what course to take
/// if 2 elements but not ordered do *sa*
/// if 3 elements but not ordered do mini_sort
/// if more than 3 elem not ordered do sort
/// @param s_a 
/// @param s_b 
void	push_swap(t_list **s_a, t_list **s_b)
{
	int		size;
	bool	o;

	size = ft_lstsize(*s_a);
	o = is_sorted(*s_a);
	if (size == 2 && !o)
		sa(s_a);
	else if (size == 3)
		mini_sort(s_a);
	else if (size > 3 && !o)
		sort(s_a, s_b);
}

int	main(int argc, char *argv[])
{
	t_list	*s_a;
	t_list	*s_b;

	s_a = NULL;
	s_b = NULL;
	initialize(argc, argv, &s_a);
	push_swap(&s_a, &s_b);
	ft_lstclear(&s_a, del_stk);
}