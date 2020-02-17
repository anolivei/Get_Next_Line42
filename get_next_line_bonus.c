/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 20:32:40 by anolivei          #+#    #+#             */
/*   Updated: 2020/02/06 20:32:42 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line_bonus.h"

static int	gnl_end_line(char *s_line)
{
	int i;
	
	i = 0;
	if (s_line == 0)
		return (-1);
	while (s_line[i] != '\0')
	{
		if (s_line[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static int	gnl_return_line(char **s_line, char **line)
{
	int	i;
	char	*tmp;

	tmp = (char *)malloc(ft_strlen(*s_line) + 1);
	i = gnl_end_line(*s_line);
	if (i >= 0)
	{
		*line = ft_substr(*s_line, 0, i);
		tmp = ft_substr(*s_line, i + 1, ft_strlen(*s_line));
		free (*s_line);
		*s_line = tmp;
		tmp = NULL;
		return (1);
	}
	else
		return (0);
}

int	get_next_line(int fd, char **line)
{
	char		*buff;
	ssize_t		ret;
	static char	*s_line[OPEN_MAX];
	int		ret_line;

	if (line == 0 || fd < 0)
		return (-1);
	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (s_line[fd] != NULL)
	{
		ret_line = gnl_return_line(&s_line[fd], line);
		if (ret_line == 1)
			return (1);
	}
	else
		s_line[fd] = ft_strdup("");
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		s_line[fd] = s_line[fd] == NULL ? ft_strdup(buff)
			: ft_strjoin(s_line[fd], buff);
		ret_line = gnl_return_line(&s_line[fd], line);
		if (ret_line == 1)
			return (1);
	}
	*line = ret < 0 ? NULL : s_line[fd];
	s_line[fd] = NULL;
	return (ret);
}
