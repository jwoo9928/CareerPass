/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japark <astro9928@o.cnu.ac.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 11:39:00 by japark            #+#    #+#             */
/*   Updated: 2020/04/11 14:26:11 by japark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t elt_count, size_t elt_size)
{
	unsigned char *storage;

	storage = (unsigned char*)malloc(elt_count * elt_size);
	if (!storage)
		return (NULL);
	ft_memset(storage, 0, elt_size * elt_count);
	return ((void*)storage);
}
