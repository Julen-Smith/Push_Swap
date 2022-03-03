/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsmith <jsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 09:58:55 by jsmith            #+#    #+#             */
/*   Updated: 2022/03/03 12:20:56 by jsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

t_node	*ft_create_node(void)
{
	t_node	*node;

	node = malloc (sizeof(t_node));
	node->next = NULL;
	return (node);
}

void	ft_destroy_node(t_node *node)
{
	free(node);
}

t_nodelst	*ft_generate_nodelst(char **nbr)
{
	t_nodelst	*list;
	t_node		*last;
	t_node		*new;
	int			i;	

	i = 1;
	list = malloc(sizeof(t_nodelst));
	list->a_head = ft_create_node();
	list->a_head->nbr = ft_atoi(nbr[0]);
	last = list->a_head;
	while (nbr[i])
	{
		new = ft_create_node();
		last->next = new;
		new->nbr = ft_atoi(nbr[i]);
		last = new;
		i++;
	}
	list->b_head = NULL;
	return (list);
}

void	ft_initialize_positions(t_nodelst *lst)
{
	t_node	*pnt;
	t_node	*lp;
	t_node	*ghost_pointer;

	pnt = lst->a_head;
	lp = ft_return_specific_node(lst, ft_iterate_stack(lst, 'a'), 'a');
	ghost_pointer = malloc (sizeof(t_node));
	lp->next = ghost_pointer;
	ghost_pointer->next = NULL;
	while (pnt->next)
	{	
		pnt->position = -1;
		pnt = pnt->next;
	}
	lp->next = NULL;
	free(ghost_pointer);
}
/*
void	ft_print_stack_a(t_nodelst *nodelst)
{
	t_node	*dummy;

	printf("STACK A\n\n");
	if (nodelst->a_head)
	{
		dummy = nodelst->a_head;
		while (dummy->next)
		{
			printf("%d Position : %d\n", dummy->nbr, dummy->position);
			dummy = dummy->next;
		}
		printf("%d Position : %d\n\n", dummy->nbr, dummy->position);	
	}
}

void	ft_print_stack_b(t_nodelst *nodelst)
{
	t_node  *dummy;
	printf("STACK B\n\n");
	if(nodelst->b_head)
	{
		dummy = nodelst->b_head;
		while(dummy->next)
		{
			printf("%d Position : %d\n",dummy->nbr,dummy->position);
		//	if (dummy->previus)
		//		printf("Previus nbr : %d\n",dummy->previus->nbr);
		//	else
		//		printf("NULL\n");
			dummy = dummy->next;
		}
			printf("%d Position : %d\n\n",dummy->nbr,dummy->position);	
	}

}
*/