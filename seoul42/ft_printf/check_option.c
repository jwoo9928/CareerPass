/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewoopark <jaewoopark@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 20:29:46 by japark            #+#    #+#             */
/*   Updated: 2020/07/14 16:34:49 by jaewoopark       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void    reset_option(struct s_option *option)
{
    option->flag = 0;
    option->pre_flag = 0;
    option->precision = 0;
    option->width = 0;
    option->minus = 0;
}

int     count_option(const char *format,int i)
{
    int count;

    count = 0;
    while(format[--i] != '%')
        count++;
    return (count);
}

char    *check_option(const char *format, int i)
{
    char *option;
    int op_len;

    op_len =  count_option(format, i);
    if (op_len == 0)
        return(NULL);
    option = (char*)malloc((op_len+1)*sizeof(char));
    option[op_len] = '\0';
    while(*(format - (--i)) != '%' && op_len > 0)
        option[--op_len] = format[i];
    return (option);
}

int    ft_option(struct s_option *option, const char *format, int i)
{
    char *op;

    op = check_option(format,i);
    if (op == NULL)
        return (0);
    option->flag =  (op[0] == '0' ? 1 : 0);
    while(*op != '\0')
    {
        if (*op == '-')
            option->minus = 1;
        if (*op == '.')
        {
            option->pre_flag = 1;
            op++;
        }
        if (option->pre_flag != 1 && *op >= '0' && *op <= '9')
            option->width = option->width * 10 + (*op - '0');
        if(option->pre_flag == 1 && *op >= '0' && *op <= '9')
            option->precision = option->precision *10 + (*op - '0');
        op++;
    }
    return (1);
}


int    printf_option(char *storage, struct s_option *option, int flag)
{
    char *width;

    if (option->width != 0 && option->width > (int)ft_strlen(storage) && option->minus == 0)
    {
        width = (char*)malloc(sizeof(char)*(option->width +1));
        if (flag == 0)
            cal_blank(width, option->width - ft_strlen(storage),' ');
        else
        {
            if (option->flag == 1)
                cal_blank(width, option->width - ft_strlen(storage),'0');
            else
                cal_blank(width, option->width - ft_strlen(storage),' ');
        }
        ft_strncat(width, storage,ft_strlen(storage));
        ft_putstr_fd(width, 1);
        return(ft_strlen(width));
    }
    else
        return(ft_putstr_count(storage, option->width - ft_strlen(storage)));
}