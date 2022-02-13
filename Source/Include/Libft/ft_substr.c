/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsmith <jsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:23:57 by jsmith            #+#    #+#             */
/*   Updated: 2021/06/07 19:29:05 by jsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*pnt;

	i = 0;
	pnt = malloc(sizeof(char) * len + 1);
	if (!pnt || !s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (pnt);
	while (len --)
	{
		pnt[i] = s[start];
		i++;
		start++;
	}
	pnt[i] = '\0';
	return (pnt);
}
