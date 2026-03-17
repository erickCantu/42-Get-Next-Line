/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 15:06:51 by ecantu-p          #+#    #+#             */
/*   Updated: 2026/01/15 12:40:19 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			i;
	unsigned char	*ptr;

	if (nmemb > 4294967295 || (nmemb * size) > 4294967295)
		return (NULL);
	if (nmemb == 0 || size == 0)
		return (NULL);
	ptr = (void *) malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < (nmemb * size))
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		len_str;
	int		i;

	len_str = 0;
	while (s[len_str])
		len_str++;
	dup = (char *) ft_calloc((len_str + 1), sizeof(char));
	if (!dup)
		return (NULL);
	i = 0;
	while (i <= len_str)
	{
		dup[i] = 0;
		i++;
	}
	i = 0;
	while (i < len_str)
	{
		dup[i] = s[i];
		i++;
	}
	return (dup);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*dest_cpy;
	unsigned char	*src_cpy;

	if (!dest && !src)
		return (NULL);
	i = 0;
	src_cpy = (unsigned char *)src;
	dest_cpy = (unsigned char *)dest;
	while (i < n)
	{
		dest_cpy[i] = src_cpy[i];
		i++;
	}
	return (dest);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*s1_join_s2;
	int		len_s1;
	int		len_s2;

	if (s1 == NULL || s2 == NULL)
	{
		return (NULL);
	}
	len_s1 = 0;
	len_s2 = 0;
	while (s1[len_s1])
		len_s1++;
	while (s2[len_s2])
		len_s2++;
	s1_join_s2 = (char *)ft_calloc((len_s1 + len_s2 + 1), sizeof(char));
	if (!s1_join_s2)
		return (NULL);
	ft_memcpy(s1_join_s2, s1, len_s1);
	free (s1);
	s1 = NULL;
	ft_memcpy((s1_join_s2 + ((int)len_s1)), s2, len_s2);
	s1_join_s2[(int)(len_s1 + len_s2)] = '\0';
	return (s1_join_s2);
}
