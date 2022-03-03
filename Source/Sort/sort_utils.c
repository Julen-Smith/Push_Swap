/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsmith <jsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 08:26:17 by jsmith            #+#    #+#             */
/*   Updated: 2022/03/03 13:15:52 by jsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

int	ft_check_nodeorder(t_nodelst *nodelst)
{
	t_node	*i;
	int		u;
	t_node	*ghost_ptr;
	t_node	*ln;

	i = nodelst->a_head->next;
	u = nodelst->a_head->nbr;
	ln = ft_return_specific_node(nodelst, ft_iterate_stack(nodelst, 'a'), 'a');
	ghost_ptr = malloc (sizeof(t_node));
	ln->next = ghost_ptr;
	ghost_ptr->next = NULL;
	while (i && i->next)
	{
		if (u > i->nbr && i)
		{
			ln->next = NULL;
			free(ghost_ptr);
			return (1);
		}
		u = i->nbr;
		i = i->next;
	}
	ln->next = NULL;
	free(ghost_ptr);
	return (0);
}

void	ft_get_middle(t_nodelst *nodelst)
{
	t_node	*big;
	t_node	*small;
	t_node	*head;
	int		middle;

	middle = 0;
	big = ft_return_biggst_pointer(nodelst, 'a');
	small = ft_return_lowst_pointer(nodelst);
	head = nodelst->a_head;
	nodelst->middle = nodelst->a_head;
	while (head->next)
	{
		if (head->nbr < big->nbr && head->nbr > small->nbr)
			nodelst->middle = head;
		head = head->next;
	}
	if (head->nbr > small->nbr && head->nbr < big->nbr)
		nodelst->middle = head;
}

void	ft_refresh_stacklen(t_nodelst *nodelst)
{	
	t_node	*pnt;
	t_node	*last_ptr;
	int		i;

	i = 1;
	pnt = nodelst->a_head;
	last_ptr = ft_return_last_ptr(nodelst);
	while (pnt->next)
	{
		i++;
		pnt = pnt->next;
	}
	nodelst->stacklen = i;
}

void	ft_refresh_stacklen_b(t_nodelst *nodelst)
{	
	t_node	*pnt;
	t_node	*last_ptr;
	int		i;

	i = 1;
	pnt = nodelst->b_head;
	last_ptr = ft_return_last_ptr(nodelst);
	while (pnt->next)
	{
		i++;
		pnt = pnt->next;
	}
	nodelst->stacklen = i;
}
