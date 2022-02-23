/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_3_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsmith <jsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 08:25:17 by jsmith            #+#    #+#             */
/*   Updated: 2022/02/23 08:45:51 by jsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

void	ft_ordenate_3_stack(t_nodelst *nodelst)
{
	int middle;

	middle = ft_where_is_node_in_stack(nodelst,ft_return_node_by_pos(nodelst,nodelst->middle->position)->nbr);
	if (middle == 1 && nodelst->a_head->next->nbr < nodelst->middle->nbr)
		ft_swap_a(nodelst);
	else if(middle == 1 && nodelst->a_head->next->nbr > nodelst->middle->nbr)
		ft_reverse_rotate_a(nodelst);
	else if(middle == 2)
	{
		ft_swap_a(nodelst);
		ft_reverse_rotate_a(nodelst);
	}
	else
	{
		if (ft_return_biggst_pointer(nodelst) == nodelst->a_head)
			ft_rotate_a(nodelst);
		else
		{
			ft_swap_a(nodelst);
			ft_rotate_a(nodelst);
		}
	}
}