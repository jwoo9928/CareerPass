/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_t_itoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewoopark <jaewoopark@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 15:36:23 by japark            #+#    #+#             */
/*   Updated: 2020/07/11 15:27:20 by jaewoopark       ###   ########.fr       */
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

char	*ft_strncat(char *dest, char *src, int nb)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0' && j < nb)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}