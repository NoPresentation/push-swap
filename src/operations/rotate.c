/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anashwan <anashwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 19:30:13 by anashwan          #+#    #+#             */
/*   Updated: 2025/12/17 22:13:54 by anashwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	rotate(t_stack *s, char c)
{
	t_node	*temp;

	temp = s->head;
	if (s->size <= 1)
		return (0);
	s->head = s->head->next;
	s->head->prev = NULL;
	temp->prev = s->tail;
	s->tail->next = temp;
	s->tail = temp;
	s->tail->next = NULL;
	if (c == 'a' || c == 'b')
		ft_printf("r%c\n", c);
	return (1);
}

void	rr(t_stack *a, t_stack *b)
{
	int	x;

	x = rotate(a, 'r') + rotate(b, 'r');
	if (x)
		ft_printf("rr\n");
}

int	rev_rotate(t_stack *s, char c)
{
	t_node	*temp;

	if (s->size <= 1)
		return (0);
	temp = s->tail;
	s->tail = temp->prev;
	s->tail->next = NULL;
	s->head->prev = temp;
	temp->next = s->head;
	temp->prev = NULL;
	s->head = temp;
	if (c == 'a' || c == 'b')
		ft_printf("rr%c\n", c);
	return (1);
}

void	rrr(t_stack *a, t_stack *b)
{
	int	x;

	x = rev_rotate(a, 'r') + rev_rotate(b, 'r');
	if (x)
		ft_printf("rrr\n");
}
