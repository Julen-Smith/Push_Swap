/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsmith <jsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 01:57:12 by jsmith            #+#    #+#             */
/*   Updated: 2022/02/13 01:57:35 by jsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../Include/push_swap.h"

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