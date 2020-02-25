/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japark <astro9928@o.cnu.ac.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:45:11 by japark            #+#    #+#             */
/*   Updated: 2020/02/25 15:45:11 by japark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_bzero(void *ptr, size_t num)
{
    char *temp;
    int value;

    value = 0;
    temp = (unsigned char*)ptr;
    while (num--)
        *(temp++) = (unsigned char)value;
    return (ptr);
}