/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsmith <jsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 01:57:12 by jsmith            #+#    #+#             */
/*   Updated: 2022/02/25 08:01:06 by jsmith           ###   ########.fr       */
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
		if (pnt && pnt->next)
		{
			while (pnt && pnt->next)
			{
				pnt = pnt->next;
				i++;
			}
			return (i);
		}
	}	
	else
		pnt = nodelst->b_head;
		while (pnt && pnt->next)
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
		if (nodelst->a_head)
		{
			spec_node = nodelst->a_head;
			while(i != last && spec_node && spec_node->next)
			{
				spec_node = spec_node->next;
				i++;
			}
		}
		
	}else
		if (nodelst->b_head)
		{
			spec_node = nodelst->b_head;
			while(i != last && spec_node && spec_node->next)
			{
				spec_node = spec_node->next;
				i++;
			}
		}
		
	return (spec_node);
}

int	ft_check_if_we_still_have_middles(t_nodelst *nodelst)
{
	t_node *node;
	t_node *last_ptr;
	t_node *ghost_pointer;
	
	node = nodelst->a_head;
	ghost_pointer = malloc(sizeof(t_node));
	last_ptr = ft_return_specific_node(nodelst,ft_iterate_stack(nodelst,'a'),'a');
	last_ptr->next = ghost_pointer;
	ghost_pointer->next = NULL;
	while(node->next)
	{
		if (node->nbr < nodelst->middle->nbr)
		{	
			free(ghost_pointer);
			return (1);
		}
		node = node->next;	
	}
	last_ptr->next = NULL;
	free(ghost_pointer);
	return (0);
}