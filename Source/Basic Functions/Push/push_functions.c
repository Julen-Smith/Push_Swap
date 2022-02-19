/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsmith <jsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 01:44:29 by jsmith            #+#    #+#             */
/*   Updated: 2022/02/18 20:06:09 by jsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/push_swap.h"

void	ft_push_a(t_nodelst *nodelst)
{
	t_node *a_head_pointer;
	t_node *b_head_pointer;

	if (nodelst->b_head)
	{
		b_head_pointer = nodelst->b_head;             //cojo primer elemento de b;
		if (b_head_pointer->next)		            //si primer elemento de b tiene algo detras. Se convierte en la cabeza.
			nodelst->b_head = b_head_pointer->next;
		else
			nodelst->b_head = NULL;              //si la cabeza de a tiene algo
		if(nodelst->a_head)
		{
			a_head_pointer = nodelst->a_head;	//a dummy lo coje
			nodelst->a_head = b_head_pointer;  //la nueva cabeza pasa a ser lo que habia en b;
			b_head_pointer->next = a_head_pointer;  //y el siguiente de dummy pasa a ser la antigua cabeza.
		}
		else                      //Si no se coje directamente la antigua cabeza.
		{
			nodelst->a_head = b_head_pointer;
			nodelst->a_head->next = NULL;
		}			
	}
}

void	ft_push_b(t_nodelst *nodelst)
{
	t_node *a_head_pointer;
	t_node *b_head_pointer;

	if (nodelst->a_head)
	{
		a_head_pointer = nodelst->a_head;
		if (a_head_pointer->next)
			nodelst->a_head = a_head_pointer->next;
		else
			nodelst->a_head = NULL;
		if(nodelst->b_head)
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
	printf("push_b\n");
}
