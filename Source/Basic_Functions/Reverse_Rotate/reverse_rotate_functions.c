/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsmith <jsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 01:52:23 by jsmith            #+#    #+#             */
/*   Updated: 2022/03/03 11:04:32 by jsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/push_swap.h"

void	ft_reverse_rotate_a(t_nodelst *lst)
{
	t_node	*head_node;
	t_node	*pn;
	t_node	*last_node;

	if (lst->a_head)
	{
		head_node = lst->a_head;
		last_node = ft_return_last_ptr(lst);
		pn = ft_return_specific_node(lst, ft_iterate_stack(lst, 'a') - 1, 'a');
		lst->a_head = last_node;
		last_node->next = head_node;
		pn->next = NULL;
	}
	printf("rra\n");
}

void	ft_reverse_rotate_b(t_nodelst *lst)
{
	t_node	*head_node;
	t_node	*pn;
	t_node	*ln;

	if (lst->b_head)
	{
		head_node = lst->b_head;
		ln = ft_return_specific_node(lst, ft_iterate_stack(lst, 'b'), 'b');
		pn = ft_return_specific_node(lst, ft_iterate_stack(lst, 'b') - 1, 'b');
		lst->b_head = ln;
		ln->next = head_node;
		pn->next = NULL;
	}
	printf("rrb\n");
}

void	ft_reverse_rotate_rr(t_nodelst *nodelst)
{
	ft_reverse_rotate_a(nodelst);
	ft_reverse_rotate_b(nodelst);
}
