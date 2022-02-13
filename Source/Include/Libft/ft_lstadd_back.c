/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsmith <jsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 14:32:28 by jsmith            #+#    #+#             */
/*   Updated: 2021/06/03 14:34:02 by jsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*pnt;

	if (lst)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			pnt = ft_lstlast(*(lst));
			pnt->next = new;
		}
	}
}
