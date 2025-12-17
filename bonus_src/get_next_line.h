/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anashwan <anashwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 15:53:05 by anashwan          #+#    #+#             */
/*   Updated: 2025/11/25 21:07:36 by anashwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

char				*get_next_line(int fd);

void				ft_lstadd_back(t_list **lst, t_list *new);
t_list				*ft_lstnew(char *content);
void				*ft_lstclear(t_list **lst, void (*del)(void *),
						char *buffer);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_line_len(t_list **list);

#endif
