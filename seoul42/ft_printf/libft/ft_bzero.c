/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japark <astro9928@o.cnu.ac.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:45:11 by japark            #+#    #+#             */
/*   Updated: 2020/02/25 15:45:11 by japark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void    ft_bzero(void *ptr, size_t num)
{
	size_t i;
	unsigned char *buffer;

	i = 0;
	buffer = (unsigned char*)ptr;
	while(i < num)
	{
		buffer[i] = 0;
		i++;
	}
}