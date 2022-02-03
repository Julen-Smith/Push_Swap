/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsmith <jsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 15:07:18 by jsmith            #+#    #+#             */
/*   Updated: 2021/06/03 15:08:30 by jsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*pnt;

	if (lst != NULL)
	{
		pnt = lst;
		while (1)
		{
			(*f)(pnt->content);
			pnt = pnt->next;
			if (pnt == NULL)
				return ;
		}
	}
}
