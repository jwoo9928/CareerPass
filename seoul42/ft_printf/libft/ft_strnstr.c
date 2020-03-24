/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japark <astro9928@o.cnu.ac.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 19:23:15 by japark            #+#    #+#             */
/*   Updated: 2020/02/26 19:35:07 by japark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	unsigned int standard;
	unsigned int i;

    standard = 0;
	if (!*to_find)
		return ((char*)str);
	while (str[standard] != '\0' && (size_t)standard < len)
	{
		if (str[standard] == to_find[0])
		{
			i = 1;
			while (to_find[i] != '\0' && str[standard + i] == to_find[i] &&
					(size_t)(standard + i) < len)
				++i;
			if (to_find[i] == '\0')
				return ((char*)&str[standard]);
		}
		++standard;
	}
	return (0);
}