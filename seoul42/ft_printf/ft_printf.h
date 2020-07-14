/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewoopark <jaewoopark@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 17:56:09 by japark            #+#    #+#             */
/*   Updated: 2020/07/14 20:54:38 by jaewoopark       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include "libft/libft.h"
#include <stdarg.h>

struct s_option
{
    int minus;
    int flag;
    int width;
    int precision;
    int pre_flag;
} t_option;

int		int_option(const char *format, char *str, int k);
int		count_option(const char *format,int i);
int     ft_printf(const char*format, ...);
void    ft_e_notation(int num, int check);
int     check_type(int num, const char*format, int i);
char    *trand_hex(size_t num, int check);
char	*ft_strncat(char *dest, char *src, int nb);
char    *check_option(const char *format,int i);
int     string_option(const char *format, char *string,int i);
char    *ft_size_t_itoa(size_t n);
int     check_printf(va_list ap, const char *format, int i);
void	cal_blank(char *width,unsigned int cal,char set);
int		point_option(const char *format, char *string, int k);
int		ft_option(struct s_option *option, const char *format, int i);
void	reset_option(struct s_option *option);
int		char_option(const char *format, char c, int k);
int		printf_option(char *storage, struct s_option *option, int flag);
int		ft_putstr_count(char *str, int size);
int		percent_option(const char *format, int k);

void ft_count_putchar(char c, int *size);

#endif