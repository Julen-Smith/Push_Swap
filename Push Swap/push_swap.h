/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsmith <jsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 09:56:53 by jsmith            #+#    #+#             */
/*   Updated: 2022/02/10 12:40:49 by jsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include "Libft/libft.h"

typedef struct s_node
{
	int nbr;
	struct s_node *next;
}	t_node;

typedef struct s_nodelst{
	t_node *a_head;
	t_node *b_head;
}	t_nodelst;


char		**ft_args_to_string(int argc, char *argv[]);
void		ft_check_veracity(char **numbers);
t_node		*ft_create_node();
void		ft_destroy_node(t_node *node);
t_nodelst	*ft_generate_nodelst(char **nbr);
t_nodelst	*ft_manage_entry(int argc, char *argv[], t_nodelst *nodelst);
void		ft_check_order(char **numbers);
void		ft_print_stack_b(t_nodelst *nodelst);
void		ft_print_stack_a(t_nodelst *nodelst);





#endif