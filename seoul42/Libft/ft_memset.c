/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japark <astro9928@o.cnu.ac.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 22:25:40 by japark            #+#    #+#             */
/*   Updated: 2020/02/24 22:25:40 by japark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memset(void *ptr, int value, size_t num)
{
    unsigned char *temp;

    temp = (unsigned char*)ptr;
    while (num-- > 0)
        *(temp++) = (unsigned char)value;
    return (ptr);
}