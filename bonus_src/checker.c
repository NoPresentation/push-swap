/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anashwan <anashwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 11:41:51 by anashwan          #+#    #+#             */
/*   Updated: 2025/12/23 21:29:53 by anashwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_libft/mini_libft.h"
#include "../src/push_swap.h"
#include "get_next_line.h"

static void	do_swap(const char *move, t_stack *a, t_stack *b)
{
	if (ft_strcmp(move, "sa\n") == 0)
		swap(a, '-');
	else if (ft_strcmp(move, "sb\n") == 0)
		swap(b, '-');
	else if (ft_strcmp(move, "ss\n") == 0)
	{
		swap(a, '-');
		swap(b, '-');
	}
}

static void	do_rotate(const char *move, t_stack *a, t_stack *b)
{
	if (ft_strcmp(move, "ra\n") == 0)
		rotate(a, '-');
	else if (ft_strcmp(move, "rb\n") == 0)
		rotate(b, '-');
	else if (ft_strcmp(move, "rr\n") == 0)
	{
		rotate(a, '-');
		rotate(b, '-');
	}
	else if (ft_strcmp(move, "rra\n") == 0)
		rev_rotate(a, '-');
	else if (ft_strcmp(move, "rrb\n") == 0)
		rev_rotate(b, '-');
	else if (ft_strcmp(move, "rrr\n") == 0)
	{
		rev_rotate(a, '-');
		rev_rotate(b, '-');
	}
}

int	excute_moves(const char *move, t_stack *a, t_stack *b)
{
	if (ft_strcmp(move, "pa\n") == 0)
		pa(a, b, '-');
	else if (ft_strcmp(move, "pb\n") == 0)
		pb(a, b, '-');
	else if (ft_strcmp(move, "sa\n") == 0 || ft_strcmp(move, "sb\n") == 0
		|| ft_strcmp(move, "ss\n") == 0)
		do_swap(move, a, b);
	else if (ft_strcmp(move, "ra\n") == 0 || ft_strcmp(move, "rb\n") == 0
		|| ft_strcmp(move, "rr\n") == 0)
		do_rotate(move, a, b);
	else if (ft_strcmp(move, "rra\n") == 0 || ft_strcmp(move, "rrb\n") == 0
		|| ft_strcmp(move, "rrr\n") == 0)
		do_rotate(move, a, b);
	else
		return (0);
	return (1);
}

static int	read_moves(t_stack *a, t_stack *b)
{
	char	*move;
	int		x;

	move = get_next_line(0);
	while (move)
	{
		x = excute_moves(move, a, b);
		if (!x)
		{
			ft_putstr_fd("Error\n", 2);
			free(move);
			free_stack(&a);
			free_stack(&b);
			return (0);
		}
		free(move);
		move = get_next_line(0);
	}
	free(move);
	return (1);
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
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (!read_moves(a, b))
		return (0);
	if (is_sorted(a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(&a);
	free_stack(&b);
	return (0);
}
