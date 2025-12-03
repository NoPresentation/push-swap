/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anashwan <anashwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 22:47:58 by anashwan          #+#    #+#             */
/*   Updated: 2025/12/03 00:31:18 by anashwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *s)
{
	t_node	*n;

	if (!s || s->size == 0)
		return ;
	n = s->head;
	while (n)
	{
		ft_printf("%d\n", n->value);
		n = n->next;
	}
}

void	print_ab(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*a;
	t_node	*b;

	a = stack_a->head;
	b = stack_b->head;
	while (a || b)
	{
		if (a)
		{
			ft_printf("%d", a->value);
			a = a->next;
		}
		ft_printf("\t");
		if (b)
		{
			ft_printf("%d", b->value);
			b = b->next;
		}
		ft_printf("\n");
	}
}
