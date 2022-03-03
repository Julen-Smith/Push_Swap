/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsmith <jsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 21:09:55 by jsmith            #+#    #+#             */
/*   Updated: 2022/03/03 13:22:57 by jsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

t_node	*ft_order(t_nodelst *lst)
{
	t_node	*hp;
	t_node	*dummy;
	t_node	*last_node;
	t_node	*ghost_pointer;

	hp = lst->a_head;
	dummy = ft_return_biggst_pointer(lst, 'a');
	last_node = ft_return_specific_node(lst, ft_iterate_stack(lst, 'a'), 'a');
	ghost_pointer = malloc (sizeof(t_node));
	last_node->next = ghost_pointer;
	ghost_pointer->next = NULL;
	while (hp->next)
	{	
		if (hp->position < 0)
		{
			if (hp->nbr < dummy->nbr)
				dummy = hp;
		}		
		hp = hp->next;
	}
	last_node->next = NULL;
	free(ghost_pointer);
	return (dummy);
}

void	ft_generate_positions(t_nodelst *lst)
{
	t_node	*hp;
	t_node	*dummy;
	int		i;

	i = 1;
	hp = lst->a_head;
	ft_initialize_positions(lst);
	while (hp && hp->next)
	{
		dummy = ft_order(lst);
		dummy->position = i;
		i++;
		hp = hp->next;
	}
	ft_return_biggst_pointer(lst, 'a')->position = i;
}

t_node	*ft_return_last_ptr(t_nodelst *lst)
{
	t_node	*pnt;

	pnt = lst->a_head;
	while (pnt && pnt->next)
		pnt = pnt->next;
	return (pnt);
}

int	ft_find_the_lowerest_pos(t_nodelst *nodelst)
{
	t_node	*pnt;
	t_node	*ghost_pointer;
	t_node	*last_ptr;
	int		position;

	pnt = nodelst->a_head;
	ghost_pointer = malloc(sizeof(t_node));
	last_ptr = ft_return_last_ptr(nodelst);
	last_ptr->next = ghost_pointer;
	ghost_pointer->next = NULL;
	while (pnt->next)
	{
		if (pnt->position > pnt->next->position)
			position = pnt->position;
		pnt = pnt->next;
	}
	last_ptr->next = NULL;
	free(ghost_pointer);
	return (position);
}

t_node	*ft_return_last_ptr_b_edition(t_nodelst *lst)
{
	t_node	*pnt;

	pnt = lst->a_head;
	if (lst->b_head)
		pnt = lst->b_head;
	while (pnt && pnt->next)
		pnt = pnt->next;
	return (pnt);
}
