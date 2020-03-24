/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japark <astro9928@o.cnu.ac.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 16:16:07 by japark            #+#    #+#             */
/*   Updated: 2020/03/14 19:48:56 by japark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int    ft_printf(const char*format, ...)
{
    va_list ap;
    int     i;

    va_start(ap,format);
    i = 0;
    while (format[i] != '\0')
    {
        if (format[i] == '%')
        {
            i++;
            while ((format[i] >= 47 && format[i] <= 57) || format[i] == '.'
            || format[i] == '-')
                i++;
            i = check_printf(ap,format,i);
        }
        else
            ft_putchar_fd(format[i], 1);
        i++;
    }
    return (0);
}