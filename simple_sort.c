/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anashwan <anashwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 19:31:11 by anashwan          #+#    #+#             */
/*   Updated: 2025/12/14 14:09:25 by anashwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *a)
{
    int x = a->head->value;
    int y = a->head->next->value;
    int z = a->tail->value;

    if (a->size == 2)
    {
        swap(a, 'a');
        return ;
    }
    if (x > y && y < z && x > z)
        rotate(a, 'c');
    else if (x < y && y > z && x > z)
        rev_rotate(a, 'a');
    else if (x > y && y > z)
    {
        swap(a, 'a');
        rev_rotate(a, 'a');
    }
    else if (x > y && y < z && x < z)
        swap(a, 'a');
    else if (x < y && y > z && x < z)
    {
        swap(a, 'a');
        rotate(a, 'a');
    }
}