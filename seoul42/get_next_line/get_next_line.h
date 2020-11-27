/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japark <japark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 18:13:26 by japark            #+#    #+#             */
/*   Updated: 2020/07/09 11:16:08 by japark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

int					ft_strlen(const char *str);
int					shift_buf(char *buf, int i, int size, int flag);
int					check_line(char **line, char *buf, int size);
int					get_next_line(int fd, char **line);

#endif
