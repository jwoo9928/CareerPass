/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japark <astro9928@o.cnu.ac.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 21:38:42 by japark            #+#    #+#             */
/*   Updated: 2020/03/02 14:59:23 by japark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int     return_digit(int n)
{
    int count;

    count = 0;
    if(n < 0)
        n *= -1;
    while(n > 9)
    {
        n = n/10;
        count++;
    }
    count++;
    return (count);
}

char    *ft_itoa(int n)
{
    int digit;
    int flag;
    char *number;

    if (n == -2147483648)
        return(ft_strdup("-2147483648"));
    flag = 0;
    if (n < 0)
    {
        n *= -1;
        flag++;
    }
    digit = return_digit(n);
    if (!(number = (char*)malloc((digit + 1)*sizeof(char))))
        return (NULL);
    if(flag == 1)
        number[0] = '-';
    else
    {
        number[digit] = '\0';
        digit--;
    }
    while(number[digit] == '\0')
    {
        number[digit] = (n%10 + '0');
        n = n / 10;
        digit--;
    }
    return ((char*)(number));
}