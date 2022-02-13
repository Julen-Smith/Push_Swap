/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsmith <jsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 01:46:28 by jsmith            #+#    #+#             */
/*   Updated: 2022/02/13 01:54:52 by jsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/push_swap.h"

void	ft_swap_a(t_nodelst *nodelst)
{
	t_node *dummy;
	t_node *sec_dummy;

	if(nodelst->a_head->next && nodelst->a_head)
	{
		dummy = nodelst->a_head->next;
		sec_dummy = nodelst->a_head;
		nodelst->a_head->next = dummy->next;
		nodelst->a_head = dummy;
		nodelst->a_head->next = sec_dummy;	
	}	
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