/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsmith <jsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 01:52:23 by jsmith            #+#    #+#             */
/*   Updated: 2022/02/18 20:06:34 by jsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/push_swap.h"

void	ft_reverse_rotate_a(t_nodelst *nodelst)
{
	t_node *head_node;
	t_node *penultimate;
	t_node *last_node;
	
	if(nodelst->a_head)
	{
		head_node = nodelst->a_head;
		last_node = ft_return_last_ptr(nodelst);
		penultimate = ft_return_specific_node(nodelst,ft_iterate_stack(nodelst,'a')-1,'a');
		nodelst->a_head = last_node;
		last_node->next = head_node;
		penultimate->next = NULL;
	}
	printf("rra\n");
}

void	ft_reverse_rotate_b(t_nodelst *nodelst)
{
	t_node *head_node;
	t_node *penultimate;
	t_node *last_node;
	
	if(nodelst->b_head)
	{
		head_node = nodelst->b_head;
		last_node = ft_return_specific_node(nodelst,ft_iterate_stack(nodelst,'b'),'b');
		penultimate = ft_return_specific_node(nodelst,ft_iterate_stack(nodelst,'b')-1,'b');
		nodelst->b_head = last_node;
		last_node->next = head_node;
		penultimate->next = NULL;
	}
	printf("rrb\n");
}

void	ft_reverse_rotate_rr(t_nodelst *nodelst)
{
	ft_reverse_rotate_a(nodelst);
	ft_reverse_rotate_b(nodelst);
}
