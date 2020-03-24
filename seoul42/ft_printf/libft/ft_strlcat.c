/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japark <astro9928@o.cnu.ac.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:39:59 by japark            #+#    #+#             */
/*   Updated: 2020/03/02 14:14:28 by japark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t  strlcat(char *dest, const char *src, size_t size)
{
    size_t dest_s;
    size_t src_s;
    size_t i;

    while (dest[dest_s] != '\0')
        dest_s++;
    while (src[src_s] != '\0')
        src_s++;
    if (size <= dest_s)
        src_s += size;
    else
        src_s += dest_s;
    i = 0;
    while(src[i] != '\0' && i + 1 < size)
    {
        dest[dest_s] = src[i];
        i++;
        dest_s++;
    }
    dest[i] = '\0';
    return (src_s);
    
}