/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsmith <jsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 07:57:04 by jsmith            #+#    #+#             */
/*   Updated: 2022/02/15 12:12:33 by jsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Include/push_swap.h"

t_node *ft_return_lowst_pointer(t_nodelst *lst)
{
	t_node *pnt;
	t_node *dummy;

	pnt = lst->a_head;
	dummy = lst->a_head;
	while (pnt->next)
	{
		if (pnt->nbr < dummy->nbr)
			dummy = pnt;
		pnt = pnt->next;
	}
	if (pnt->nbr < dummy->nbr)
		dummy = pnt;
	dummy->position = 1;
	return (dummy);
}

t_node *ft_return_biggst_pointer(t_nodelst *lst)
{
	t_node *pnt;
	t_node *dummy;

	pnt = lst->a_head;
	dummy = lst->a_head;
	while (pnt->next)
	{
		if (pnt->nbr > dummy->nbr)
			dummy = pnt;
		pnt = pnt->next;
	}
	if (pnt->nbr > dummy->nbr)
		dummy = pnt;
	dummy->position = ft_iterate_stack(lst,'a') +1;
	return (dummy);
}

t_node	*ft_order(t_nodelst *lst, t_node *actual_node, int i)
{
	t_node *hp;
	t_node *target;

	hp = lst->a_head;
	while(hp->next)
	{	
		while(hp->nbr < actual_node->nbr && hp->next)
		{
				printf("Acelero posiciones por ser menores a la buscada\n");
				printf("%d\n",hp->nbr);
				hp = hp->next;
			
		}
			if (!hp->next)
			{
				printf("f\n");
				return (0);
			}
				
			printf("Acelero posiciones por ser menores a la buscada\n");
			//hp = hp->next;
		if (hp->nbr > actual_node->nbr)
			printf("Se descubre nuevo numero superior\n");
			//target = hp;
		if(hp->nbr < target->nbr)
			printf("Si se descubre un numero numero entre los dos se asigna\n");
			//target = hp;
		hp = hp->next;
	}	
	return (hp);
}

void	ft_generate_positions(t_nodelst *lst)
{
	t_node *low;
	t_node *hp;
	t_node *dummy;
	int i;
	
	i = 2;	
	low	= ft_return_lowst_pointer(lst);
	hp = lst->a_head;
	while(hp->next)
	{
		printf("Buscando el numero = %d\n", i);
		dummy = ft_order(lst, hp, i);
		dummy->position = i;
		hp = hp->next;
		i++;
	}
}


int main(int argc, char *argv[])
{
	t_nodelst *nodelst;
	
	nodelst = ft_manage_entry(argc, argv, nodelst);
	// ft_find_lowerest_node(nodelst);
	ft_generate_positions(nodelst);
	ft_print_stack_a(nodelst);
	ft_print_stack_b(nodelst);
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


