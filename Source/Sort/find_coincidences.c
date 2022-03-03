/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_coincidences.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsmith <jsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 18:58:07 by jsmith            #+#    #+#             */
/*   Updated: 2022/03/03 08:45:42 by jsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

/*
*
*	Coincidencias por posición respecto al tamaño del chunk
*
*/

void ft_find_first_coincidence_from_top(t_nodelst *nodelst,int chunksize)
{
	t_node *dummy;
	int i;

	dummy = nodelst->a_head;
	i = 0;
	while(dummy && dummy->next)
	{
		if (dummy->position < chunksize)
		{	
			nodelst->nbrfromtop = i;
			return ;
		}
		i++;
		dummy = dummy->next;
	}
}

void ft_find_first_coincidence_from_bottom(t_nodelst *nodelst,int chunksize)
{
	t_node *node;
	int i;

	i = 1;
	node = ft_return_last_ptr(nodelst);
	ft_generate_previus_values(nodelst);
	while(node && node->previus)
	{
		if (node->position < chunksize)
		{	
			nodelst->nbrfrombottom = i;
			return ;
		}		
		i++;
		node = node->previus;
	}
}

/*
*
*	Coincidencias por posición
*
*/

int ft_find_moves_from_top(t_nodelst *nodelst, int position)
{
	t_node *dummy;
	int i;

	
	i = 0;
	if (nodelst->b_head)
		dummy = nodelst->b_head;
	while(dummy && dummy->next)
	{
		if (dummy->position == position)
		{
			printf("Encuentro coincidencia en top con la posición %d\n",dummy->position);
			//ft_print_stack_b(nodelst);
			printf("He dado estas vueltas : %d\n",i);
			return (i);
		}	
		i++;
		dummy = dummy->next;
	}
	return (i);
}

int	ft_find_moves_from_bottom(t_nodelst *nodelst,int position)
{
	t_node *node;
	int i;

	i = 1;
	node = ft_return_last_ptr_b_edition(nodelst);
	ft_generate_previus_values_on_b(nodelst);
	while(node && node->previus)
	{	
		if (node->position == position)
			return (i);
		i++;
		node = node->previus;
	}
	return (i);
}
