/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japark <astro9928@o.cnu.ac.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:36:27 by japark            #+#    #+#             */
/*   Updated: 2020/02/27 21:01:17 by japark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int     first_dim_count(char const *s, char c)
{
    int f_dim;
    int count;

    f_dim = 0;
    count = 0;
    while(s[count] != '\0')
    {
        if (s[count] == c)
            f_dim++;
        count++;
    }
    return (f_dim + 1);
}

int     second_dim_count(char const *s, char c, int i)
{
    int count;
    int num;
    
    count = i;
    num = 0;
    while (s[count] != c)
    {
        count++;
        num++;
        if (!s[count])
            break;
    }
    return (num);
}

int g_check;

int    set_s_dim(char const *s, char c, char **storage, int flag)
{
    int i;
    int count;

    i = 0;
    count = second_dim_count(s, c, g_check);
    storage[flag] = (char*)malloc(sizeof(char)*(count + 1));
    while(i < count)
    {
        storage[flag][i] = s[g_check + i];
        i++;
    }
    storage[flag][i] = '\0';
    return (count + 1);
}

char    **ft_split(char const *s, char c)
{
    char    **storage;
    int flag;

    if (!s || !c)
        return (NULL);
    storage = (char**)malloc(first_dim_count(s, c)*sizeof(char*));
    if(!storage)
        return (NULL);
    g_check = 0;
    flag = 0;
    while(s[g_check] != '\0')
    {
        g_check += set_s_dim(s, c, storage, flag);
        flag++;
    }
    return (storage);
}