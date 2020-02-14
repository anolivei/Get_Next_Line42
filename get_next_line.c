/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 20:32:20 by anolivei          #+#    #+#             */
/*   Updated: 2020/02/13 23:03:45 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char    *ft_strjoin(char const *s1, char const *s2)
{
    char        *string;
    size_t      i;
    size_t      j;

    if (s1 == 0 || s2 == 0)
        return (0);
    i = 0;
    string = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(*string));
    if (string == 0)
        return (0);
    while (s1[i] != '\0')
    {
        string[i] = s1[i];
        i++;
    }
    j = 0;
    while (s2[j] != '\0')
    {
        string[i] = s2[j];
        i++;
        j++;
    }
    string[i] = '\0';
    return (string);
}

static char    *ft_strdup(const char *s1)
{
    char    *cpy;
    int     len;

    len = ft_strlen(s1) + 1;
    if ((cpy = ((char *)malloc(sizeof(char) * len))) != 0)
    {
        ft_strlcpy(cpy, s1, len);
        return (cpy);
    }
    return (0);
}

int	get_next_line(int fd, char **line)
{
	static char *stack[OPEN_MAX];
	char *buf;
	ssize_t control_read;

	if (line == 0 || fd < 0)
		return (-1);
	buf = malloc(BUFFER_SIZE + 1);
	
	control_read = 1;
	while (control_read > 0)
	{
		control_read = read(fd, buf, BUFFER_SIZE);
		buf[control_read] = '\0';



	}

}
