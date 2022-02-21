/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsmith <jsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 07:57:04 by jsmith            #+#    #+#             */
/*   Updated: 2022/02/21 11:29:42 by jsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Include/push_swap.h"

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
			return (1);
		node = node->next;	
	}
	last_ptr->next = NULL;
	free(ghost_pointer);
	return (0);
}

int	ft_where_is_node_in_stack(t_nodelst *nodelst, int nbr)
{
	t_node *pnt;
	t_node *ghost_pointer;
	t_node *last_ptr;
	int i;


	i  = 1;
	pnt = nodelst->a_head;
	ghost_pointer = malloc(sizeof(t_node));
	last_ptr =  ft_return_specific_node(nodelst,ft_iterate_stack(nodelst,'a'),'a');
	last_ptr->next = ghost_pointer;
	ghost_pointer->next = NULL;
	while(pnt->next)
	{
		if (pnt->nbr == nbr)
		{
			last_ptr->next = NULL;
			free(ghost_pointer);
			return (i);
		}		
		i++;
		pnt = pnt->next;
	}
	last_ptr->next = NULL;
	free(ghost_pointer);
	return (i);
}

t_node 	*ft_return_node_by_pos(t_nodelst *nodelst, int position)
{
	t_node	*pnt;
	t_node *ghost_pointer;
	t_node *last_ptr;
	int i;

	i  = 1;
	pnt = nodelst->a_head;
	ghost_pointer = malloc(sizeof(t_node));
	last_ptr = ft_return_specific_node(nodelst,ft_iterate_stack(nodelst,'a'),'a');
	last_ptr->next = ghost_pointer;
	ghost_pointer->next = NULL;
	while(pnt->next)
	{
		if (pnt->position == position)
		{
			last_ptr->next = NULL;
			free(ghost_pointer);
			return (pnt);
		}		
		i++;
		pnt = pnt->next;
	}
	last_ptr->next = NULL;
	free(ghost_pointer);
	return (pnt);
}

void ft_get_middle(t_nodelst *nodelst)
{
	t_node *pointer;
	int middle;

	pointer = ft_return_biggst_pointer(nodelst);
	middle = pointer->position / 2;
	if(middle == 1)
		middle+=1;
	nodelst->middle = ft_return_node_by_pos(nodelst,middle);
}

void		ft_refresh_stacklen(t_nodelst *nodelst)
{	
	t_node *pnt;
	t_node *ghost_pointer;
	t_node *last_ptr;
	int i;


	i  = 1;
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
	nodelst->stacklen = i -1;
}

void	ft_push_lower_middle(t_nodelst *nodelst)
{
	t_node *lowst_ptr;
	int i;

	i = 1;
	lowst_ptr = ft_return_biggst_pointer(nodelst);
	while(i != nodelst->middle->position +1)
	{
		ft_refresh_stacklen(nodelst);
		if(ft_where_is_node_in_stack(nodelst,ft_return_node_by_pos(nodelst,i)->nbr) <= nodelst->stacklen/2)
			while(ft_return_node_by_pos(nodelst,i) != nodelst->a_head)	
					ft_rotate_a(nodelst);
		else
			while(ft_return_node_by_pos(nodelst,i) != nodelst->a_head)	
				ft_reverse_rotate_a(nodelst);	
		ft_push_b(nodelst);
		i++;
	}	
}

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
	while(i->next)
	{
		if(u > i->nbr)
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

void	ft_order_higher_middle(t_nodelst *nodelst)
{
	t_node *last_node;

	last_node = ft_return_specific_node(nodelst,ft_iterate_stack(nodelst,'a'),'a');
	while(ft_check_nodeorder(nodelst))
	{
			ft_rotate_a(nodelst);
		if(nodelst->a_head->position -1  == nodelst->a_head->next->position)
			ft_swap_a(nodelst);
			ft_rotate_a(nodelst);
	}
	while(nodelst->b_head)
		ft_push_a(nodelst);
}

void	ft_ordenate_3_stack(t_nodelst *nodelst)
{
	int middle;

	middle = ft_where_is_node_in_stack(nodelst,ft_return_node_by_pos(nodelst,nodelst->middle->position)->nbr);
	if (middle == 1 && nodelst->a_head->next->nbr < nodelst->middle->nbr)
		ft_swap_a(nodelst);
	else if(middle == 1 && nodelst->a_head->next->nbr > nodelst->middle->nbr)
		ft_reverse_rotate_a(nodelst);
	else if(middle == 2)
	{
		ft_swap_a(nodelst);
		ft_reverse_rotate_a(nodelst);
	}
	else
	{
		if (ft_return_biggst_pointer(nodelst) == nodelst->a_head)
			ft_rotate_a(nodelst);
		else
		{
			ft_swap_a(nodelst);
			ft_rotate_a(nodelst);
		}
	}
}


void	push_swap(t_nodelst *nodelst)
{
	ft_refresh_stacklen(nodelst);
	if(nodelst->stacklen == 2)
		ft_swap_a(nodelst);
	else if(nodelst->stacklen == 3)
		ft_ordenate_3_stack(nodelst);
	else if (nodelst->stacklen < 10)
	{
		ft_push_lower_middle(nodelst);
		ft_order_higher_middle(nodelst);
	}
	else
	{
		
	}
}


int main(int argc, char *argv[])
{
	t_nodelst *nodelst;
	
	nodelst = ft_manage_entry(argc, argv, nodelst);
	ft_generate_positions(nodelst);
	ft_get_middle(nodelst);
	push_swap(nodelst);
	//ft_print_stack_a(nodelst);
	//ft_print_stack_b(nodelst);
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


