/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_t_itoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japark <astro9928@o.cnu.ac.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 15:36:23 by japark            #+#    #+#             */
/*   Updated: 2020/03/12 16:51:01 by japark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t     sizet_return_digit(size_t n)
{
    size_t count;

    count = 0;
    while(n > 9)
    {
        n = n/10;
        count++;
    }
    count++;
    return (count);
}

char    *ft_size_t_itoa(size_t n)
{
    size_t digit;
    char *number;

    digit = sizet_return_digit(n);
    if (!(number = (char*)malloc((digit + 1)*sizeof(char))))
        return (NULL);

    number[digit] = '\0';
    digit--;
    while(number[digit] == '\0')
    {
        number[digit] = (n%10 + '0');
        n = n / 10;
        digit--;
    }
    return ((char*)(number));
}