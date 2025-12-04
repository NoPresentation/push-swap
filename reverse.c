/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anashwan <anashwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 19:30:13 by anashwan          #+#    #+#             */
/*   Updated: 2025/12/04 17:44:56 by anashwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ra(t_stack *a)
{
	t_node	*temp;
	
	temp = a->head;
	if (!a || a->size <= 1)
		return (-1);
	a->head = a->head->next;
	a->head->prev = NULL;
	temp->prev = a->tail;
	a->tail->next = temp;
	a->tail = temp;
	a->tail->next = NULL;
	return (1);
}

int		rb(t_stack *b)
{
	t_node	*temp;
	
	temp = b->head;
	if (!b || b->size <= 1)
		return (-1);
	b->head = b->head->next;
	b->head->prev = NULL;
	temp->prev = b->tail;
	b->tail->next = temp;
	b->tail = temp;
	b->tail->next = NULL;
	return (1);
}

int rr(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return (-1);
	return (rb(b) + ra(a));
}