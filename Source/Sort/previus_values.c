/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   previus_values.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsmith <jsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 18:53:50 by jsmith            #+#    #+#             */
/*   Updated: 2022/03/03 13:19:58 by jsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

void	ft_generate_previus_values(t_nodelst *nodelst)
{
	t_node	*node;
	t_node	*nodenext;

	if (nodelst->a_head)
	{
		node = nodelst->a_head;
		node->previus = NULL;
		nodenext = nodelst->a_head->next;
		while (nodenext && node && nodenext->next)
		{
			nodenext->previus = node;
			node = node->next;
			nodenext = nodenext->next;
		}
		if (nodenext && node)
			nodenext->previus = node;
	}
}

void	ft_generate_previus_values_on_b(t_nodelst *nodelst)
{
	t_node	*node;
	t_node	*nodenext;

	nodenext = nodelst->a_head;
	if (nodelst->b_head)
	{
		node = nodelst->b_head;
		node->previus = NULL;
		if (nodelst->b_head->next)
			nodenext = nodelst->b_head->next;
		while (nodenext && node && nodenext->next)
		{
			nodenext->previus = node;
			node = node->next;
			nodenext = nodenext->next;
		}
		if (nodenext && node)
			nodenext->previus = node;
	}
}
