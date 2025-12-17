/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anashwan <anashwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 11:41:51 by anashwan          #+#    #+#             */
/*   Updated: 2025/12/17 10:23:24 by anashwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_libft/mini_libft.h"
#include "../src/push_swap.h"
#include "get_next_line.h"

static void	do_swap(const char *move, t_stack *a, t_stack *b)
{
	if (ft_strcmp(move, "sa") == 0)
		swap(a, '-');
	else if (ft_strcmp(move, "sb") == 0)
		swap(b, '-');
	else if (ft_strcmp(move, "ss") == 0)
	{
		swap(a, '-');
		swap(b, '-');
	}
}

static void	do_rotate(const char *move, t_stack *a, t_stack *b)
{
	if (ft_strcmp(move, "ra") == 0)
		rotate(a, '-');
	else if (ft_strcmp(move, "rb") == 0)
		rotate(b, '-');
	else if (ft_strcmp(move, "rr") == 0)
	{
		rotate(a, '-');
		rotate(b, '-');
	}
	else if (ft_strcmp(move, "rra") == 0)
		rev_rotate(a, '-');
	else if (ft_strcmp(move, "rrb") == 0)
		rev_rotate(b, '-');
	else if (ft_strcmp(move, "rrr") == 0)
	{
		rev_rotate(a, '-');
		rev_rotate(b, '-');
	}
}

int	excute_moves(const char *move, t_stack *a, t_stack *b)
{
	if (ft_strcmp(move, "pa") == 0)
		pa(a, b, '-');
	else if (ft_strcmp(move, "pb") == 0)
		pb(a, b, '-');
	else if (ft_strcmp(move, "sa") == 0 || ft_strcmp(move, "sb") == 0
		|| ft_strcmp(move, "ss") == 0)
		do_swap(move, a, b);
	else if (ft_strcmp(move, "ra") == 0 || ft_strcmp(move, "rb") == 0
		|| ft_strcmp(move, "rr") == 0)
		do_rotate(move, a, b);
	else if (ft_strcmp(move, "rra") == 0 || ft_strcmp(move, "rrb") == 0
		|| ft_strcmp(move, "rrr") == 0)
		do_rotate(move, a, b);
	else
		return (0);
	return (1);
}

static void	read_moves(t_stack *a, t_stack *b)
{
	char	*move;
	int		x;

	move = get_next_line(0);
	while (move)
	{
		x = excute_moves(move, a, b);
		if (!x)
		{
			ft_printf("Error\n");
			free(move);
			return ;
		}
		move = get_next_line(0);
	}
	free(move);
}

int	main(int argc, char *argv[])
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
		ft_printf("Error\n");
		return (0);
	}
	read_moves(a, b);
	if (is_sorted(a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(&a);
	free_stack(&b);
	return (0);
}
