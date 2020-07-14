/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optionfunc2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewoopark <jaewoopark@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 18:17:10 by jaewoopark        #+#    #+#             */
/*   Updated: 2020/07/14 21:29:51 by jaewoopark       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     percent_option(const char *format, int k)
{
    struct s_option option;
    char            storage[2];

    reset_option(&option);
    ft_option(&option, format, k);
    storage[0] = '%';
    storage[1] = '\0';
    return(printf_option(storage, &option, 1));

}