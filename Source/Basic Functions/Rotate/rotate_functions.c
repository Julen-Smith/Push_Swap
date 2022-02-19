/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsmith <jsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 01:48:12 by jsmith            #+#    #+#             */
/*   Updated: 2022/02/18 20:06:25 by jsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/push_swap.h"

void	ft_rotate_a(t_nodelst *nodelst)
{
	t_node *head_node;
	t_node *second_node;
	t_node *last_node;
	
	if (nodelst->a_head)
	{
		head_node = nodelst->a_head;
		second_node = head_node->next;
		last_node = ft_return_specific_node(nodelst,ft_iterate_stack(nodelst,'a'),'a');
		last_node->next = head_node;
		head_node->next = NULL;
		nodelst->a_head = second_node;
	}
	printf("ra\n");

}

void	ft_rotate_b(t_nodelst *nodelst)
{
	t_node *head_node;
	t_node *second_node;
	t_node *last_node;

	if(nodelst->b_head)
	{
		head_node = nodelst->b_head;
		second_node = head_node->next;
		last_node = ft_return_specific_node(nodelst,ft_iterate_stack(nodelst,'b'),'b');
		last_node->next = head_node;
		head_node->next = NULL;
		nodelst->b_head = second_node;
	}
	printf("rb\n");
}

void	ft_rotate_rr(t_nodelst *nodelst)
{
	ft_rotate_a(nodelst);
	ft_rotate_b(nodelst);
}