/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsmith <jsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 07:57:04 by jsmith            #+#    #+#             */
/*   Updated: 2022/02/16 21:48:46 by jsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Include/push_swap.h"

int	ft_check_if_we_still_have_middles(t_nodelst *nodelst)
{
	t_node *node;

	while(node->next)
	{
		if (node->nbr < nodelst->middle->nbr)
			return (1);
		node = node->next;	
	}
	return (0);
}

void	ft_choose_path(t_nodelst *nodelst)
{
	
}

void	ft_move_low_middle_to_b(t_nodelst *nodelst)
{
	while(ft_check_if_we_still_have_middles(nodelst))
		ft_choose_path(nodelst);

}

void	push_swap(t_nodelst *nodelst)
{
	ft_move_low_middle_to_b(nodelst);
	//ft_order_high_middle(nodelst);
	//ft_order_low_middle(nodelst);
	//ft_push_low middle(nodelst);	
	
}

void ft_get_middle(t_nodelst *nodelst)
{
	t_node *pointer;
	int middle;

	pointer = ft_return_specific_node(nodelst,ft_iterate_stack(nodelst,'a'),'a');
	middle = pointer->position / 2; 
	pointer = ft_return_specific_node(nodelst,ft_iterate_stack(nodelst,'a') - middle,'a');
	nodelst->a_head = pointer;
}

int main(int argc, char *argv[])
{
	t_nodelst *nodelst;
	
	nodelst = ft_manage_entry(argc, argv, nodelst);
	ft_generate_positions(nodelst);
	ft_get_middle(nodelst);
	push_swap(nodelst);
	ft_print_stack_a(nodelst);
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


