/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_netx_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japark <astro9928@o.cnu.ac.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 12:26:51 by japark            #+#    #+#             */
/*   Updated: 2020/03/20 17:51:00 by japark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int     ft_strcheck( char *str, int c)
{
    int temp;

    temp = 0;
    if (str == NULL)
        return (0);
    while(str[temp] != '\0')
    {
        if(str[temp] == c)
            return(temp);
        temp++;
    }
    return (-1);
}

char	*ft_strncat(char *dest, char *src, int nb)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0' && j < nb)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

size_t      ft_strlen(const char *str)
{
    int i;

    i = 0;
    while(str[i] != '\0')
    {
        i++;
    }
    return(i);
}

char    *ft_strndup(char *s, int start, int end)
{
    unsigned char *temp;
    int i;
    int t;
    if (end == 0)
        return (NULL);
    temp = (unsigned char*)malloc((end - start + 2)* sizeof(char));
    if(!temp)
        return (NULL);
    i = start - 1;
    t = -1;
    while (s[++i] != '\0' && i < end)
        temp[++t] = s[i];
    temp[i] = '\0';
    return ((char*)temp);
}

char *ft_sum(char **line, char *src, int nbyte)
{
    char *temp;
    if (src == NULL)
        return (*line);
    if (*line == NULL)
        return (src);
    temp = (char*)malloc(nbyte + 1 + ft_strlen(*line));
    ft_strncat(temp, *line, ft_strlen(*line));
    ft_strncat(temp,src,nbyte);
    return (temp);
}