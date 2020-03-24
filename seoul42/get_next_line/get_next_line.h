/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japark <astro9928@o.cnu.ac.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 18:13:26 by japark            #+#    #+#             */
/*   Updated: 2020/03/20 17:50:57 by japark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFF_SIZE 32


char    *ft_strndup(char *s, int start, int end);
int     ft_strcheck( char *str, int c);
int     get_next_line(int fd, char **line);
char *ft_sum(char **line, char *src, int nbyte);
char	*ft_strncat(char *dest, char *src, int nb);
size_t  ft_strlen(const char *str);

#endif