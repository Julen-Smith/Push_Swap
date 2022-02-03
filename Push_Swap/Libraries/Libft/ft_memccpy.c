/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsmith <jsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 12:22:56 by jsmith            #+#    #+#             */
/*   Updated: 2021/05/28 11:36:32 by jsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*pnt_dst;
	unsigned char	*pnt_src;
	size_t			i;

	pnt_dst = (unsigned char *) dst;
	pnt_src = (unsigned char *) src;
	i = 0;
	while (i < n)
	{
		pnt_dst[i] = pnt_src[i];
		if (pnt_dst[i] == (unsigned char)c)
			return ((void *)(dst + i + 1));
		++i;
	}
	return (NULL);
}
