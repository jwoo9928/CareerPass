/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewoopark <jaewoopark@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 12:26:51 by japark            #+#    #+#             */
/*   Updated: 2020/07/09 17:45:18 by jaewoopark       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*str_sums(char *temp, char *line, char *buf, int i)
{
	char	*tmp;

	tmp = temp;
	while (*line)
		*temp++ = *line++;
	*temp = '\0';
	while (*buf && i--)
		*temp++ = *buf++;
	*temp = 0;
	return (tmp);
}

int			ft_strlen(const char *str)
{
	size_t			res;

	res = 0;
	while (*str)
	{
		if (!(*(str + 1)))
			return (res + 1);
		if (!(*(str + 2)))
			return (res + 2);
		if (!(*(str + 3)))
			return (res + 3);
		if (!(*(str + 4)))
			return (res + 4);
		if (!(*(str + 5)))
			return (res + 5);
		if (!(*(str + 6)))
			return (res + 6);
		if (!(*(str + 7)))
			return (res + 7);
		res += 8;
		str += 8;
	}
	return (res);
}

int			shift_buf(char *buf, int i, int size, int flag)
{
	int count;

	count = 0;
	buf[i - 1] = 0;
	while (i + count < BUFFER_SIZE + 0 && (buf[i + count]))
	{
		buf[count] = buf[i + count];
		buf[i + count] = 0;
		++count;
	}
	if (flag && !*buf)
		return (size == BUFFER_SIZE ? 1 : 0);
	return (1);
}

int			check_line(char **line, char *buf, int size)
{
	int		i;
	int		cont;
	char	*temp;

	i = 0;
	while (i < size)
		if (buf[i] != '\n' && buf[i] != '\0')
			i++;
		else
			break ;
	cont = ft_strlen(*line) + 1;
	if (!(temp = malloc((cont + i) * sizeof(char))))
		return (-1);
	str_sums(temp, *line, buf, i);
	free(*line);
	*line = temp;
	cont = i;
	while (cont--)
		*buf++ = 0;
	return (i);
}
