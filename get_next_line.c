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

int	get_next_line(int fd, char **line)
{
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
