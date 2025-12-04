/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anashwan <anashwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 19:01:21 by anashwan          #+#    #+#             */
/*   Updated: 2025/12/04 19:15:10 by anashwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pa(t_stack *a, t_stack *b)
{
	int		*value;
	
	if (!a || !b)
	{
		free_stack(&a);
		free_stack(&b);
		return (-1);
	}
	if (b->size == 0)
		return (0);
	value = pop(b);
	push(a, create_node(*value));
	free(value);
	return (1);
}

int pb(t_stack *a, t_stack *b)
{
	int		*value;
	
	if (!a || !b)
	{
		free_stack(&a);
		free_stack(&b);
		return (-1);
	}
	if (a->size == 0)
		return (0);
	value = pop(a);
	push(b, create_node(*value));
	free(value);
	return (1);
}