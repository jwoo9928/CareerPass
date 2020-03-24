/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optionfunc_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japark <astro9928@o.cnu.ac.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 22:28:29 by japark            #+#    #+#             */
/*   Updated: 2020/03/14 23:04:58 by japark           ###   ########.fr       */
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
    //char            *zerox;

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