/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japark <astro9928@o.cnu.ac.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 13:12:45 by japark            #+#    #+#             */
/*   Updated: 2020/03/20 17:50:59 by japark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



int    stack_string(char **line, char *g_buffer, int rd, int rd_before)
{
    int nbytes;

    if (g_buffer != NULL)
    {
        if((nbytes = ft_strcheck(g_buffer,'\n')) > 0)
        {
            *line = ft_strndup(g_buffer,0, nbytes);
            g_buffer = ft_strndup(g_buffer, nbytes + 1, BUFF_SIZE);
            return (1);
        }
        *line = ft_sum(line,g_buffer,BUFF_SIZE);
        g_buffer = NULL;
        if (rd < 32)
        {
            *line = ft_strndup(*line,0,rd_before);
            return (1);
        }
        return (-1);
    }
    return (0);
}

void    ch_zero(char **line, char *buf, int nbytes, char *stack)
{
    *line = ft_strndup(buf, 0, nbytes);
    stack = ft_strndup(buf, nbytes + 1, BUFF_SIZE);
}

int     check_buf(char **line, char *buf, int nbytes, char *stack)
{
    *line = ft_sum(line,ft_strndup(buf, 0, nbytes),nbytes);
    stack = ft_strndup(buf, nbytes + 1, BUFF_SIZE);
}

int     get_next_line(int fd, char **line)
{
    char    buf[BUFF_SIZE + 1];
    static int     nbytes;
    int     ch;
    static char *stack;
    static int     rd;
    int     rd_before;

    rd_before = rd - nbytes;
    if (fd < 0 || line == NULL)
        return (-1);
    *line = NULL;
    while (1)
    {
        if ((ch = stack_string(line, stack, rd, rd_before)) == 1)
            return (1);
        if ((rd = read(fd, buf, BUFF_SIZE)) > 0 && (nbytes = ft_strcheck(buf, '\n')) >= 0)
        {
            if (ch == 0)
                ch_zero(line, buf, nbytes, stack);
            else if (ch == -1)
                check_buf(line, buf, nbytes, stack);
            return (1);
        }
        stack = ft_strndup(buf, 0, BUFF_SIZE);
    }
}