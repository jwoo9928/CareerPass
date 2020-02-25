/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japark <astro9928@o.cnu.ac.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:21:50 by japark            #+#    #+#             */
/*   Updated: 2020/02/25 15:21:50 by japark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef LIBFT_H
#define LIBFT_H

typedef unsigned int size_t;

void    *ft_bzero(void *ptr, size_t num);
void    *memcpy(void *destination, const void  *source, size_t num);
void    *ft_memmove(void *destination, const void *source, size_t num);
void    *ft_memset(void *ptr, int value, size_t num);

#endif