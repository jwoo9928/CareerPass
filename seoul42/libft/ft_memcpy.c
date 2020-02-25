/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japark <astro9928@o.cnu.ac.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:50:31 by japark            #+#    #+#             */
/*   Updated: 2020/02/25 15:50:31 by japark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *memcpy(void *destination, const void  *source, size_t num)
{
    size_t i;

    i = 0;
    while(i < num)
    {
        *((unsigned char*)destination + i) = *((unsigned char*)source + i);
        i++;
    }
    return (destination);
}