/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_500_case.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsmith <jsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 10:22:28 by jsmith            #+#    #+#             */
/*   Updated: 2022/03/03 10:53:31 by jsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

void	ft_ordenate_500_stack(t_nodelst *nodelst)
{
	t_node	*big;
	int		initial_chunk;
	int		i;
	int		u;

	big = ft_return_biggst_pointer(nodelst, 'a');
	ft_refresh_stacklen(nodelst);
	nodelst->chunksize = nodelst->stacklen / 8;
	initial_chunk = nodelst->chunksize;
	u = 0;
	while (u++ != 8)
	{
		i = 0;
		while (i != initial_chunk)
		{
			ft_find_first_cond_from_top(nodelst, nodelst->chunksize);
			ft_find_first_cond_from_bottom(nodelst, nodelst->chunksize);
			ft_conditional_ra_and_rra(nodelst);
			i++;
		}
		nodelst->chunksize += initial_chunk;
	}
	ft_ordenate_100_last_part(nodelst);
	ft_numbers_return_to_stack_a(nodelst);
}

int	ft_just_because_the_norm(t_nodelst *nodelst, int big)
{
	ft_push_a(nodelst);
	big = big -1;
	return (big);
}
