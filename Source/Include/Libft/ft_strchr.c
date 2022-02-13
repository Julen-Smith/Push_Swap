/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsmith <jsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 12:23:11 by jsmith            #+#    #+#             */
/*   Updated: 2021/06/02 18:56:26 by jsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ind)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)ind)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == (char)ind)
		return ((char *)&str[i]);
	return (NULL);
}
