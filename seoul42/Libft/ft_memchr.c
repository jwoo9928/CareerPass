/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japark <astro9928@o.cnu.ac.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:03:46 by japark            #+#    #+#             */
/*   Updated: 2020/04/10 20:47:01 by japark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *ptr, int c, size_t num)
{
	size_t i;

	i = 0;
	while (i < num)
	{
		if (*((unsigned char*)ptr + i) == (unsigned char)c)
			return (ptr + i);
		i++;
	}
	return (0);
}
