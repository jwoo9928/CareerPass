/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japark <astro9928@o.cnu.ac.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 13:48:06 by japark            #+#    #+#             */
/*   Updated: 2020/04/13 13:48:06 by japark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*get_str(char const *s, char c, int *len)
{
	int		i;
	char	*str;

	i = 0;
	*len = 0;
	while (*s == c)
	{
		s++;
		(*len)++;
	}
	while (s[i])
	{
		if (c == s[i])
			break ;
		i++;
		(*len)++;
	}
	str = (char*)malloc(sizeof(char) * i + 1);
	ft_strlcpy(str, s, i + 1);
	return (str);
}

static int		get_count(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (*s == c)
		s++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1])
			count++;
		i++;
	}
	return (i == 0 ? count : count + 1);
}

char			**ft_split(char const *s, char c)
{
	char	**set;
	int		count;
	int		len;
	int		i;

	i = 0;
	count = get_count(s, c);
	if (!(set = (char**)malloc(sizeof(char*) * (count + 1))))
		return (NULL);
	while (i < count)
	{
		set[i] = get_str(s, c, &len);
		s += len;
		i++;
	}
	set[i] = NULL;
	return (set);
}
