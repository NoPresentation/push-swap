/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anashwan <anashwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 18:06:21 by anashwan          #+#    #+#             */
/*   Updated: 2025/12/18 19:22:51 by anashwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_int(char *input)
{
	long	n;
	
	n = atol(input);
	if (n > INT_MAX || n < INT_MIN)
		return (0);
	return (1);
}


int	is_number(char **input)
{
	int			i;
	char	*s;

	while (*input)
	{
		i = 0;
		s = *input;
		if (s[i] == '-' || s[i] == '+')
			i++;
		if (s[i] == '\0')
			return (0);
		if (!is_int(s))
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

int	is_duplicate(char **input)
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