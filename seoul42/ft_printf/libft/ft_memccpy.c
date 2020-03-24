/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japark <astro9928@o.cnu.ac.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:03:07 by japark            #+#    #+#             */
/*   Updated: 2020/03/02 13:02:52 by japark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "libft.h"

void    *ft_memccpy(void *dest, const void *src, int c, size_t num)
{
    size_t i;
    char *dst;
    char *srcs;

    if(dest == src || num == 0)
        return (dest);
    i = 0;
    dst = (char *)dest;
    srcs = (char *)src;
    while (i <num)
    {
        dst[i] = srcs[i];
        if(dst[i] == (char)c)
            return (dest + i + 1);
        i++;
    }
    return (NULL);
}