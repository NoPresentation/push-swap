/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anashwan <anashwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:14:31 by anashwan          #+#    #+#             */
/*   Updated: 2025/12/15 23:49:25 by anashwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	final_touch(t_stack *a)
{
	while (a->min->cost < 0)
	{
		rev_rotate(a, 'a');
		a->min->cost++;
	}
	while (a->min->cost > 0)
	{
		rotate(a, 'a');
		a->min->cost--;
	}
}

static void	different_operations(t_stack *a, t_stack *b)
{
	t_node	*node;

	node = b->cheapest;
	while (node->cost < 0)
	{
		rev_rotate(b, 'b');
		node->cost++;
	}
	while (node->cost > 0)
	{
		rotate(b, 'b');
		node->cost--;
	}
	while (node->target->cost < 0)
	{
		rev_rotate(a, 'a');
		node->target->cost++;
	}
	while (node->target->cost > 0)
	{
		rotate(a, 'a');
		node->target->cost--;
	}
	pa(a, b);
}

static void	perform_operations(t_stack *a, t_stack *b)
{
	t_node	*node;
	int		i;

	node = b->cheapest;
	i = 0;
	if (node->cost < 0 && node->target->cost < 0)
	{
		i = max(node->cost, node->target->cost);
		node->cost -= i;
		node->target->cost -= i;
		while (i++ < 0)
			rrr(a, b);
	}
	else if (node->cost > 0 && node->target->cost > 0)
	{
		i = min(node->cost, node->target->cost);
		node->cost -= i;
		node->target->cost -= i;
		while (i-- > 0)
			rr(a, b);
	}
	different_operations(a, b);
}

static void	sort_three(t_stack *a)
{
	int	x;
	int	y;
	int	z;
	
	x = a->head->value;
	y = a->head->next->value;
	z = a->tail->value;
	if (x > y && y < z && x > z)
		rotate(a, 'a');
	else if (x < y && y > z && x > z)
		rev_rotate(a, 'a');
	else if (x > y && y > z)
	{
		swap(a, 'a');
		rev_rotate(a, 'a');
	}
	else if (x > y && y < z && x < z)
		swap(a, 'a');
	else if (x < y && y > z && x < z)
	{
		swap(a, 'a');
		rotate(a, 'a');
	}
}	

void	push_swap(t_stack *a, t_stack *b)
{
	if (a->size == 2)
	{
		swap(a, 'a');
		return ;
	}
	else if (a->size == 3)
	{
		sort_three(a);
		return ;	
	}
	while (a->size > 3)
		pb(a, b);
	sort_three(a);
	while (b->size > 0)
	{
		calculate_cost(a);
		calculate_cost(b);
		assign_targets(b, a);
		find_cheapest(b);
		perform_operations(a, b);
	}
	calculate_cost(a);
	final_touch(a);
}
