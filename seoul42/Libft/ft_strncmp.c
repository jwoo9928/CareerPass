/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japark <astro9928@o.cnu.ac.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 19:36:29 by japark            #+#    #+#             */
/*   Updated: 2020/02/26 19:56:47 by japark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int     ft_strncmp(const char *str1, const char *str2, size_t n)
{
    size_t i;

    i = 0;
    if (n == 0)
        return (0);
    while (str1[i] && str2[i] && str1[i] == str2[i] && i < n - 1)
        i++;
    return (*((unsigned char*)str1 + i) - *((unsigned char*)str2 + i));
}