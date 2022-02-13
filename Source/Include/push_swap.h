/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsmith <jsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 09:56:53 by jsmith            #+#    #+#             */
/*   Updated: 2022/02/13 02:24:48 by jsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include "Libft/libft.h"

typedef struct s_node
{
	int nbr;
	struct s_node *next;
	int position;
}	t_node;

typedef struct s_nodelst{
	t_node *a_head;
	t_node *b_head;
}	t_nodelst;

void		ft_destroy_node(t_node *node);
void		ft_check_order(char **numbers);
void		ft_check_veracity(char **numbers);
void		ft_push_a(t_nodelst *nodelst);
void		ft_push_b(t_nodelst *nodelst);
void		ft_swap_a(t_nodelst *nodelst);
void		ft_swap_b(t_nodelst *nodelst);
void		ft_swap_ss(t_nodelst *nodelst);
void		ft_rotate_a(t_nodelst *nodelst);
void		ft_rotate_b(t_nodelst *nodelst);
void		ft_rotate_rr(t_nodelst *nodelst);
void		ft_reverse_rotate_b(t_nodelst *nodelst);
void		ft_reverse_rotate_a(t_nodelst *nodelst);
void		ft_reverse_rotate_rr(t_nodelst *nodelst);
void		ft_print_stack_a(t_nodelst *nodelst);
void		ft_print_stack_b(t_nodelst *nodelst);
t_node		*ft_create_node();
t_nodelst	*ft_generate_nodelst(char **nbr);
char		**ft_args_to_string(int argc, char *argv[]);
t_nodelst	*ft_manage_entry(int argc, char *argv[], t_nodelst *nodelst);
int			ft_iterate_stack(t_nodelst *nodelst, char e);
t_node 		*ft_return_specific_node(t_nodelst *nodelst, int last, char e);
#endif