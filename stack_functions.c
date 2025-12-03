/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anashwan <anashwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 22:44:55 by anashwan          #+#    #+#             */
/*   Updated: 2025/12/03 18:48:09 by anashwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*push(t_stack *s, t_node *n)
{
	if (!s || !n)
		return (NULL);
	if (s->size == 0)
	{
		s->head = n;
		s->tail = n;
		s->size++;
		return (n);
	}
	n->next = s->head;
	n->prev = NULL;
	s->head->prev = n;
	s->head = n;
	s->size++;
	return (n);
}

int	*pop(t_stack **s)
{
	t_stack	*st;
	t_node	*temp;
	int		*value;

	st = *s;
	if (!s || st->size == 0)
		return (NULL);
	value = malloc(sizeof(int));
	if (st->size == 1)
	{
		*value = st->head->value;
		free(st->head);
		st->head = NULL;
		st->tail = NULL;
		st->size = 0;
		return (value);
	}
	temp = st->head;
	*value = temp->value;
	st->head = st->head->next;
	st->head->prev = NULL;
	free(temp);
	st->size--;
	return (value);
}

int	*peek_top(t_stack *s)
{
	if (!s || s->size == 0)
		return (NULL);
	return (&(s->head->value));
}

int	*peek_tail(t_stack *s)
{
	if (!s || s->size == 0)
		return (NULL);
	return (&(s->tail->value));
}

void	free_stack(t_stack **s)
{
	t_node	*n;
	t_node	*temp;

	if (!s || (*s)->size == 0)
		return ;
	n = (*s)->head;
	while (n)
	{
		temp = n->next;
		free(n);
		n = temp;
	}
	free(*s);
}
