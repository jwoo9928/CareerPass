/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japark <astro9928@o.cnu.ac.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 17:51:43 by japark            #+#    #+#             */
/*   Updated: 2020/03/14 22:33:12 by japark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//^c  ^s  p  ^d  ^i   ^u  ^x   ^X

//d,i,e,E,u
int    check_printf(va_list ap, const char *format,int i)
{
    if (format[i] == 's')
        string_option(format, va_arg(ap,char*),i);
    else if (format[i] == 'p')
        point_option(format, trand_hex((size_t)va_arg(ap,void*),1), i);
    else if (format[i] =='%')
        ft_putchar_fd('%',1);
    else if (format[i] == 'u')
        num_option(format, ft_size_t_itoa((size_t)va_arg(ap, unsigned int)), i);
    else if (check_type(va_arg(ap,int),format, i) == 1)
        i++;
    return (i);
}



int    check_type(int num, const char*format, int i)
{
    if (format[i] == 'd' || format[i] == 'i')
        num_option(format, ft_itoa(num), i);
    if (format[i] == 'e')
        ft_e_notation(num, 1);
    if (format[i] == 'E')
        ft_e_notation(num, 0);
    if (format[i] == 'x')
        num_option(format, trand_hex(num, 1), i);
    if (format[i] == 'X')
        num_option(format, trand_hex(num, 0), i);
    if (format[i] == 'c')
        ft_putchar_fd((char)num, 1);
    else
        return (0);
    return (1);
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
    int count;
    count =  count_option(format, i);
    if (count == 0)
        return(NULL);
    option = (char*)malloc((count+1)*sizeof(char));
    option[count] = '\0';
    while(format[--i] != '%' || count >= 0)
        option[--count] = format[i];
    return (option);
}
