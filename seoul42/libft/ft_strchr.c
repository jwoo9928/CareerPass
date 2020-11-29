/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japark <astro9928@o.cnu.ac.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:30:58 by japark            #+#    #+#             */
/*   Updated: 2020/04/11 14:17:57 by japark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char *temp;

	temp = (char*)str;
	while (*temp != c)
	{
		if (*temp == '\0')
			return (NULL);
		temp++;
	}
	return (temp);
}
