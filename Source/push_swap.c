/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsmith <jsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 07:57:04 by jsmith            #+#    #+#             */
/*   Updated: 2022/02/13 03:16:51 by jsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Include/push_swap.h"


int	ft_find_lowerest_node(t_nodelst *lst)
{
	t_node *point;
	int lowst;
	t_node *actualize_pointer;
	

	point = lst->a_head;
	lowst = point->nbr;
	while(point->next)
	{
		if (point->nbr < lowst)
		{
			lowst = point->nbr;
			actualize_pointer = point;
		}
			
		point = point->next;
	}
	actualize_pointer->position = 1;
	return (lowst);
}

void	ft_generate_positions(t_nodelst *lst)
{
	int i;
	int quant;
	t_node *point;
	int lowst;
	int cache;
	t_node *actualize_pointer;

	i = 2;
	cache = 2147483647;
	quant = ft_iterate_stack(lst,'a') + 1;
	lowst = ft_find_lowerest_node(lst);
	actualize_pointer = lst->a_head;
	while(i != quant)
	{
		point = lst->a_head;
		while(point->next)
		{
			if (point->nbr < cache  && point->nbr > actualize_pointer->nbr)
			{
				cache = point->nbr;
				actualize_pointer = point;	
			}	
			point = point->next;
		}
		actualize_pointer->position = i;
		i++;
	}	
}

int main(int argc, char *argv[])
{
	t_nodelst *nodelst;
	
	nodelst = ft_manage_entry(argc, argv, nodelst);
	ft_generate_positions(nodelst);
	
	ft_print_stack_a(nodelst);
	ft_print_stack_b(nodelst);
    return (0);
}

	

/*
	printf("\n------------------------------\n\n");
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


