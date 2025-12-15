/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anashwan <anashwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 19:20:58 by anashwan          #+#    #+#             */
/*   Updated: 2025/12/15 20:03:33 by anashwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_stack *s, char c)
{
	int	temp;

	if (s->size < 2)
		return (0);
	temp = s->head->value;
	s->head->value = s->head->next->value;
	s->head->next->value = temp;
	if (c == 'a' || c == 'b')
		ft_printf("s%c\n", c);
	return (1);
}

void	ss(t_stack *a, t_stack *b)
{
	int x;

	x = swap(a, 's') + swap(b, 's');
	if (x)
		ft_printf("ss\n");
}