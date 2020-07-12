/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trans_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewoopark <jaewoopark@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 13:39:31 by japark            #+#    #+#             */
/*   Updated: 2020/07/12 19:00:18 by jaewoopark       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ft_printf.h"

int     count_digit(size_t num, int launch)
{
    int digit;

    digit = 0;
    if (launch == 10)
    {
        while (num > 9)
        {
            num = num/10;
            digit++;
        }
    }
    else if (launch == 16)
    {
        while (num > 15)
        {
            num = num/16;
            digit++;
        }
    }
    return (digit);
}

void    ft_e_notation(int num, int check)
{
    int digit;
    char remain[3];
    char *store;

    digit = count_digit(num,10);
    if(check == 1)
        remain[0] = 'e';
    else
        remain[0] = 'E';
    remain[1] = '+';
    remain[2] = digit + '0';
    store = (char*)malloc((digit+3)*sizeof(char));
    while (num > 9 && digit-- >= 0)
    {
        store[digit] = num%10 +'0';
        num = num/10;
    }
    ft_putchar_fd(num+'0',1);
    ft_putchar_fd('.',1);
    ft_putstr_fd(store,1);
    ft_putstr_fd(remain,1);
    free(store);
}

char    *trand_hex(size_t num, int check)
{
    char *storage;
    int digit;
    char *hex;
    size_t l;

    digit = count_digit(num,16) + 1;
    if (check == 1)
        hex = "0123456789abcdef";
    else
        hex = "0123456789ABCDEF";
    storage = (char*)malloc((digit+1)*sizeof(char));
    storage[digit] = '\0';
    while (num > 15 && --digit > 0)
    {
        l = num%16;
        storage[digit] = hex[l];
        num = num/16;
    }
    storage[digit - 1] = hex[num];
    return (storage);
}