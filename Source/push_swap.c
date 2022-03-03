/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsmith <jsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 07:57:04 by jsmith            #+#    #+#             */
/*   Updated: 2022/03/03 11:51:05 by jsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Include/push_swap.h"

void	push_swap(t_nodelst *nodelst)
{
	ft_refresh_stacklen(nodelst);
	if (nodelst->stacklen == 2)
		ft_swap_a(nodelst);
	else if (nodelst->stacklen == 3)
		ft_ordenate_3_stack(nodelst);
	else if (nodelst->stacklen < 10)
		ft_ordenate_10_stack(nodelst);
	else if (nodelst->stacklen <= 100)
		ft_ordenate_100_stack(nodelst);
	else
		ft_ordenate_500_stack(nodelst);
}

int	main(int argc, char *argv[])
{
	t_nodelst	*nodelst;
	t_node		*dummy;

	nodelst = ft_manage_entry(argc, argv, nodelst);
	ft_generate_positions(nodelst);
	push_swap(nodelst);
	ft_print_stack_a(nodelst);
	ft_print_stack_b(nodelst);
	while (nodelst->a_head->next)
	{
		dummy = nodelst->a_head;
		nodelst->a_head = nodelst->a_head->next;
		free(dummy);
	}
	free(nodelst->a_head);
	free(nodelst);
	return (0);
}
