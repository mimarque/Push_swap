# Push_swap
Because Swap_push isn’t as natural


## Description of the problem


<sub>Description taken from [Jamie Dawson's](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a) Medium</sub>

---

You have two stacks called **Stack A** and **Stack B**. Stack A is given a random list of unorganized numbers. You must take the random list of numbers in Stack A and sort them so that Stack A is organized from smallest to largest. There are only a few moves you’re allowed to used to manipulate the stacks that we’re going to call “Actions”. The main goal of this project is to organize Stack A in as few actions as possible.

The actions are named: **sa, sb, ss, ra, rb, rr, rra, rrb, rrr, pa, pb**.

Here’s how they all work:

![](https://imgur.com/hRfW8OI.png)
![](https://imgur.com/H02IxoU.png)
![](https://imgur.com/AhBVtR4.png)
![](https://imgur.com/i4yoqP3.png)
## Breakdown of the Solution


This project doesn't have to be much optimized only the output. So we can use more time and CPU cycles trying to figure out where to put our values.

We'll use [libft](https://github.com/mimarque/libft)'s bonus Linked Lists in conjunction with this struct:

    `typedef struct s_stack
    {
    	int				value;
    	int				index;
    	int				pos;
    	int				target_pos;
    	int				cost_a;
    	int				cost_b;
    }	t_stack;`

-   **value**: the integer we must sort,
-   **index**: its index in the list of all values that must be sorted,
-   **pos**: its current position in its stack,
-   **target_pos**: for elements in stack B, the target position in stack A where it should be,
-   **cost_a**: how many actions it would cost to rotate stack A so that the element at the target position gets to the top of stack A,
-   **cost_b**: how many actions it would cost to rotate stack B so that this element gets to the top of stack B,

Before we fill the stack we check the input and make sure each value is in between `INT_MAX` and `INT_MIN` (`is_intnumber`) before writing to an array (a1)(`store_validate_data`) and that there are no duplicates (`has_duplicates`).

We order with bubble sort the values in another array (a2)(`sort_values`), fill stack a (`init_stack`) and add the index to it. 
Since we don't have duplicate values and we have an array with the unorganized positions (a1) and other with the organized ones (a2) we can just use both to add the index to each of the stack a nodes  `node->content->index`.

After this comes the sorting, we need to make sure the stack isn't already sorted (`is_sorted`) if so we're done, if not we have 3 possible sorting scenarios (`push_swap`):
 1. we have 2 values: We just do `SA` and we're done.
 2. we have 3 values: We use a optimised sort to sort 3 values (`mini_sort`)
 3. we have more than 3 values: We use a general case sort(`sort`)

#### Mini_Sort
When we have 3 values we only have 6 possible combinations of those same values, that we can take advantage of:

```
Case		
1 2 3	  -> nothing to do
1 3 2		-> rra -> 2 1 3 -> sa  -> 1 2 3 
2 1 3		-> sa  -> 1 2 3 
2 3 1		-> rra -> 1 2 3 
3 1 2		-> ra  -> 1 2 3 
3 2 1		-> ra  -> 2 1 3 -> sa  -> 1 2 3 
```
Note how the "2-1-3" occurs 3 out of 5 times we can boil it down to something like:

1. get the highest index (`get_highest_index`)
2. if the highest index is first then do `RA`
3. else if highest index is second do `RRA`
4. then if first element is greater than the second do `SA`

#### Sort
This one is the tricky part.
We take use of the struct we created earlier to send values to their respective positions.
 
Whenever we push nodes from one stack to the other we reverse the order of the list:
 ```
 1     5
 2     4
 3 <-> 3
 4     2
 5     1
 -     - 
 A     B
 ```
So we can try to use that to our advantage.
First we try to send everything (but 3 values) in a "half-ordered" way to stack b. 
We send first the all the numbers smaller than the median to stack b, and rotate the bigger ones to the bottom of stack a, pushing them afterwards. (`push_to_b`)

Then we sort the 3 remaining values (`mini_sort`)

And now for each value in b we:
1. Find position where b goes
 a. find and put the position of each element on each stack (see struct) (`get_position`)
b. try to find the lowest gap between 2 values in `stack a` where a b value can go (`get_target`)
2. Calculate the cost of moving each element. Since we can always rotate elements from the bottom we can divide our stack into 2 halves one with positive cost other with negative.  (we will decide based on absolute value) (`get_cost`)
3. Pick cheapest value to order.(`do_cheapest_move`)
4. Move it to the right position (`do_move`)
 
 After all this if stack a is still not ordered rotate it into position.(`shift_stack`)

 

Flowcharts of the code (moves are not included):
![flowchart](https://imgur.com/RZOfvzl.png)
![code flowchart](https://imgur.com/iIBltnG.png)
