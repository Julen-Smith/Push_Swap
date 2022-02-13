/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsmith <jsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 07:57:04 by jsmith            #+#    #+#             */
/*   Updated: 2022/02/13 02:03:01 by jsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Include/push_swap.h"

int main(int argc, char *argv[])
{
	t_nodelst *nodelst;
	nodelst = ft_manage_entry(argc, argv, nodelst);

	t_node *pointer = ft_return_specific_node(nodelst, ft_iterate_stack(nodelst,'a') -1,'a');
	printf("Ante ultimo numero %d\n", pointer->nbr);
	//ft_swap_a(nodelst);
	//ft_swap_b(nodelst);
	//ft_swap_ss(nodelst);
	
	printf("\n------------------------------\n\n");
	ft_print_stack_a(nodelst);
	ft_print_stack_b(nodelst);
	ft_push_b(nodelst);
	ft_push_b(nodelst);
	ft_push_b(nodelst);
	ft_push_b(nodelst);
	printf("\n------------------------------\n\n");
	ft_print_stack_a(nodelst);
	ft_print_stack_b(nodelst);
	ft_reverse_rotate_rr(nodelst);
	ft_print_stack_a(nodelst);
	ft_print_stack_b(nodelst);
	printf("\n------------------------------\n\n");

    return (0);
}