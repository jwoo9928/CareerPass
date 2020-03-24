/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japark <astro9928@o.cnu.ac.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:54:17 by japark            #+#    #+#             */
/*   Updated: 2020/03/02 14:12:58 by japark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strrchr(const char *str, int c)
{
    int     len;

    len = ft_strlen((char*)str);
    while(0 != len && str[len] != (char)c)
        len--;
    if(str[len] == (char)c)
        return((char*)&str[len]);
    return (NULL);
}