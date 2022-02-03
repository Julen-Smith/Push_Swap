/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsmith <jsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:23:46 by jsmith            #+#    #+#             */
/*   Updated: 2021/05/27 18:20:28 by jsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	unsigned int	i;
	char			*new;

	if (s == 0 || f == 0)
		return (NULL);
	len = ft_strlen(s);
	new = (char *)malloc(sizeof(char) *(len + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new[i] = f(i, s[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	f(unsigned int i, char c)
{
	if (i + 1)
	{
		if (ft_isalpha(c))
			c = c - 32;
	}
	return (c);
}
