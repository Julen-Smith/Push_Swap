/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsmith <jsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 07:57:04 by jsmith            #+#    #+#             */
/*   Updated: 2022/02/28 18:52:14 by jsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Include/push_swap.h"

t_node *ft_return_last_ptr(t_nodelst *lst)
{
	t_node *pnt;

	pnt = lst->a_head;
	while(pnt && pnt->next)
		pnt = pnt->next;
	return (pnt);
}

int ft_find_the_lowerest_pos(t_nodelst *nodelst)
{
	t_node	*pnt;
	t_node *ghost_pointer;
	t_node *last_ptr;
	int position;

	pnt = nodelst->a_head;
	ghost_pointer = malloc(sizeof(t_node));
	last_ptr = ft_return_specific_node(nodelst,ft_iterate_stack(nodelst,'a'),'a');
	last_ptr->next = ghost_pointer;
	ghost_pointer->next = NULL;
	while(pnt->next)
	{
		if (pnt->position > pnt->next->position)
			position = pnt->position;
		pnt = pnt->next;
	}
	last_ptr->next = NULL;
	free(ghost_pointer);
	return (position);
}

int	ft_is_in_the_middle_of_the_stack(t_nodelst *nodelst, int nodepos)
{
	int middlestacklen;
	
	ft_refresh_stacklen(nodelst);
	middlestacklen = nodelst->stacklen/2;
	if (middlestacklen == 3)
		return (0);
	if(ft_where_is_node_in_stack(nodelst,ft_return_node_by_pos(nodelst,nodepos)->nbr) <= middlestacklen)
		return (1);
	else
		return (0);
}

void	ft_ordenate_10_stack(t_nodelst *nodelst)
{
	t_node *lowst_ptr;
	int i;

	i = 1;
	lowst_ptr = ft_return_biggst_pointer(nodelst);
	while(ft_check_nodeorder(nodelst) && nodelst->stacklen > 3)
	{
		if(ft_is_in_the_middle_of_the_stack(nodelst,i))
			while(ft_return_node_by_pos(nodelst,i) != nodelst->a_head && nodelst->stacklen > 3)	
				ft_rotate_a(nodelst);
		else
			while(ft_return_node_by_pos(nodelst,i) != nodelst->a_head && nodelst->stacklen > 3)		
				ft_reverse_rotate_a(nodelst);
		i++;
		ft_push_b(nodelst);
		ft_refresh_stacklen(nodelst);
	}
	if(nodelst->stacklen == 3 && ft_check_nodeorder(nodelst))
		ft_ordenate_3_stack(nodelst);
	while(nodelst->b_head)
		ft_push_a(nodelst);
}

void ft_find_first_coincidence_from_top(t_nodelst *nodelst,int chunksize)
{
	t_node *dummy;
	int i;

	dummy = nodelst->a_head;
	i = 0;
	while(dummy && dummy->next)
	{
		if (dummy->position < chunksize)
		{	
			nodelst->nbrfromtop = i;
			return ;
		}
		i++;
		dummy = dummy->next;
	}
}

void	ft_generate_previus_values(t_nodelst *nodelst)
{
	t_node *node;
	t_node *nodenext;

	if(nodelst->a_head)
	{
		node = nodelst->a_head;
		node->previus = NULL;
		nodenext = nodelst->a_head->next;
		while(nodenext && node && nodenext->next)
		{
			nodenext->previus = node;
			node = node->next;
			nodenext = nodenext->next;
		}
		if(nodenext && node)
			nodenext->previus = node;
	}
}

void ft_find_first_coincidence_from_bottom(t_nodelst *nodelst,int chunksize)
{
	t_node *node;
	int i;

	i = 1;
	node = ft_return_last_ptr(nodelst);
	ft_generate_previus_values(nodelst);
	while(node && node->previus)
	{
		if (node->position < chunksize)
		{
			nodelst->nbrfrombottom = i;
			return ;
		}		
		i++;
		node = node->previus;
	}
}

void	ft_ordenate_100_stack(t_nodelst *nodelst)
{
	t_node * big;
	int initial_chunk;
	int position;
	int i;

	i = 0;
	position = 0;
	big = ft_return_biggst_pointer(nodelst);
	ft_refresh_stacklen(nodelst);
	nodelst->chunksize = nodelst->stacklen/ 4;
	initial_chunk = nodelst->chunksize;
	while(nodelst->a_head)
	{
		i = 0;
		while(i != initial_chunk)
		{
			ft_find_first_coincidence_from_top(nodelst,nodelst->chunksize);
			ft_find_first_coincidence_from_bottom(nodelst,nodelst->chunksize);
			if(nodelst->nbrfromtop < nodelst->nbrfrombottom)
				while(nodelst->nbrfromtop != 0)
				{
					ft_rotate_a(nodelst);
					nodelst->nbrfromtop--;
				}	
			else
				while(nodelst->nbrfrombottom != 0)
				{
					ft_reverse_rotate_b(nodelst);
					nodelst->nbrfrombottom--;
				}
			if (nodelst->a_head)
				printf("El numero pusheado es %d con posición %d\n",nodelst->a_head->nbr, nodelst->a_head->position);
			ft_push_b(nodelst);
			i++;
		}
		nodelst->chunksize += initial_chunk;
	}
}

void	push_swap(t_nodelst *nodelst)
{
	int i;
	int initial_chunksize;

	i = 0;
	ft_refresh_stacklen(nodelst);
	if(nodelst->stacklen == 2)
		ft_swap_a(nodelst);
	else if(nodelst->stacklen == 3)
		ft_ordenate_3_stack(nodelst);
	else if (nodelst->stacklen < 10)
		ft_ordenate_10_stack(nodelst);
	else if(nodelst->stacklen < 100)
		ft_ordenate_100_stack(nodelst);
}

int main(int argc, char *argv[])
{
	t_nodelst *nodelst;
	
	nodelst = ft_manage_entry(argc, argv, nodelst);
	ft_generate_positions(nodelst);
	push_swap(nodelst);
	ft_print_stack_a(nodelst);
	ft_print_stack_b(nodelst);
	
	return (0);
}

/*
	printf("\n-----------------------------\n\n");
	ft_print_stack_a(nodelst);
	ft_print_stack_b(nodelst);
	ft_push_b(nodelst);
	ft_push_b(nodelst);
	ft_push_b(nodelst);
	ft_push_b(nodelst);
	printf("\n------------------------------\n\n");
	
	ft_reverse_rotate_rr(nodelst);
	ft_print_stack_a(nodelst);
	ft_print_stack_b(nodelst);
	printf("\n------------------------------\n\n");
*/


