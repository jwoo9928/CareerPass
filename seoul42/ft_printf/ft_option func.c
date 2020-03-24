/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japark <astro9928@o.cnu.ac.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 20:29:46 by japark            #+#    #+#             */
/*   Updated: 2020/03/14 22:35:56 by japark           ###   ########.fr       */
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

int    ft_option(struct s_option *option, const char *format, int i)
{
    char *op;

    op = check_option(format,i);
    printf("op : %s\n",op);
    if (op == NULL)
        return (0);
    if(op[0] == '0')
        option->flag =  1;
    else
        option->flag = 0;
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


void    printf_option(char *storage, struct s_option *option, int flag)
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
    }
    else
        ft_putstr_fd(storage, 1);
}

void    string_option(const char *format, char *string,int k)
{
    struct s_option option;
    char            *storage;

    reset_option(&option);
    if(ft_option(&option, format, k) == 0)
        return(ft_putstr_fd(string,1));
    if (option.pre_flag == 1 && option.precision == 0)
        return(ft_putstr_fd("",1));
    else if (option.precision != 0)
    {
        storage = (char*)malloc(sizeof(char)*(option.precision + 1));
        ft_strncat(storage,string,option.precision);
    }
    else
        storage = string;
    printf_option(storage, &option,0);
}

void    num_option(const char *format, char *string, int k)
{
struct s_option option;
    char            *storage;
    int             strlen;
    
    strlen = ft_strlen(string);
    reset_option(&option);
    ft_option(&option, format, k);
    if (option.precision <= strlen && option.width == 0)
        return(ft_putstr_fd(string,1));
    else if (option.precision > strlen)
    {
        storage = (char*)malloc(sizeof(char)*(option.precision + 1));
        cal_blank(storage, option.precision - strlen, '0');
        ft_strncat(storage,string,strlen);
    }
    else
        storage = string;
    printf_option(storage, &option,1);
}