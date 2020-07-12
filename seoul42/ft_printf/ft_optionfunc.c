/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optionfunc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewoopark <jaewoopark@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 22:28:29 by japark            #+#    #+#             */
/*   Updated: 2020/07/12 19:04:13 by jaewoopark       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    cal_blank(char *width,unsigned int cal,char set)
{
    int i;

    i = -1;
    while(++i < (int)cal)
        width[i] = set;
    width[i] = '\0';
}

void    point_option(const char *format, char *string, int k)
{
    struct s_option option;
    char            *storage;
    int             strlen;

    strlen = ft_strlen(string);
    reset_option(&option);
    ft_option(&option, format, k);
    if (option.width > strlen && option.minus == 0)
    {
        storage = (char*)malloc(sizeof(char)*(option.width + 1));
        cal_blank(storage, option.width - strlen, ' ');
        storage[option.width - strlen - 1] = 'x';
        storage[option.width - strlen - 2] = '0';
        ft_strncat(storage,string,strlen);
        ft_putstr_fd(storage,1);
    }
    else
    {
        ft_putstr_fd("0x",1);
        ft_putstr_fd(string,1);
    }
}

void    char_option(const char *format, char c, int k) {

    struct s_option option;
    char            storage[2];

    reset_option(&option);
    if (ft_option(&option, format, k) == 0)
        ft_putchar_fd(c,1);
	else
	{
		storage[0] = c;
		printf_option(storage, &option,0);
	}
}

void    string_option(const char *format, char *string,int k)
{
    struct s_option option;
    char            *storage;

    reset_option(&option);
    if(ft_option(&option, format, k) == 0)
        return(ft_putstr_fd(string,1));
    if (option.pre_flag == 1 && option.precision == 0)//option only has "."
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

void	int_option(const char *format, char *str, int k)
{
	struct s_option option;
	int				len;
    char            *temp;

    len = ft_strlen(str);
    reset_option(&option);
    if(ft_option(&option, format, k) == 0 || (option.precision <= len && option.width <= len))
        ft_putstr_fd(str, 1);
	else
	{
        temp = (char*)malloc(sizeof(char)*(option.precision + 1));
        cal_blank(temp, option.precision - len, '0');
        temp  = ft_strjoin(temp, str);
        printf_option(temp, &option, 1);
	}
	
}