/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anashwan <anashwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 10:58:11 by anashwan          #+#    #+#             */
/*   Updated: 2025/12/03 18:49:56 by anashwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int ft_isnumber(const char *s)
{
	int		i;

	if (!s || s[i] == '\0')
		return (-1);
	i = 0;
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
	
	t_stack	*a;
	
	i = 1;
	a = create_stack();
	while (i < size)
	{
		if (!(ft_isnumber(input[i])))
		{
			free_stack(&a);
			return (NULL);
		}
		value = ft_atoi(input[i]);
		if (is_duplicate(a, value) || !push(a, create_node(value)))
		{
			free_stack(&a);
			return (NULL);	
		}
		i++;
	}
	return (a);
}