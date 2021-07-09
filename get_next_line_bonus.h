/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aricholm <aricholm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:29:39 by aricholm          #+#    #+#             */
/*   Updated: 2021/06/22 18:49:38 by aricholm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>

# define FD_MAX 4096

typedef struct s_list
{
	int				fd;
	char			*content;
	struct s_list	*next;
}	t_list;

typedef enum e_bool{FALSE, TRUE}	t_bool;

int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
int		free_string(char **arr, char *string);
char	*get_line(char **saved_string);
int		read_fd(int fd, char **saved_string);
t_bool	initialize(char **str);
t_bool	has_end_of_line(const char *str);

#endif
