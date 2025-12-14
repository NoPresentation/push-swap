/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anashwan <anashwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 03:52:10 by anashwan          #+#    #+#             */
/*   Updated: 2025/12/13 23:12:25 by anashwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		max(int x, int y)
{
	if (x >= y)
		return (x);
	return (y);
}

int		min(int x, int y)
{
	if (x <= y)
		return (x);
	return (y);
}

int		abs(int x)
{
	if (x >= 0)
		return (x);
	return (-1 * x);
}