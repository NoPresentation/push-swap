/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anashwan <anashwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 19:20:58 by anashwan          #+#    #+#             */
/*   Updated: 2025/12/03 19:28:46 by anashwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		sa(t_stack *a)
{
	int temp;

	if (!a)
		return (-1);
	if (a->size < 2)
		return (0);
	temp = a->head->value;
	a->head->value = a->head->next->value;
	a->head->next->value = temp;
	return (1);
}

int		sb(t_stack *b)
{
	int temp;

	if (!b)
		return (-1);
	if (b->size < 2)
		return (0);
	temp = b->head->value;
	b->head->value = b->head->next->value;
	b->head->next->value = temp;
	return (1);
}

int		ss(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return (b);
	return (sa(a) + s(b));
}