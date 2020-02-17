/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 20:32:20 by anolivei          #+#    #+#             */
/*   Updated: 2020/02/09 21:54:44 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	gnl_del(char **s)
{
	free(*s);
	*s = NULL;
}

static int	gnl_ret(ssize_t r_read, char **rest, int fd, char **line)
{
	int  i;
	char *tmp;

	i = 0;
	if (r_read < 0)
		return (-1);
	else if (r_read == 0 && rest[fd] == NULL &&
		(*line = (char *)ft_calloc(1, 1)) != 0)
		return (0);
	while (rest[fd][i] != '\n' && rest[fd][i] != '\0')
		i++;
	if (rest[fd][i] == '\n')
	{
		*line = ft_substr(rest[fd], 0, i);
		tmp = ft_strdup(&(rest[fd][i + 1]));
		free(rest[fd]);
		rest[fd] = tmp;
		if (rest[fd][0] == '\0')
			gnl_del(&rest[fd]);
		return (1);
	}
	*line = ft_strdup(rest[fd]);
	gnl_del(&rest[fd]);
	return(0);
}

static int	gnl_end_line(char *buff)
{
	int i;

	i = 0;
	while (buff[i] != '\0')
	{
		if (buff[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char		*buff;
	ssize_t		r_read;
	static char	*rest[OPEN_MAX];
	char		*tmp;
	int		end;

	if (line == 0 || fd < 0)
		return (-1);
	buff = (char *)malloc(BUFFER_SIZE + 1);
	while ((r_read = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[r_read] = '\0';
		if (rest[fd] == 0)
			rest[fd] = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(rest[fd], buff);
			free(rest[fd]);
			rest[fd] = tmp;
		}
		if ((end = gnl_end_line(buff)) > 0)
			break ;
	}
	free(buff);
	return (gnl_ret(r_read, rest, fd, line));
}
