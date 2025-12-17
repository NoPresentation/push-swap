/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anashwan <anashwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 10:58:11 by anashwan          #+#    #+#             */
/*   Updated: 2025/12/17 22:13:27 by anashwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	is_number(char **input)
{
	int			i;
	const char	*s;

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
		input++;
	}
	return (1);
}

static int	is_duplicate(char **input)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (input[i])
	{
		j = i + 1;
		while (input[j])
		{
			if (ft_strcmp(input[i], input[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static size_t	input_count(char **input)
{
	size_t	count;

	count = 0;
	while (input[count])
		count++;
	return (count);
}

static t_stack	*push_input(int size, char **input)
{
	int		value;
	int		i;
	t_node	*node;
	t_stack	*a;

	a = create_stack();
	if (!a)
		return (NULL);
	i = size - 1;
	while (i >= 0)
	{
		value = ft_atoi(input[i]);
		node = create_node(value);
		if (!node)
		{
			free_stack(&a);
			return (NULL);
		}
		push(a, node);
		i--;
	}
	return (a);
}

t_stack	*parse_input(int argc, char **argv)
{
	t_stack	*a;

	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (!argv)
			return (NULL);
		if (is_duplicate(argv) || !is_number(argv))
		{
			free_split(argv);
			return (NULL);
		}
		a = push_input(input_count(argv), argv);
		free_split(argv);
	}
	else
	{
		if (is_duplicate(argv + 1) || !is_number(argv + 1))
			return (NULL);
		a = push_input(argc - 1, argv + 1);
	}
	return (a);
}
