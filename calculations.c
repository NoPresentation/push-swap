/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anashwan <anashwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 23:10:12 by anashwan          #+#    #+#             */
/*   Updated: 2025/12/14 14:07:35 by anashwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	find_cheapest(t_stack *b)
{
	t_node *node;
	int		min_cost;
	int		total_cost;
	
	node = b->head;
	min_cost = INT_MAX;
	while (node)
	{
		if (node->cost < 0 && node->target->cost < 0)
			total_cost = -1 * min(node->cost, node->target->cost);
		else if (node->cost > 0 && node->target->cost > 0)
			total_cost = max(node->cost, node->target->cost);
		else
			total_cost = abs(node->cost) + abs(node->target->cost);
		if (total_cost < min_cost)
		{
			b->cheapest = node;
			min_cost = total_cost;
		}
		node = node->next;
	}
}

void	assign_targets(t_stack *first, t_stack *second)
{
	t_node *i;
	t_node *j;
	int		holder;

	i = first->head;
	while (i)
	{
		j = second->head;
		holder = INT_MAX;
		while (j)
		{
			if (i->value > second->max->value || i->value < second->min->value)
			{
				i->target = second->min;
				break;;
			}
			if (j->value - i->value > 0 && j->value - i->value < holder)
			{
				i->target = j;
				holder = j->value - i->value;
			}
			j = j->next;
		}
		i = i->next;
	}
}


void	find_min_max(t_stack *s)
{
	t_node *node;
	
	s->min = s->head;
	s->max = s->head;
	node = s->head;
	while (node)
	{
		if (node->value < s->min->value)
			s->min = node;
		if (node->value > s->max->value)
			s->max = node;
		node = node->next;
	}	
}

void	calculate_cost(t_stack *s)
{
	int	mid_line;
	t_node *node;
	int	i;

	find_min_max(s);
	i = 0;
	mid_line = s->size / 2;
	node = s->head;
	while (node)
	{
		if (i <= mid_line)
			node->cost = i;
		else
			node->cost = i - s->size;
		i++;
		node = node->next;
	}
}