/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japark <astro9928@o.cnu.ac.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:02:08 by japark            #+#    #+#             */
/*   Updated: 2020/04/10 20:51:07 by japark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	const unsigned char *temp1;
	const unsigned char *temp2;

	if (num == 0)
		return (0);
	temp1 = (const unsigned char*)ptr1;
	temp2 = (const unsigned char*)ptr2;
	while (num--)
	{
		if (*temp1 != *temp2)
			return (*temp1 - *temp2);
		if (num)
		{
			temp1++;
			temp2++;
		}
	}
	return (0);
}
