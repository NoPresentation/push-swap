/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anashwan <anashwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 00:09:23 by anashwan          #+#    #+#             */
/*   Updated: 2025/12/21 16:34:46 by anashwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/ft_printf.h"
# include "../mini_libft/mini_libft.h"
# include <limits.h>
# include <stdio.h>
# include <unistd.h>

typedef struct doubly_list
{
	int					value;
	struct doubly_list	*next;
	struct doubly_list	*prev;
	struct doubly_list	*target;
	int					cost;
}						t_node;

typedef struct s_stack
{
	t_node				*head;
	t_node				*tail;
	t_node				*max;
	t_node				*min;
	t_node				*cheapest;
	size_t				size;
}						t_stack;

// Validation
t_stack				*parse_input(int argc, char **argv);
int					is_sorted(t_stack *a);
int					is_int(char *input);
int					is_number(char **input);
int					is_duplicate(t_stack *a);
// Sortin
void				push_swap(t_stack *a, t_stack *b);
// Stack function
t_node				*create_node(int value);
t_stack				*create_stack(void);
void				push(t_stack *s, t_node *n);
int					*pop(t_stack *s);
void				free_stack(t_stack **s);
// push operation
int					pa(t_stack *a, t_stack *b, char c);
int					pb(t_stack *a, t_stack *b, char c);
// Swap Operation
int					swap(t_stack *s, char c);
void				ss(t_stack *s, t_stack *b);
// ra r
int					rotate(t_stack *s, char c);
void				rr(t_stack *a, t_stack *b);
// rr
int					rev_rotate(t_stack *s, char c);
void				rrr(t_stack *a, t_stack *b);
// Calculation
void				calculate_cost(t_stack *s);
void				assign_targets(t_stack *first, t_stack *second);
void				find_cheapest(t_stack *b);
// Util
int					abs(int x);
int					min(int x, int y);
int					max(int x, int y);
void				free_split(char **s);

#endif