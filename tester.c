/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meow.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anashwan <anashwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 18:17:25 by anashwan          #+#    #+#             */
/*   Updated: 2025/12/04 19:10:52 by anashwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static void	dispatch_op(t_stack *a, t_stack *b, char *op)
{
	// Push
	if (!strcmp(op, "pa")) pa(a, b);
	else if (!strcmp(op, "pb")) pb(a, b);

	// Swap
	else if (!strcmp(op, "sa")) sa(a);
	else if (!strcmp(op, "sb")) sb(b);
	else if (!strcmp(op, "ss")) ss(a, b);

	// Rotate
	else if (!strcmp(op, "ra")) ra(a);
	else if (!strcmp(op, "rb")) rb(b);
	else if (!strcmp(op, "rr")) rr(a, b);

	// Reverse rotate
	else if (!strcmp(op, "rra")) rra(a);
	else if (!strcmp(op, "rrb")) rrb(b);
	else if (!strcmp(op, "rrr")) rrr(a, b);

	else
		ft_printf("Unknown operation: %s\n", op);
}

void	test(t_stack *a, t_stack *b)
{
	char	*line = NULL;
	size_t	size = 0;

	ft_printf("Push_swap interactive mode.\n");
	ft_printf("Type operations (sa, pb, rra, ...). Type 'exit' to quit.\n\n");

	while (1)
	{
		ft_printf("> ");
		if (getline(&line, &size, stdin) == -1)
			break;

		// Remove trailing newline
		line[strcspn(line, "\n")] = '\0';

		if (strcmp(line, "exit") == 0)
			break;

		dispatch_op(a, b, line);
		print_ab(a, b);
		ft_printf("\n");
	}
	free(line);
}

