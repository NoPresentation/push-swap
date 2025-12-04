/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anashwan <anashwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 00:09:23 by anashwan          #+#    #+#             */
/*   Updated: 2025/12/04 18:42:13 by anashwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct doubly_list
{
	int						value;
	struct doubly_list 		*next;
	struct doubly_list		*prev;
}					t_node;

typedef struct s_stack
{
	t_node			*head;
	t_node			*tail;
	size_t			size;
}					t_stack;

// Input validation
t_stack	*check_input(int size, char **input);

// Constructors
t_node	*create_node(int value);
t_stack	*create_stack(void);

// Stack functions
t_node	*push(t_stack *s, t_node *n);
int		*pop(t_stack *s);
int		*peek_top(t_stack *s);
int		*peek_tail(t_stack *s);
void	free_stack(t_stack **s);

// push operations
int		pa(t_stack *a, t_stack *b);
int 	pb(t_stack *a, t_stack *b);

// Swap Operations
int		sa(t_stack *a);
int		sb(t_stack *b);
int		ss(t_stack *a, t_stack *b);

// ra rb
int		ra(t_stack *a);
int		rb(t_stack *b);
int		rr(t_stack *a, t_stack *b);


// rrr
int		rra(t_stack *a);
int		rrb(t_stack *b);
int 	rrr(t_stack *a, t_stack *b);
// Print out functions
void	print_stack(t_stack *s);
void	print_ab(t_stack *stack_a, t_stack *stack_b);

// Throw away
void	test(t_stack *a, t_stack *b);

#endif