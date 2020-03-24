/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japark <astro9928@o.cnu.ac.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 12:57:32 by japark            #+#    #+#             */
/*   Updated: 2020/03/02 12:57:32 by japark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memcpy(void *destination, const void  *source, size_t num)
{
    char    *dst;
    char    *src;

    if(num == 0 || destination == source)
        return(destination);
    dst = (char*)destination;
    src = (char*)source;
    while(--num)
    {
        *dst++ = *src++;
    }
    *dst = *src;
    return (destination);
}