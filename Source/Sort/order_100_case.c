/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_100_case.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsmith <jsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 18:55:17 by jsmith            #+#    #+#             */
/*   Updated: 2022/03/03 10:52:03 by jsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

int	ft_return_the_ordenate_chunk_to_a(t_nodelst *nodelst, int big)
{
	while (nodelst->b_head->position - 1 == nodelst->b_head->next->position)
	{
		ft_push_a(nodelst);
		big--;
	}
	if (nodelst->b_head->position == big)
	{
		ft_push_a(nodelst);
		big--;
	}
	return (big);
}

void	ft_numbers_return_to_stack_a(t_nodelst *nodelst)
{
	int	big;
	int	top;
	int	bot;

	big = ft_return_biggst_pointer(nodelst, 'b')->position;
	big = ft_return_the_ordenate_chunk_to_a(nodelst, big);
	while (big != 0 && nodelst->b_head)
	{	
		ft_refresh_stacklen_b(nodelst);
		top = ft_find_moves_from_top(nodelst, big);
		bot = ft_find_moves_from_bottom(nodelst, big);
		if (nodelst->b_head && nodelst->b_head->position != big)
		{
			if (top <= bot)
				while (nodelst->b_head->position != big)
					ft_rotate_b(nodelst);
			else
				while (nodelst->b_head->position != big)
					ft_reverse_rotate_b(nodelst);
		}
		if (nodelst->b_head->position == big)
			big = ft_just_because_the_norm(nodelst, big);
	}
}

void	ft_ordenate_100_last_part(t_nodelst *nodelst)
{
	int	i;

	ft_refresh_stacklen(nodelst);
	while (nodelst->a_head)
	{
		ft_refresh_stacklen(nodelst);
		i = ft_return_lowst_pointer(nodelst)->position;
		if (ft_is_in_the_middle_of_the_stack(nodelst, i))
		{
			while (nodelst->a_head->position != i)
				ft_rotate_a(nodelst);
		}
		else
			while (nodelst->a_head->position != i)
				ft_reverse_rotate_a(nodelst);
		ft_push_b(nodelst);
	}
}

void	ft_conditional_ra_and_rra(t_nodelst *nodelst)
{
	if (nodelst->nbrfromtop <= nodelst->nbrfrombottom)
	{
		while (nodelst->nbrfromtop != 0)
		{
			ft_rotate_a(nodelst);
			nodelst->nbrfromtop--;
		}	
	}
	else
	{
		while (nodelst->nbrfrombottom != 0)
		{
			ft_reverse_rotate_a(nodelst);
			nodelst->nbrfrombottom--;
		}
	}	
	if (nodelst->a_head && nodelst->a_head->position <= nodelst->chunksize)
		ft_push_b(nodelst);
}

void	ft_ordenate_100_stack(t_nodelst *nodelst)
{
	t_node	*big;
	int		initial_chunk;
	int		i;
	int		u;

	big = ft_return_biggst_pointer(nodelst, 'a');
	ft_refresh_stacklen(nodelst);
	nodelst->chunksize = nodelst->stacklen / 4;
	initial_chunk = nodelst->chunksize;
	u = 0;
	while (u++ != 3)
	{
		i = 0;
		while (i++ != initial_chunk)
		{
			ft_find_first_cond_from_top(nodelst, nodelst->chunksize);
			ft_find_first_cond_from_bottom(nodelst, nodelst->chunksize);
			ft_conditional_ra_and_rra(nodelst);
		}
		nodelst->chunksize += initial_chunk;
	}
	ft_ordenate_100_last_part(nodelst);
	ft_numbers_return_to_stack_a(nodelst);
}
