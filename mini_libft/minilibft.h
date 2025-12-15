/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anashwan <anashwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 17:03:26 by anashwan          #+#    #+#             */
/*   Updated: 2025/12/15 23:38:50 by anashwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILIBFT_H
# define MINILIBFT_H

# include <stdlib.h>
# include <unistd.h>

int			ft_isdigit(int c);
char		**ft_split(char const *s, char c);
int			ft_atoi(const char *nptr);

#endif
