/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsmith <jsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 07:57:04 by jsmith            #+#    #+#             */
/*   Updated: 2022/02/19 00:37:21 by jsmith           ###   ########.fr       */
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
	last_ptr  = ft_return_specific_node(nodelst,ft_iterate_stack(nodelst,'a'),'a');
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
	nodelst->middle = ft_return_node_by_pos(nodelst,middle);
}

void	push_swap(t_nodelst *nodelst)
{
	t_node *lowst_ptr;
	int i;

	i = 0;
	lowst_ptr = ft_return_biggst_pointer(nodelst);
	while(i != nodelst->middle->position)
	{
		lowst_ptr = ft_return_lowst_pointer(nodelst);
		if(ft_where_is_node_in_stack(nodelst,lowst_ptr->nbr) < ft_where_is_node_in_stack(nodelst, nodelst->middle->nbr))	
			ft_rotate_a(nodelst);
		else
			ft_reverse_rotate_a(nodelst);	
		i++;
		ft_push_b(nodelst);
	}

}


int main(int argc, char *argv[])
{
	t_nodelst *nodelst;
	
	nodelst = ft_manage_entry(argc, argv, nodelst);
	ft_generate_positions(nodelst);
	ft_get_middle(nodelst);
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


