/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anashwan <anashwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 10:58:11 by anashwan          #+#    #+#             */
/*   Updated: 2025/12/15 23:49:04 by anashwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	free_split(char **s)
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

static int	is_number(const char *s)
{
	int	i;

	i = 0;
	if (!s || s[i] == '\0')
		return (0);
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

static int	is_duplicate(t_stack *stack, int value)
{
	t_node	*node;

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
	i = size - 1;
	while (i >= 0)
	{
		if (!(is_number(input[i])))
			return (NULL);
		value = ft_atoi(input[i]);
		node = create_node(value);
		if (is_duplicate(a, value) || !node)
			return (NULL);
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
		a = push_input(input_count(argv), argv);
		free_split(argv);
	}
	else
		a = push_input(argc - 1, argv + 1);
	return (a);
}
