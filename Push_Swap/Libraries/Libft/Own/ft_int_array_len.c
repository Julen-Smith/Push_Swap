/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_array_len.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsmith <jsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 09:22:08 by jsmith            #+#    #+#             */
/*   Updated: 2022/02/01 09:23:40 by jsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int ft_int_array_len(int *serial)
{
    int len;

    len = 0;
    while(serial[len])
        len++;
    return (len);  
}