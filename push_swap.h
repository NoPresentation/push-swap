/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anashwan <anashwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 00:09:23 by anashwan          #+#    #+#             */
/*   Updated: 2025/12/03 10:49:08 by anashwan         ###   ########.fr       */
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
int		*pop(t_stack **s);
int		*peek_top(t_stack *s);
int		*peek_tail(t_stack *s);
void	free_stack(t_stack **s);


// Print out functions
void	print_stack(t_stack *s);
void	print_ab(t_stack *stack_a, t_stack *stack_b);

#endif