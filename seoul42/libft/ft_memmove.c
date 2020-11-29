/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japark <astro9928@o.cnu.ac.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 14:52:07 by japark            #+#    #+#             */
/*   Updated: 2020/04/17 15:04:09 by japark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *dst2;
	unsigned char *src2;

	if (dst == NULL && src == NULL)
		return (NULL);
	src2 = (unsigned char *)src;
	dst2 = (unsigned char *)dst;
	if (src < dst)
		while (len--)
			*(dst2 + len) = *(src2 + len);
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
