/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewoopark <jaewoopark@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 16:16:07 by japark            #+#    #+#             */
/*   Updated: 2020/07/14 15:35:32 by jaewoopark       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int    ft_printf(const char*format, ...)
{
    va_list ap;
    int     i;
    int     size;

    va_start(ap,format);
    i = 0;
    size = 0;
    while (format[i] != '\0')
    {
        if (format[i] == '%')
        {
            i++;
            while ((format[i] > 47 && format[i] <= 57) || format[i] == '.'
            || format[i] == '-')
                i++;
            size += check_printf(ap,format,i);
        }
        else
            ft_count_putchar(format[i], &size);
        i++;
        /*if (format[i] == '\n')
            size++;*/
    }
    return (size);
}