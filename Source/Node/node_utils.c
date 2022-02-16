/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsmith <jsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 01:57:12 by jsmith            #+#    #+#             */
/*   Updated: 2022/02/16 21:07:55 by jsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../Include/push_swap.h"

int	ft_iterate_stack(t_nodelst *nodelst, char e)
{
	t_node *pnt;
	int i;

	i = 0;
	if (e == 'a')
	{
		pnt = nodelst->a_head;
		while (pnt->next)
		{
			pnt = pnt->next;
			i++;
		}
			return (i);
	}	
	else
		pnt = nodelst->b_head;
		while (pnt->next)
		{
			pnt = pnt->next;
			i++;
		}
	return (i);
}

t_node *ft_return_specific_node(t_nodelst *nodelst, int last, char e)
{
	t_node *spec_node;
	int i;

	i = 0;
	if(e == 'a')
	{
		spec_node = nodelst->a_head;
		while(i != last)
		{
			spec_node = spec_node->next;
			i++;
		}
	}else
		spec_node = nodelst->b_head;
		while(i != last)
		{
			spec_node = spec_node->next;
			i++;
		}
	return (spec_node);
}

t_node *ft_return_lowst_pointer(t_nodelst *lst)
{
	t_node *pnt;
	t_node *dummy;

	pnt = lst->a_head;
	dummy = lst->a_head;
	while (pnt->next)
	{
		if (pnt->nbr < dummy->nbr)
			dummy = pnt;
		pnt = pnt->next;
	}
	if (pnt->nbr < dummy->nbr)
		dummy = pnt;
	dummy->position = 1;
	return (dummy);
}

void	ft_initialize_positions(t_nodelst *lst)
{
	t_node *pnt;
	t_node *last_node;
	t_node *ghost_pointer;

	pnt = lst->a_head;
	last_node =  ft_return_specific_node(lst,ft_iterate_stack(lst,'a'),'a');
	ghost_pointer = malloc (sizeof(t_node));
	last_node->next = ghost_pointer;
	ghost_pointer->next = NULL;
	while(pnt->next)
	{	
		pnt->position = -1;
		pnt = pnt->next;
	}
	last_node->next = NULL;
	free(ghost_pointer);
}

t_node *ft_return_biggst_pointer(t_nodelst *lst)
{
	t_node *pnt;
	t_node *dummy;

	pnt = lst->a_head;
	dummy = lst->a_head;
	while (pnt->next)
	{
		if (pnt->nbr > dummy->nbr)
			dummy = pnt;
		pnt = pnt->next;
	}
	if (pnt->nbr > dummy->nbr)
		dummy = pnt;
	dummy->position = ft_iterate_stack(lst,'a') +1;
	return (dummy);
}