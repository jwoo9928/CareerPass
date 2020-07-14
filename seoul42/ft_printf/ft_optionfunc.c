/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optionfunc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewoopark <jaewoopark@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 22:28:29 by japark            #+#    #+#             */
/*   Updated: 2020/07/14 17:52:16 by jaewoopark       ###   ########.fr       */
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

int    point_option(const char *format, char *string, int k)
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
        return (ft_putstr_count(storage, 0));
    }
    else
    {
        ft_putstr_fd("0x",1);
        return (ft_putstr_count(string, option.width - ft_strlen(string) - 2) + 2);
    }
}

int    char_option(const char *format, char c, int k) {

    struct s_option option;
    char            storage[2];

    reset_option(&option);
    if (ft_option(&option, format, k) == 0)
    {
        ft_putchar_fd(c,1);
        return (1);
    }
	else
	{
		storage[0] = c;
		return(printf_option(storage, &option,0));
	}
}

int    string_option(const char *format, char *string,int k)
{
    struct s_option option;
    char            *storage;

    if (string == NULL)
        string = "(null)";
    reset_option(&option);
    if(ft_option(&option, format, k) == 0)
        return(ft_putstr_count(string, 0));
    if (option.pre_flag == 1 && option.precision == 0 && option.width == 0)//option only has "."
        return(ft_putstr_count("", 0));
    else if (option.precision != 0)
    {
        storage = (char*)malloc(sizeof(char)*(option.precision + 1));
        ft_strncat(storage,string,option.precision);
    }
    else if (option.pre_flag == 1 && option.precision == 0)
        storage = "";
    else
        storage = string;
    return(printf_option(storage, &option,0));
}

int	int_option(const char *format, char *str, int k)
{
	struct s_option option;
	int				len;
    char            *temp;

    len = ft_strlen(str);
    reset_option(&option);
    if(ft_option(&option, format, k) == 0 || (option.precision <= len && option.width <= len))
        return(ft_putstr_count(str, 0));
	else
	{
        temp = (char*)malloc(sizeof(char)*(option.precision + 1));
        cal_blank(temp, option.precision - len, '0');
        temp  = ft_strjoin(temp, str);
        return(printf_option(temp, &option, 1));
	}
	
}