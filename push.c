/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anashwan <anashwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 19:01:21 by anashwan          #+#    #+#             */
/*   Updated: 2025/12/13 17:12:09 by anashwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pa(t_stack *a, t_stack *b)
{
	int		*value;
	t_node	*node;
	if (b->size == 0)
		return (1);
	value = pop(b);
	if (value == NULL)
		return (0);
	node = create_node(*value);
	if (!node)
		return (0);
	push(a, node);
	free(value);
	ft_printf("pa\n");
	return (1);
}

int	pb(t_stack *a, t_stack *b)
{
	int		*value;
	t_node	*node;
	
	if (a->size == 0)
		return (1);
	value = pop(a);
	if (value == NULL)
		return (0);
	node = create_node(*value);
	if (!node)
		return (0);
	push(b, node);
	free(value);
	ft_printf("pb\n");
	return (1);
}