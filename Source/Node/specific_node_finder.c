/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specific_node_finder.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsmith <jsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 08:27:46 by jsmith            #+#    #+#             */
/*   Updated: 2022/03/03 13:25:51 by jsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

int	ft_where_is_node_in_stack(t_nodelst *nodelst, int nbr)
{
	t_node	*pnt;
	int		i;

	i = 1;
	pnt = nodelst->a_head;
	while (pnt && pnt->next)
	{
		if (pnt && pnt->nbr == nbr)
			return (i);
		i++;
		pnt = pnt->next;
	}
	return (i);
}

t_node	*ft_where_is_node_by_nbr(t_nodelst *nodelst, int nbr)
{
	t_node	*pnt;
	t_node	*ghost_pointer;
	t_node	*lp;
	int		i;

	i = 1;
	pnt = nodelst->a_head;
	ghost_pointer = malloc(sizeof(t_node));
	lp = ft_return_specific_node(nodelst, ft_iterate_stack(nodelst, 'a'), 'a');
	lp->next = ghost_pointer;
	ghost_pointer->next = NULL;
	while (pnt && pnt->next)
	{
		if (pnt && pnt->nbr == nbr)
		{
			lp->next = NULL;
			free(ghost_pointer);
			return (pnt);
		}		
		i++;
		pnt = pnt->next;
	}
	lp->next = NULL;
	free(ghost_pointer);
	return (pnt);
}

t_node	*ft_return_node_by_pos(t_nodelst *nodelst, int position)
{
	t_node	*pnt;
	int		i;

	i = 1;
	pnt = nodelst->a_head;
	while (pnt && pnt->next)
	{
		if (pnt && pnt->position == position)
			return (pnt);
		pnt = pnt->next;
		i++;
	}
	return (pnt);
}

t_node	*ft_return_lowst_pointer(t_nodelst *lst)
{
	t_node	*pnt;
	t_node	*dummy;

	pnt = lst->a_head;
	dummy = lst->a_head;
	while (pnt && pnt->next)
	{
		if (pnt->nbr < dummy->nbr)
			dummy = pnt;
		pnt = pnt->next;
	}
	if (pnt && pnt->nbr < dummy->nbr)
		dummy = pnt;
	return (dummy);
}

t_node	*ft_return_biggst_pointer(t_nodelst *lst, char e)
{
	t_node	*pnt;
	t_node	*dummy;

	if (e == 'a')
	{
		pnt = lst->a_head;
		dummy = lst->a_head;
	}
	else
	{
		pnt = lst->b_head;
		dummy = lst->b_head;
	}
	while (pnt && pnt && pnt->next)
	{
		if (pnt->nbr > dummy->nbr)
			dummy = pnt;
		pnt = pnt->next;
	}
	if (pnt && pnt->nbr > dummy->nbr)
		dummy = pnt;
	return (dummy);
}
