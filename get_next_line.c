/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aricholm <aricholm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 12:10:27 by aricholm          #+#    #+#             */
/*   Updated: 2021/06/22 16:41:04 by aricholm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_line(char **saved_string)
{
	char	*tmp;
	char	*string;
	size_t	len_output;

	len_output = 0;
	while ((*saved_string)[len_output] != '\n' && (*saved_string)[len_output])
		len_output++;
	string = ft_substr(*saved_string, 0, len_output);
	if (!string)
		return (0);
	tmp = ft_substr(*saved_string, len_output + 1, ft_strlen(*saved_string));
	if (!tmp)
	{
		free (string);
		return (0);
	}
	if (tmp[0] == 0)
	{
		free(tmp);
		tmp = 0;
	}
	free (*saved_string);
	*saved_string = tmp;
	return (string);
}

int	read_fd(int fd, char **saved_string)
{
	int		chars_read;
	char	*buff;
	char	*tmp;
	size_t	len;

	buff = malloc(BUFFER_SIZE * sizeof(char));
	if (!buff)
		return (free_string(buff));
	chars_read = read(fd, buff, BUFFER_SIZE);
	if (chars_read <= 0)
	{	
		free (buff);
		return (chars_read);
	}
	len = ft_strlen(*saved_string);
	tmp = malloc((chars_read + len + 1) * sizeof (char));
	if (!tmp)
		return (-1);
	tmp[len + chars_read] = 0;
	ft_memcpy(tmp, *saved_string, len);
	ft_memcpy(&tmp[len], buff, chars_read);
	free (*saved_string);
	*saved_string = tmp;
	free (buff);
	return (chars_read);
}

t_bool	initialize(char **str)
{
	if (!*str)
	{
		*str = malloc(sizeof (char));
		if (!*str)
			return (FALSE);
		*str[0] = 0;
	}
	return (TRUE);
}

t_bool	has_end_of_line(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (TRUE);
		i++;
	}
	return (FALSE);
}

int	get_next_line(int fd, char **line)
{
	int				chars_read;
	static char		*saved_string;

	if (!line || fd < 0 || BUFFER_SIZE < 1)
		return (-1);
	if (!initialize(&saved_string))
		return (-1);
	chars_read = 1;
	while (!has_end_of_line(saved_string) && chars_read > 0)
	{
		chars_read = read_fd(fd, &saved_string);
		if (chars_read < 0)
			return (free_string(saved_string));
	}
	*line = get_line(&saved_string);
	if (!*line)
		return (free_string(saved_string));
	if (chars_read)
		return (1);
	return (0);
}
