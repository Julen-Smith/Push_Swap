/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsmith <jsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 08:26:17 by jsmith            #+#    #+#             */
/*   Updated: 2022/02/23 12:47:34 by jsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

int		ft_check_nodeorder(t_nodelst *nodelst)
{
	t_node *i;
	int u;
	t_node *ghost_ptr;
	t_node *last_node;

	i = nodelst->a_head->next;
	u = nodelst->a_head->nbr;
	last_node = ft_return_specific_node(nodelst,ft_iterate_stack(nodelst,'a'),'a');
	ghost_ptr = malloc (sizeof(t_node));
	last_node->next = ghost_ptr;
	ghost_ptr->next = NULL;
	while(i && i->next)
	{
		if(u > i->nbr && i)
		{
			last_node->next = NULL;
			free(ghost_ptr);
			return (1);
		}
		u = i->nbr;
		i = i->next;
	}
	last_node->next = NULL;
	free(ghost_ptr);	
	return (0);
}

void ft_get_middle(t_nodelst *nodelst)
{
	t_node *pointer;
	int middle;

	pointer = ft_return_biggst_pointer(nodelst);
	middle = pointer->position / 2;
	nodelst->middle = ft_return_node_by_pos(nodelst,middle);
}

void		ft_refresh_stacklen(t_nodelst *nodelst)
{	
	t_node *pnt;
	t_node *ghost_pointer;
	t_node *last_ptr;
	int i;

	i = 1;
	pnt = nodelst->a_head;
	ghost_pointer = malloc(sizeof(t_node));
	last_ptr =  ft_return_specific_node(nodelst,ft_iterate_stack(nodelst,'a'),'a');
	last_ptr->next = ghost_pointer;
	ghost_pointer->next = NULL;
	while(pnt->next)
	{
		i++;
		pnt = pnt->next;
	}
	last_ptr->next = NULL;
	free(ghost_pointer);
	nodelst->stacklen = i - 1;
}
