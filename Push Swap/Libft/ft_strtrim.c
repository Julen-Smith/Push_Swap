/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsmith <jsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:23:49 by jsmith            #+#    #+#             */
/*   Updated: 2021/06/02 19:33:58 by jsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_try_char(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	u;
	size_t	z;

	u = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[u] && ft_try_char(s1[u], set))
		u++;
	z = ft_strlen(s1);
	while (z > u && ft_try_char(s1[z - 1], set))
		z--;
	str = (char *)malloc(sizeof(*s1) * (z - u + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (u < z)
		str[i++] = s1[u++];
	str[i] = 0;
	return (str);
}
