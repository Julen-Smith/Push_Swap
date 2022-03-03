/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsmith <jsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 18:52:29 by jsmith            #+#    #+#             */
/*   Updated: 2022/03/03 10:27:40 by jsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

int	ft_is_in_the_middle_of_the_stack(t_nodelst *nodelst, int nodepos)
{
	int	middlestacklen;

	ft_refresh_stacklen(nodelst);
	middlestacklen = nodelst->stacklen / 2;
	if (middlestacklen == 3)
		return (0);
	if (ft_calculate_middle_pos(nodelst, nodepos) <= middlestacklen)
		return (1);
	else
		return (0);
}

int	ft_calculate_middle_pos(t_nodelst *lst, int nodepos)
{
	t_node	*node;
	int		i;

	i = 1;
	node = lst->a_head;
	while (node && node->next)
	{
		if (node->position == nodepos)
			return (i);
		i++;
		node = node->next;
	}
	return (i);
}
