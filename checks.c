/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anashwan <anashwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 10:58:11 by anashwan          #+#    #+#             */
/*   Updated: 2025/12/13 23:06:27 by anashwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	is_sorted(t_stack* a)
{
	t_node *node;

	node = a->head;
	while (node->next)
	{
		if (node->value > node->next->value)
			return (0);
		node = node->next;
	}
	return (1);
}


static int ft_isnumber(const char *s)
{
	int		i;

	i = 0;
	if (!s || s[i] == '\0')
		return (-1);
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}


static int is_duplicate(t_stack *stack, int value)
{
	t_node *node;

	if (!stack)
		return (1);
	node = stack->head;
	while (node)
	{
		if (node->value == value)
			return (1);
		node = node->next;
	}
	return (0);
}


t_stack	*check_input(int size, char **input)
{
	int	i;
	int	value;
	t_node	*node;
	t_stack	*a;
	
	i = 1;
	if (size == 2)
		i = 0;
	a = create_stack();
	while (i < size)
	{
		if (!(ft_isnumber(input[i])))
			return (NULL);
		value = ft_atoi(input[i]);
		node = create_node(value);
		if (is_duplicate(a, value) || !node)
			return (NULL);
		push(a, node);
		i++;
	}
	return (a);
}
