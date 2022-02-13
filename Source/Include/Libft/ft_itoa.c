/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsmith <jsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:23:27 by jsmith            #+#    #+#             */
/*   Updated: 2021/05/28 15:51:52 by jsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_size(int n, size_t *len, int *weight)
{
	*len = 1;
	if (n >= 0)
	{
		*len = 0;
		n = -n;
	}
	*weight = 1;
	while (n / *weight < -9)
	{
		*weight *= 10;
		*len += 1;
	}
}

char	*ft_itoa(int nbr)
{
	size_t		size;
	int			weight;
	size_t		i;
	char		*str;

	ft_size(nbr, &size, &weight);
	str = (char *)malloc(sizeof(*str) * (size + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	if (nbr < 0)
	{
		str[i] = '-';
		i++;
	}
	if (nbr > 0)
		nbr = -nbr;
	while (weight >= 1)
	{
		str[i++] = -(nbr / weight % 10) + 48;
		weight /= 10;
	}
	str[i] = '\0';
	return (str);
}
