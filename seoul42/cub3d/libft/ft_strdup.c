/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japark <astro9928@o.cnu.ac.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 11:11:51 by japark            #+#    #+#             */
/*   Updated: 2020/04/11 14:27:26 by japark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	size_t	i;
	char	*ret;

	i = 0;
	if ((ret = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1)) != NULL)
	{
		while (s1[i])
		{
			ret[i] = s1[i];
			i++;
		}
		ret[i] = '\0';
		return (ret);
	}
	return (NULL);
}
