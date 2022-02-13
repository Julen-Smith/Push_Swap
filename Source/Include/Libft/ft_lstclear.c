/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsmith <jsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 15:03:08 by jsmith            #+#    #+#             */
/*   Updated: 2021/06/03 15:03:44 by jsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*pnt;

	if (lst)
	{
		while (*lst)
		{
			pnt = (*lst)->next;
			ft_lstdelone(*lst, del);
			(*lst) = pnt;
		}
	}
}
