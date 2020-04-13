/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japark <astro9928@o.cnu.ac.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 15:28:45 by japark            #+#    #+#             */
/*   Updated: 2020/04/11 14:04:06 by japark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned char	*find;
	size_t			count;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (ft_strlen(s) - start + 1 < len)
		len = ft_strlen(s) - start + 1;
	find = (unsigned char*)malloc((sizeof(unsigned char) * len + 1));
	if (!find)
		return (NULL);
	count = 0;
	while (count < len)
	{
		find[count] = s[count + start];
		count++;
	}
	find[count] = '\0';
	return ((char*)find);
}
