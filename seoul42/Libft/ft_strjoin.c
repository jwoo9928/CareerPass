/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japark <astro9928@o.cnu.ac.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:20:17 by japark            #+#    #+#             */
/*   Updated: 2020/02/27 22:27:40 by japark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strjoin(char const *s1, char const *s2)
{
    char *sum;
    int i;
    int s1_len;

    if (!s1 || !s2)
        return (NULL);
    s1_len = ft_strlen(s1);
    sum = (char*)malloc((s1_len + ft_strlen(s2))*sizeof(char));
    if (!sum)
        return (NULL);
    i = -1;
    while (s1[++i] != '\0')
        sum[i] = s1[i];
    i = -1;
    while (s2[++i] != '\0')
        sum[s1_len + i] = s2[i];
    sum[s1_len + i] = '\0';
    return (sum);
}