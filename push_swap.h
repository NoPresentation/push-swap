/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anashwan <anashwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 00:09:23 by anashwan          #+#    #+#             */
/*   Updated: 2025/12/13 23:23:14 by anashwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
#include <limits.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct doubly_list
{
	int						value;
	struct doubly_list 		*next;
	struct doubly_list		*prev;
	struct doubly_list		*target;
	int						cost;
}					t_node;

typedef struct s_stack
{
	t_node			*head;
	t_node			*tail;
	t_node			*max;
	t_node			*min;
	t_node			*cheapest;
	size_t			size;
}					t_stack;

// Validation
t_stack		*check_input(int size, char **input);
int			is_sorted(t_stack* a);

// Constructors
t_node	*create_node(int value);
t_stack	*create_stack(void);

// Stack functions
void	push(t_stack *s, t_node *n);
int		*pop(t_stack *s);
void	free_stack(t_stack **s);
void	free_all(t_stack **a, t_stack **b);

// push operations
int		pa(t_stack *a, t_stack *b);
int 	pb(t_stack *a, t_stack *b);

// Swap Operations
int		swap(t_stack *s, char c);
void	ss(t_stack *s, t_stack *b);

// ra rb
int		rotate(t_stack *s, char c);
void	rr(t_stack *a, t_stack *b);


// rrr
int		rev_rotate(t_stack *s, char c);
void 	rrr(t_stack *a, t_stack *b);

// Calculations
void	calculate_cost(t_stack *s);
void	assign_targets(t_stack *first, t_stack *second);
void	find_cheapest(t_stack *b);
void	perform_operations(t_stack *a, t_stack *b);
void	final_touch(t_stack *a);

// Utils
int		abs(int x);
int		min(int x, int y);
int		max(int x, int y);

// Print out functions
void	print_stack(t_stack *s);
void	print_ab(t_stack *stack_a, t_stack *stack_b);


// Sorting
void	push_swap(t_stack *a, t_stack *b);
void	sort_three(t_stack *a);


#endif