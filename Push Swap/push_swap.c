/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsmith <jsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 07:57:04 by jsmith            #+#    #+#             */
/*   Updated: 2022/02/10 13:33:00 by jsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_nodelst *nodelst)
{
	t_node *dummy;
	t_node *sec_dummy;

	if(nodelst->a_head->next && nodelst->a_head)
	{
		dummy = nodelst->a_head->next;
		sec_dummy = nodelst->a_head;
		nodelst->a_head->next = dummy->next;
		nodelst->a_head = dummy;
		nodelst->a_head->next = sec_dummy;	
	}	
}

void	ft_swap_b(t_nodelst *nodelst)
{
	t_node *dummy;
	t_node *sec_dummy;

	if(nodelst->b_head && nodelst->b_head->next)
	{
		dummy = nodelst->b_head->next;
		sec_dummy = nodelst->b_head;
		nodelst->b_head->next = dummy->next;
		nodelst->b_head = dummy;
		nodelst->b_head->next = sec_dummy;	
	}	
}

void	ft_swap_ss(t_nodelst *nodelst)
{
	ft_swap_a(nodelst);
	ft_swap_b(nodelst);
}

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
}

int	ft_iterate_stack(t_nodelst *nodelst, char e)
{
	t_node *pnt;
	int i;

	i = 0;
	if (e == 'a')
	{
		pnt = nodelst->a_head;
		while (pnt->next)
		{
			pnt = pnt->next;
			i++;
		}
			return (i);
	}	
	else
		pnt = nodelst->b_head;
		while (pnt->next)
		{
			pnt = pnt->next;
			i++;
		}
	return (i);
}

t_node *ft_return_specific_node(t_nodelst *nodelst, int last, char e)
{
	t_node *spec_node;
	int i;

	i = 0;
	if(e == 'a')
	{
		spec_node = nodelst->a_head;
		while(i != last)
		{
			spec_node = spec_node->next;
			i++;
		}
	}else
		spec_node = nodelst->b_head;
		while(i != last)
		{
			spec_node = spec_node->next;
			i++;
		}
	return (spec_node);
}

void	ft_minirotate_a(t_nodelst *nodelst)
{
	t_node *head_node;
	t_node *last_node;
	t_node *aux_node;

	head_node = nodelst->a_head;
	aux_node = nodelst->a_head->next;
	last_node = ft_return_specific_node(nodelst, ft_iterate_stack(nodelst,'a'),'a');
	nodelst->a_head = last_node;
	last_node->next = aux_node;
	aux_node->next = head_node;
	head_node->next = NULL;
}

void	ft_rotate_a(t_nodelst *nodelst)
{
	t_node *head_node;
	t_node *second_node;
	t_node *penultimate;
	t_node *last_node;
	if(ft_iterate_stack(nodelst,'a') < 1)
	{
		if (ft_iterate_stack(nodelst,'a') == 1)
			ft_minirotate_a(nodelst);
		else
		{
			head_node = nodelst->a_head;
			second_node = nodelst->a_head->next;
			penultimate = ft_return_specific_node(nodelst, ft_iterate_stack(nodelst,'a') -1,'a');
			last_node = ft_return_specific_node(nodelst, ft_iterate_stack(nodelst,'a'),'a');
			nodelst->a_head = last_node;
			last_node->next = second_node;
			penultimate->next = head_node;
			head_node->next = NULL;
		}
	}	
}

/*
void	ft_rotate_b(t_nodelst *nodelst)
{
	t_node *pnt;
	t_node *b_head_pointer;
	t_node *last_node;
	int lstsize;
	int i;

	i = 0;
	pnt = nodelst->b_head;
	last_node = nodelst->b_head;
	b_head_pointer = nodelst->b_head;
	lstsize = ft_iterate_stack(nodelst,'b');
	printf("%d\n",lstsize);
	if(lstsize == 2)
	{
		last_node = b_head_pointer->next;
		last_node->next = b_head_pointer;
		b_head_pointer->next = NULL;
		nodelst->b_head = last_node;
	}
	else
	{
		while(i != lstsize -1)
		{
			pnt = pnt->next;
			i++;
		}
		i = 0;
		while(i != lstsize)
		{
			last_node = last_node->next;
			i++;
		}
		nodelst->b_head = last_node;
		last_node->next = b_head_pointer->next;
		pnt->next = b_head_pointer;
		b_head_pointer->next = NULL;
	}	
}
*/


void	ft_rotate_ab(t_nodelst *nodelst)
{

	
}


int main(int argc, char *argv[])
{
	t_nodelst *nodelst;
	nodelst = ft_manage_entry(argc, argv, nodelst);

	t_node *pointer = ft_return_specific_node(nodelst, ft_iterate_stack(nodelst,'a') -1,'a');
	printf("Ante ultimo numero %d\n", pointer->nbr);
	//ft_swap_a(nodelst);
	//ft_swap_b(nodelst);
	//ft_swap_ss(nodelst);
	//ft_push_b(nodelst);
	//ft_push_b(nodelst);
	//ft_push_b(nodelst);
	//ft_push_b(nodelst);
	ft_rotate_a(nodelst);
	ft_print_stack_a(nodelst);
	ft_print_stack_b(nodelst);
	printf("\n------------------------------\n\n");

    return (0);
}