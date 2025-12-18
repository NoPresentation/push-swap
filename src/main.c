/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anashwan <anashwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 22:11:26 by anashwan          #+#    #+#             */
/*   Updated: 2025/12/18 17:44:15 by anashwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	a = parse_input(argc, argv);
	b = create_stack();
	if (!a || !b)
	{
		free_stack(&a);
		free_stack(&b);
		ft_printf("Error\n"); // print to stderror u idiot
		return (0);
	}
	if (!is_sorted(a))
		push_swap(a, b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
