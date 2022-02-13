/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsmith <jsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 18:14:51 by jsmith            #+#    #+#             */
/*   Updated: 2021/05/28 13:23:19 by jsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*pnt;

	pnt = malloc(size * count);
	if (!pnt)
		return (NULL);
	ft_memset(pnt, 0, count * size);
	return (pnt);
}
