/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anashwan <anashwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 03:52:10 by anashwan          #+#    #+#             */
/*   Updated: 2025/12/17 22:09:40 by anashwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	max(int x, int y)
{
	if (x >= y)
		return (x);
	return (y);
}

int	min(int x, int y)
{
	if (x <= y)
		return (x);
	return (y);
}

int	abs(int x)
{
	if (x >= 0)
		return (x);
	return (-1 * x);
}

int	is_sorted(t_stack *a)
{
	t_node	*node;

	node = a->head;
	while (node->next)
	{
		if (node->value > node->next->value)
			return (0);
		node = node->next;
	}
	return (1);
}

void	free_split(char **s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	s = NULL;
}
