/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 15:07:08 by ecantu-p          #+#    #+#             */
/*   Updated: 2026/01/15 12:42:49 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
   Variables:
		BUFFER_SIZE = The specified buffer size to read.
		buff_to_ptr = list structure with the required information
		nl_rd       = return (value from read); number of read characters.
		buff_rd     = pointer to the read characters.
		str_to_prt  = pointer to the string to print.
		dlm         = new line delimiter.
		next        = a list next node.

*/

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_list
{
	int				fd;
	int				len_rd;
	char			dlm;
	char			*buff_rd;
	char			*ovf;
	char			*str;
	struct s_list	*next;
}					t_str_prt;

void		*ft_calloc(size_t nmemb, size_t size);
char		*ft_strdup(const char *s);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		ft_lstdelone(t_str_prt *lst);
char		*ft_strjoin(char *s1, char const *s2);
t_str_prt	*ft_gnl_lstnew(void *content, const char dlm);
t_str_prt	*ft_gnl(t_str_prt *ls_gnl, size_t i, size_t j, int loop);
char		*get_next_line(int fd);
#endif