/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aricholm <aricholm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 12:10:32 by aricholm          #+#    #+#             */
/*   Updated: 2021/06/22 19:14:09 by aricholm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	free_string(char **arr, char *string)
{
	size_t	i;

	i = 0;
	while (i < FD_MAX)
	{
		if (arr[i])
			free (arr[i]);
		i++;
	}
	if (string)
		free (string);
	return (-1);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len] != 0)
		len++;
	return (len);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*ptr;
	char	*ptr2;

	if (!dest && !src && n)
		return (0);
	i = 0;
	ptr = dest;
	ptr2 = (void *)src;
	while (i < n)
	{
		ptr[i] = ptr2[i];
		i++;
	}
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*src;
	char	*dst;

	if (!s)
		return (ft_strdup(""));
	i = 0;
	src = (void *)s;
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	dst = malloc(len + 1);
	if (!dst)
		return (0);
	while (i < len)
	{
		dst[i] = src[start + i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

char	*ft_strdup(const char *s)
{
	char	*ptr;
	char	*src;
	size_t	i;

	i = 0;
	src = (void *)s;
	ptr = malloc(ft_strlen(src) + 1);
	if (!ptr)
		return (0);
	while (src[i] != 0)
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}
