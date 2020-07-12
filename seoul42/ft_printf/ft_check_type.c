/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewoopark <jaewoopark@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 17:51:43 by japark            #+#    #+#             */
/*   Updated: 2020/07/12 19:03:07 by jaewoopark       ###   ########.fr       */
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
        int_option(format, ft_size_t_itoa((size_t)va_arg(ap, unsigned int)), i);
    else
        check_type(va_arg(ap, int),format, i);
    return (0);
}



int    check_type(int num, const char*format, int i)
{   
    if (format[i] == 'd' || format[i] == 'i')
        int_option(format, ft_itoa(num), i);
    else if (format[i] == 'x')
        int_option(format, trand_hex(num, 1), i);
    else if (format[i] == 'X')
        int_option(format, trand_hex(num, 0), i);
    else if (format[i] == 'e')
        ft_e_notation(num, 1);
    else if (format[i] == 'E')
        ft_e_notation(num, 0);
    else if (format[i] == 'c')
        char_option(format, (char)num, i);
    else
        return (0);

    return 1;
}
