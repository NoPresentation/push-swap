/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_libft.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anashwan <anashwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 17:03:26 by anashwan          #+#    #+#             */
/*   Updated: 2025/12/21 15:32:40 by anashwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_LIBFT_H
# define MINI_LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

int			ft_isdigit(int c);
char		**ft_split(char const *s, char c);
long		ft_atol(const char *nptr);
int			ft_strcmp(const char *s1, const char *s2);
size_t		ft_strlen(const char *s);
void		ft_putstr_fd(char *s, int fd);

#endif
