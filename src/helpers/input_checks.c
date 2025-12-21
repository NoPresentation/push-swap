/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anashwan <anashwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 18:06:21 by anashwan          #+#    #+#             */
/*   Updated: 2025/12/21 16:31:07 by anashwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_int(char *input)
{
	long	n;

	n = ft_atol(input);
	if (n > INT_MAX || n < INT_MIN)
		return (0);
	return (1);
}

int	is_number(char **input)
{
	int		i;
	char	*s;

	while (*input)
	{
		i = 0;
		s = *input;
		if (s[i] == '-' || s[i] == '+')
			i++;
		if (s[i] == '\0')
			return (0);
		while (s[i])
		{
			if (!ft_isdigit(s[i]))
				return (0);
			i++;
		}
		if (!is_int(s))
			return (0);
		input++;
	}
	return (1);
}

int	is_duplicate(t_stack *a)
{
	t_node	*i;
	t_node	*j;

	i = a->head;
	while (i->next)
	{
		j = i->next;
		while (j)
		{
			if (i->value == j->value)
				return (1);
			j = j->next;
		}
		i = i->next;
	}
	return (0);
}
