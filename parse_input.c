/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anashwan <anashwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 10:58:11 by anashwan          #+#    #+#             */
/*   Updated: 2025/12/03 11:15:22 by anashwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int ft_isnumber(const char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (-1);
		i++;
	}
	return (1);
}


static t_stack *fill_stack(int size, int *elements)
{
	t_stack	*a;
	int		i;

	a = create_stack();
	if (!a)
		return (NULL);
	while (i < size)
	{
		push(a, create_node(elements[i]));
		i++;
	}
	return (a);
}

t_stack	*check_input(int size, char **input)
{
	int			i;
	int			j;
	int			elements[size];
	t_stack		*a;

	i = 1;
	j = 0;
	while (i < size && input[i])
	{
		if (ft_isnumber(input[i]))
		{
			elements[j] = ft_atoi(input[i]);
		}
		else
		{
			ft_printf("ERROR\n");
			return (NULL);
		}
		i++;
	}
	a = fill_stack(size, elements);
	return (a);
}