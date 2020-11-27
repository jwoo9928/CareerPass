/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japark <japark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 14:02:00 by jaewoopark        #+#    #+#             */
/*   Updated: 2020/07/09 11:15:57 by japark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	return_output(char **line, char *buf, int size, int flag)
{
	int i;

	i = 0;
	if (size == -1)
		return (-1);
	if ((i = check_line(line, buf, size)) == -1)
		return (-1);
	if (buf[i] == '\n')
		return (shift_buf(buf, i + 1, size, 0));
	if ((!size && **line))
		return (shift_buf(buf, i + 1, size, flag));
	return (2);
}

int	get_next_line(int fd, char **line)
{
	static char	buf[BUFFER_SIZE + 1];
	int			size;
	int			out;
	int			flag;

	if (!line || fd < 0 || !(*line = malloc(sizeof(char))) || BUFFER_SIZE < 1)
		return (-1);
	(*line)[0] = 0;
	size = 1;
	while (size > 0)
	{
		flag = 0;
		if ((size = ft_strlen(buf)) == 0)
		{
			size = read(fd, buf, BUFFER_SIZE);
			flag = 1;
		}
		if ((out = return_output(line, buf, size, flag)) < 2)
			return (out);
	}
	return (0);
}
