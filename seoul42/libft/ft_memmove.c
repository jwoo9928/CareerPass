/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japark <astro9928@o.cnu.ac.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:34:58 by japark            #+#    #+#             */
/*   Updated: 2020/02/25 16:34:58 by japark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memmove(void *destination, const void *source, size_t num)
{
    void *temp;
    size_t i;

    temp = destination;
    i = 0;
    while (i < num)
    {
        (unsigned char*)destination + i = (unsigned char*)source + i;
        i++;
    }
    return (temp);
}