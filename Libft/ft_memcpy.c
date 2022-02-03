/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsmith <jsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 12:23:04 by jsmith            #+#    #+#             */
/*   Updated: 2021/06/04 15:05:43 by jsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*pntdst;
	unsigned char	*pntsrc;

	pntdst = (unsigned char *)dst;
	pntsrc = (unsigned char *)src;
	i = 0;
	if (pntdst == NULL && pntsrc == NULL)
		return (NULL);
	while (i < n)
	{
		pntdst[i] = pntsrc[i];
		i++;
	}
	return ((void *) pntdst);
}
