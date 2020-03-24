/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japark <astro9928@o.cnu.ac.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 11:11:51 by japark            #+#    #+#             */
/*   Updated: 2020/02/29 19:27:55 by japark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strdup(char *s)
{
    unsigned char *temp;
    int i;
    
    temp = (unsigned char*)malloc(sizeof(s));
    if(!temp)
        return (NULL);
    i = 0;
    while (s[i] != '\0')
    {
        temp[i] = s[i];
        i++;
    }
    temp[i] = '\0';
    return ((char*)temp);
}