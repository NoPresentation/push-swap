/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rreverse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anashwan <anashwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 17:46:24 by anashwan          #+#    #+#             */
/*   Updated: 2025/12/04 19:00:43 by anashwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rra(t_stack *a)
{
	t_node	*temp;

	if (!a || a->size <= 1)
		return (-1);
	temp = a->tail;
	a->tail = temp->prev;
	a->tail->next = NULL;
	a->head->prev = temp;
	temp->next = a->head;
	temp->prev = NULL;
	a->head = temp;
	return (1);
}

int	rrb(t_stack *b)
{
	t_node	*temp;

	if (!b || b->size <= 1)
		return (-1);
	temp = b->tail;
	b->tail = temp->prev;
	b->tail->next = NULL;
	b->head->prev = temp;
	temp->next = b->head;
	temp->prev = NULL;
	b->head = temp;
	return (1);
}

int rrr(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return (-1);
	return (rra(a) + rrb(b));
}