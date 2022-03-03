/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsmith <jsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 01:48:12 by jsmith            #+#    #+#             */
/*   Updated: 2022/03/03 11:07:01 by jsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/push_swap.h"

void	ft_rotate_a(t_nodelst *lst)
{
	t_node	*head_node;
	t_node	*second_node;
	t_node	*ln;

	if (lst->a_head)
	{
		head_node = lst->a_head;
		second_node = head_node->next;
		ln = ft_return_specific_node(lst, ft_iterate_stack(lst, 'a'), 'a');
		ln->next = head_node;
		head_node->next = NULL;
		lst->a_head = second_node;
	}
	printf("ra\n");
}

void	ft_rotate_b(t_nodelst *lst)
{
	t_node	*head_node;
	t_node	*second_node;
	t_node	*ln;

	if (lst->b_head)
	{
		head_node = lst->b_head;
		second_node = head_node->next;
		ln = ft_return_specific_node(lst, ft_iterate_stack(lst, 'b'), 'b');
		ln->next = head_node;
		head_node->next = NULL;
		lst->b_head = second_node;
	}
	printf("rb\n");
}

void	ft_rotate_rr(t_nodelst *nodelst)
{
	ft_rotate_a(nodelst);
	ft_rotate_b(nodelst);
}
