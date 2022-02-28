/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsmith <jsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 07:57:04 by jsmith            #+#    #+#             */
/*   Updated: 2022/02/28 16:34:41 by jsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Include/push_swap.h"

t_node *ft_return_last_ptr(t_nodelst *lst)
{
	t_node *pnt;

	pnt = lst->a_head;
	while(pnt && pnt->next)
	{
		pnt = pnt->next;
	}
	return (pnt);

}
int	ft_count_key_number_values(t_nodelst *nodelst, int chunksize, int max)
{
	t_node *i;
	int u;
	t_node *ghost_ptr;
	t_node *last_node;

	i = nodelst->a_head;
	last_node = ft_return_specific_node(nodelst,ft_iterate_stack(nodelst,'a'),'a');
	ghost_ptr = malloc (sizeof(t_node));
	last_node->next = ghost_ptr;
	while(i->next)
	{
		if(i->position <= chunksize && i->position >= max)
			u++;
		i = i->next;
	}
	last_node->next = NULL;
	free(ghost_ptr);	
	return (u);
}

void	ft_push_chunk_nbr(t_nodelst *nodelst, int chunksize, int lastchunksize)
{
	int max;
	int i;

	i = 1;
	max = ft_count_key_number_values(nodelst, chunksize, lastchunksize);
	while(i != max)
	{
		if(nodelst->a_head->position < chunksize)
		{
			ft_push_b(nodelst);
			i++;
		}
		else
			ft_rotate_a(nodelst);
	}
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
	/*else if(nodelst->stacklen < 100)
	{
		nodelst->chunksize = nodelst->stacklen/4;
		initial_chunksize = nodelst->chunksize;
		while(i != 3)
		{			
			if (nodelst->chunksize == nodelst->stacklen/4)
				initial_chunksize = 0;
			ft_push_chunk_nbr(nodelst,nodelst->chunksize, nodelst->chunksize - initial_chunksize);
			initial_chunksize =  nodelst->stacklen/4;
			nodelst->chunksize += initial_chunksize;
			i++;
		}
	}
	*/
}


int main(int argc, char *argv[])
{
	t_nodelst *nodelst;
	
	nodelst = ft_manage_entry(argc, argv, nodelst);
	ft_generate_positions(nodelst);
	//printf("%d\n", nodelst->middle->nbr);
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


