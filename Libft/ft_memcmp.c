/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsmith <jsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 12:23:02 by jsmith            #+#    #+#             */
/*   Updated: 2021/05/27 18:02:51 by jsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*pnt_s1;
	unsigned char	*pnt_s2;
	size_t			i;

	pnt_s1 = (unsigned char *) s1;
	pnt_s2 = (unsigned char *) s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i != n)
	{
		if (pnt_s1[i] != pnt_s2[i])
			return (pnt_s1[i] - pnt_s2[i]);
		++i;
	}
	return (0);
}
