/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anashwan <anashwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 22:44:55 by anashwan          #+#    #+#             */
/*   Updated: 2025/12/15 21:45:50 by anashwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *s, t_node *n)
{
	if (s->size == 0)
	{
		s->head = n;
		s->tail = n;
		s->size++;
		return ;
	}
	n->next = s->head;
	n->prev = NULL;
	s->head->prev = n;
	s->head = n;
	s->size++;
}

int	*pop(t_stack *s)
{
	t_node	*temp;
	int		*value;

	value = malloc(sizeof(int));
	if (!value)
		return (NULL);
	if (s->size == 1)
	{
		*value = s->head->value;
		free(s->head);
		s->head = NULL;
		s->tail = NULL;
		s->size = 0;
		return (value);
	}
	temp = s->head;
	*value = temp->value;
	s->head = s->head->next;
	s->head->prev = NULL;
	free(temp);
	s->size--;
	return (value);
}

t_node	*create_node(int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->target = NULL;
	new_node->value = value;
	new_node->cost = 0;
	return (new_node);
}

t_stack	*create_stack(void)
{
	t_stack	*new_stack;

	new_stack = malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack->head = NULL;
	new_stack->tail = NULL;
	new_stack->min = NULL;
	new_stack->max = NULL;
	new_stack->cheapest = NULL;
	new_stack->size = 0;
	return (new_stack);
}

void	free_stack(t_stack **s)
{
	t_node	*n;
	t_node	*temp;

	if (!s || !*s)
		return ;
	n = (*s)->head;
	while (n)
	{
		temp = n->next;
		free(n);
		n = temp;
	}
	free(*s);
	*s = NULL;
}