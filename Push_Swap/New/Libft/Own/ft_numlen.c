/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsmith <jsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 09:18:12 by jsmith            #+#    #+#             */
/*   Updated: 2022/02/01 09:20:21 by jsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int ft_numlen(long long num)
{
    unsigned int len = 1;
    int base_len = 10;

    while(num >= base_len)
	{
        len++;
        num /= base_len;
    }
    return (len);
}