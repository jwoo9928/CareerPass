/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japark <astro9928@o.cnu.ac.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:47:56 by japark            #+#    #+#             */
/*   Updated: 2020/02/28 17:59:51 by japark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int     check_str(char s1, char const *set)
{
    int count;

    count = 0;
    while (set[count] != '\0')
    {
        if(set[count] == s1)
            return (1);
        count++;
    }
    return (0);
}

int     get_size(char const *s1, char const *set)
{
    int     size;
    int     s_size;
    int     f_count;
    int     b_count;
    s_size = ft_strlen(s1);
    f_count = 0;
    while (check_str(s1[f_count], set))
        f_count++;
    while (check_str(s1[s_size - b_count - 1],set))
        b_count++;
    size = s_size - f_count - b_count + 1;
    return (size);
}

char	*ft_strtrim(char const *s1, char const *set)
{
    char    *storage;
    int     size;
    int     i;
    int f_size;

    if (!s1)
        return (NULL);
    if (!set)
        return (ft_strdup((char*)s1));
    f_size = ft_strlen(set);
    size = get_size(s1, set);
    storage = (char*)malloc((size)*sizeof(char));
    while (i < size - 1)
    {
        storage[i] = s1[f_size + i];
        i++;
    }
    return (storage);
}