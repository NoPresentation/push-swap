/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anashwan <anashwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 22:44:55 by anashwan          #+#    #+#             */
/*   Updated: 2025/12/14 11:39:23 by anashwan         ###   ########.fr       */
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

void	free_all(t_stack **a, t_stack **b)
{
	free_stack(a);
	free_stack(b);
}