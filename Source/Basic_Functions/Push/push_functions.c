/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsmith <jsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 01:44:29 by jsmith            #+#    #+#             */
/*   Updated: 2022/03/03 13:44:21 by jsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/push_swap.h"

void	ft_push_a(t_nodelst *nodelst)
{
	t_node	*a_head_pointer;
	t_node	*b_head_pointer;

	if (nodelst->b_head)
	{
		b_head_pointer = nodelst->b_head;
		if (b_head_pointer->next)
			nodelst->b_head = b_head_pointer->next;
		else
			nodelst->b_head = NULL;
		if (nodelst->a_head)
		{
			a_head_pointer = nodelst->a_head;
			nodelst->a_head = b_head_pointer;
			b_head_pointer->next = a_head_pointer;
		}
		else
		{
			nodelst->a_head = b_head_pointer;
			nodelst->a_head->next = NULL;
		}			
	}
	printf("pa\n");
}

void	ft_push_b(t_nodelst *nodelst)
{
	t_node	*a_head_pointer;
	t_node	*b_head_pointer;

	if (nodelst->a_head)
	{
		a_head_pointer = nodelst->a_head;
		if (a_head_pointer->next)
			nodelst->a_head = a_head_pointer->next;
		else
			nodelst->a_head = NULL;
		if (nodelst->b_head)
		{
			b_head_pointer = nodelst->b_head;
			nodelst->b_head = a_head_pointer;
			a_head_pointer->next = b_head_pointer;
		}
		else
		{
			nodelst->b_head = a_head_pointer;
			nodelst->b_head->next = NULL;
		}	
	}
	printf("pb\n");
}
