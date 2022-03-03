/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_10_case.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsmith <jsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 18:51:55 by jsmith            #+#    #+#             */
/*   Updated: 2022/03/03 10:26:33 by jsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

void	ft_ordenate_10_stack(t_nodelst *nodelst)
{
	t_node	*lowst_ptr;
	int		i;

	i = 1;
	lowst_ptr = ft_return_biggst_pointer(nodelst, 'a');
	while (ft_check_nodeorder(nodelst) && nodelst->stacklen > 3)
	{
		if (ft_is_in_the_middle_of_the_stack(nodelst, i))
			while (ft_return_node_by_pos(nodelst, i) != nodelst->a_head
				&& nodelst->stacklen > 3)
				ft_rotate_a(nodelst);
		else
			while (ft_return_node_by_pos(nodelst, i) != nodelst->a_head
				&& nodelst->stacklen > 3)
				ft_reverse_rotate_a(nodelst);
		i++;
		ft_push_b(nodelst);
		ft_refresh_stacklen(nodelst);
	}
	if (nodelst->stacklen == 3 && ft_check_nodeorder(nodelst))
		ft_ordenate_3_stack(nodelst);
	while (nodelst->b_head)
		ft_push_a(nodelst);
}
