/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japark <astro9928@o.cnu.ac.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 13:47:51 by japark            #+#    #+#             */
/*   Updated: 2020/04/13 13:47:51 by japark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *ptr1, const char *ptr2, size_t num)
{
	size_t	i;
	size_t	ptr1_len;
	size_t	ptr2_len;

	i = 0;
	ptr1_len = ft_strlen(ptr1);
	ptr2_len = ft_strlen(ptr2);
	if (ptr1_len >= num)
		return (ptr2_len + num);
	while (ptr2[i] && (num - 1 > i + ptr1_len))
	{
		ptr1[i + ptr1_len] = ptr2[i];
		i++;
	}
	ptr1[i + ptr1_len] = '\0';
	return (ptr1_len + ptr2_len);
}
