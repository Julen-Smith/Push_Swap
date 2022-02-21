/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsmith <jsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 01:46:28 by jsmith            #+#    #+#             */
/*   Updated: 2022/02/21 09:15:37 by jsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/push_swap.h"

void	ft_swap_a(t_nodelst *nodelst)
{
	t_node *new_head;
	t_node *sec_dummy;
	t_node *connector;

	if(nodelst->a_head->next && nodelst->a_head)
	{
		new_head = nodelst->a_head->next;
		sec_dummy = nodelst->a_head;
		connector = new_head->next;
		nodelst->a_head = new_head;
		new_head->next = sec_dummy;
		sec_dummy->next = connector;
	}
	printf("swap_a\n");	
}

void	ft_swap_b(t_nodelst *nodelst)
{
	t_node *dummy;
	t_node *sec_dummy;

	if(nodelst->b_head && nodelst->b_head->next)
	{
		dummy = nodelst->b_head->next;
		sec_dummy = nodelst->b_head;
		nodelst->b_head->next = dummy->next;
		nodelst->b_head = dummy;
		nodelst->b_head->next = sec_dummy;	
	}	
}

void	ft_swap_ss(t_nodelst *nodelst)
{
	ft_swap_a(nodelst);
	ft_swap_b(nodelst);
}