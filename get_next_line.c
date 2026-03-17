/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 12:31:08 by ecantu-p          #+#    #+#             */
/*   Updated: 2026/01/15 12:39:58 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function structure
	- Function Name: get_next_line.c
	- Description: Write a function that returns a line read from a
					file descriptor.
	- Prototype as: char *get_next_line(int fd);
	- Parameters: fd: the file descriptor to read from.
	- Return value:
		| Read Line: | correct behavior |
		| NULL: | there is nothing else to read, or an error occurred. |
*/

#include "get_next_line.h"

void	ft_lstdelone(t_str_prt *lst)
{
	free(lst->buff_rd);
	lst->buff_rd = NULL;
	free(lst->ovf);
	lst->ovf = NULL;
	free(lst->str);
	lst->str = NULL;
	free(lst);
	lst = NULL;
}

t_str_prt	*ft_gnl_lstnew(void *content, const char dlm)
{
	t_str_prt	*ls_gnl;

	ls_gnl = (t_str_prt *)malloc(sizeof(t_str_prt));
	if (!ls_gnl)
		return (NULL);
	ls_gnl->fd = *((int *) content);
	ls_gnl->len_rd = 0;
	ls_gnl->dlm = dlm;
	ls_gnl->buff_rd = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!ls_gnl->buff_rd)
		return (NULL);
	ls_gnl->ovf = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!ls_gnl->ovf)
		return (NULL);
	ls_gnl->str = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!ls_gnl->str)
		return (NULL);
	ls_gnl->next = NULL;
	return (ls_gnl);
}

t_str_prt	*ft_gnl(t_str_prt *ls_gnl, size_t i, size_t j, int loop)
{
	ls_gnl->buff_rd[ls_gnl->len_rd] = 0;
	ls_gnl->str = ft_strjoin(ls_gnl->str, ls_gnl->buff_rd);
	while (loop)
	{
		while (ls_gnl->str[i])
			i++;
		while ((ls_gnl->str[j]) && (ls_gnl->str[j] != ls_gnl->dlm))
			j++;
		if (i != j)
		{
			ls_gnl->ovf = ft_strjoin(ls_gnl->ovf, ls_gnl->str);
			ls_gnl->str[j + 1] = 0;
			ft_memcpy(ls_gnl->ovf, ls_gnl->ovf + j + 1, i - j);
			ls_gnl->ovf[i - j] = 0;
			return (ls_gnl);
		}
		ls_gnl->len_rd = read(ls_gnl->fd, ls_gnl->buff_rd, BUFFER_SIZE);
		if (ls_gnl->len_rd != BUFFER_SIZE)
			ls_gnl->buff_rd[ls_gnl->len_rd] = 0;
		if (ls_gnl->len_rd <= 0)
			return (ls_gnl);
		ls_gnl->str = ft_strjoin(ls_gnl->str, ls_gnl->buff_rd);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	char				*str_rsp;
	static t_str_prt	*ls_gnl;

	if (fd < 0)
		return (NULL);
	if (!ls_gnl)
	{
		ls_gnl = ft_gnl_lstnew(&fd, '\n');
		if (!ls_gnl)
			return (NULL);
	}
	ls_gnl->str[0] = 0;
	ls_gnl->buff_rd[0] = 0;
	ls_gnl->str = ft_strjoin(ls_gnl->str, ls_gnl->ovf);
	ls_gnl->ovf[0] = 0;
	ls_gnl->len_rd = read(fd, ls_gnl->buff_rd, BUFFER_SIZE);
	if (ls_gnl->len_rd < 0 || ((ls_gnl->len_rd == 0) && ls_gnl->str[0] == 0))
	{
		ft_lstdelone(ls_gnl);
		ls_gnl = NULL;
		return (NULL);
	}
	ls_gnl = ft_gnl(ls_gnl, 0, 0, 1);
	str_rsp = ft_strdup(ls_gnl->str);
	return (str_rsp);
}
/*
int	main(void)
{
	int		fd[4];
	char	*gln;

	fd[0] = open("files/41_with_nl", O_RDWR);
	gln = get_next_line(1000);
	printf("%s", gln);
	free(gln);
	gln = NULL;
	gln = get_next_line(fd[0]);
	printf("%s", gln);
	free(gln);
	gln = NULL;

	fd[1] = open("files/42_with_nl", O_RDWR);
	gln = get_next_line(1001);
	printf("%s", gln);
	free(gln);
	gln = NULL;
	gln = get_next_line(fd[1]);
	printf("%s", gln);
	free(gln);
	gln = NULL;

	fd[2] = open("files/43_with_nl", O_RDWR);
	gln = get_next_line(1002);
	printf("%s", gln);
	free(gln);
	gln = NULL;
	gln = get_next_line(fd[2]);
	printf("%s", gln);
	free(gln);
	gln = NULL;
	
	gln = get_next_line(1003);
	printf("%s", gln);
	free(gln);
	gln = NULL;
	gln = get_next_line(fd[0]);
	printf("%s", gln);
	free(gln);
	gln = NULL;
	
	gln = get_next_line(1004);
	printf("%s", gln);
	free(gln);
	gln = NULL;
	gln = get_next_line(fd[1]);
	printf("%s", gln);
	free(gln);
	gln = NULL;

	gln = get_next_line(1005);
	printf("%s", gln);
	free(gln);
	gln = NULL;
	gln = get_next_line(fd[2]);
	printf("%s", gln);
	free(gln);
	gln = NULL;

	gln = get_next_line(fd[0]);
	printf("%s", gln);
	free(gln);
	gln = NULL;
	gln = get_next_line(fd[1]);
	printf("%s", gln);
	free(gln);
	gln = NULL;
	gln = get_next_line(fd[2]);
	printf("%s", gln);
	free(gln);
	gln = NULL;
	

	fd[3] = open("files/nl", O_RDWR);
	gln = get_next_line(1006);
	printf("%s", gln);
	free(gln);
	gln = NULL;
	gln = get_next_line(fd[3]);
	printf("%s", gln);
	free(gln);
	gln = NULL;
	gln = get_next_line(1007);
	printf("%s", gln);
	free(gln);
	gln = NULL;
	gln = get_next_line(fd[3]);
	printf("%s", gln);
	free(gln);
	gln = NULL;	
	return (0);
}

*/
// int	main(void)
// {
// 	int		fd;
// 	char	*gln;
//
// 	fd = open("files/multiple_line_no_nl", O_RDONLY);
// 	if (fd == -1)
// 		return (1);
// 	gln = get_next_line(fd);
// 	printf("%s", gln); //"01234567890123456789012345678901234567890\n"
// 	free(gln);
// 	gln = NULL;
// 	gln = get_next_line(fd);
// 	printf("%s", gln); //"987654321098765432109876543210987654321098\n"
// 	free(gln);
// 	gln = NULL;
// 	gln = get_next_line(fd);
// 	printf("%s", gln); //"0123456789012345678901234567890123456789012\n"
// 	free(gln);
// 	gln = NULL;
// 	gln = get_next_line(fd);
// 	printf("%s", gln); //"987654321098765432109876543210987654321098\n"
// 	free(gln);
// 	gln = NULL;
// 	gln = get_next_line(fd);
// 	printf("%s", gln); //"01234567890123456789012345678901234567890"
// 	free(gln);
// 	gln = NULL;
// 	gln = get_next_line(fd);
// 	printf("%s", gln); //NULL
// 	free(gln);
// 	gln = NULL;
// 	close (fd);
// 	return (0);
// }
//
//
// int		main(void)
// {
// 	int		fd;
// 	char	*gln;
//
// 	fd = open("files/empty", O_RDONLY);
// 	if (fd == -1)
// 		return (1);
// 	gln = get_next_line(1000);
// 	printf("%s", gln);
// 	free(gln);
// 	gln = NULL;
// 	gln = get_next_line(-1);
// 	printf("%s", gln);
// 	free(gln);
// 	gln = NULL;
// 	close (fd);
// 	gln = get_next_line(fd);
// 	printf("%s", gln);
// 	free(gln);
// 	gln = NULL;
// 	return(0);
// }
//
// int		main(void)
// {
// 	int		fd;
// 	char	*gln;
//
// 	fd = open("files/41_with_nl", O_RDONLY);
// 	if (fd == -1)
// 		return (1);
// 	gln = get_next_line(fd);
// 	printf("%s", gln); //"0123456789012345678901234567890123456789\n"
// 	free(gln);
// 	gln = NULL;
// 	gln = get_next_line(fd);
// 	printf("%s", gln); //"0"
// 	free(gln);
// 	gln = NULL;
// 	close (fd);
// 	gln = get_next_line(fd);
// 	printf("%s", gln); // NULL
// 	free(gln);
// 	gln = NULL;
// 	return(0);
// }
//
// int		main(void)
// {
// 	int		fd;
// 	char	*gln;
//
// 	fd = open("fsoares/read_error.txt", O_RDONLY);
// 	if (fd == -1)
// 		return(1);
// 	gln	= get_next_line(fd);
// 	printf("%s", gln); //"aaaaaaaaaa\n"
// 	gln = NULL;
// 	gln	= get_next_line(fd);
// 	printf("%s", gln); //"bbbbbbbbbb\n"
// 	gln = NULL;
// 	gln = get_next_line (-1);
// 	printf("%s", gln); //NULL
// 	close(fd);
// 	fd = open("fsoares/read_error.txt", O_RDONLY);
// 	if (fd == -1)
// 		return(1);
// 	gln	= get_next_line(fd);
// 	printf("%s", gln); //"aaaaaaaaaa\n"
// 	gln = NULL;
// 	gln	= get_next_line(fd);
// 	printf("%s", gln); //"bbbbbbbbbb\n"
// 	gln = NULL;
// 	gln	= get_next_line(fd);
// 	printf("%s", gln); //"cccccccccc\n"
// 	gln = NULL;
// 	gln	= get_next_line(fd);
// 	printf("%s", gln); //"dddddddddd\n"
// 	gln = NULL;
// 	gln	= get_next_line(fd);
// 	printf("%s", gln); //NULL
// 	free(gln);
// 	gln = NULL;
// 	close(fd);
// 	return(0);
// }
//
// int		main(void)
// {
// 	int		fd;
// 	char	*gnl;
//
// 	gnl = get_next_line (-1); //NULL
// 	printf ("%s", gnl); 
// 	gnl = NULL;
// 	gnl = get_next_line (100); //NULL
// 	printf("%s", gnl);
// 	gnl = NULL;
// 	fd = open("fsoares/emtpy.tx", O_RDONLY);
// 	close (fd);
// 	gnl = get_next_line (fd); //NULL
// 	printf("%s", gnl);
// 	free(gnl);
// 	gnl = NULL;
// 	return (0);
// }
//
// int	main(void)
// {
// 	int		fd;
// 	char	*gnl;
// 	fd = open("fsoares/empty.txt", O_RDONLY);
// 	gnl = get_next_line (fd); //NULL
// 	printf("%s", gnl);
// 	free(gnl);
// 	gnl = NULL;
// 	gnl = get_next_line (fd); //NULL
// 	printf("%s", gnl);
// 	free(gnl);
// 	gnl = NULL;
// 	close (fd);
// 	return (0);
// }