/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsmith <jsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 09:56:53 by jsmith            #+#    #+#             */
/*   Updated: 2022/03/03 13:14:52 by jsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				nbr;
	struct s_node	*next;
	struct s_node	*previus;
	int				position;
}	t_node;

typedef struct s_nodelst{
	t_node	*a_head;
	t_node	*b_head;
	t_node	*middle;
	int		stacklen;
	int		chunksize;
	int		nbrfromtop;
	int		nbrfrombottom;
}	t_nodelst;

void			ft_destroy_node(t_node *node);
void			ft_check_order(char **numbers);
void			ft_check_veracity(char **numbers);
void			ft_push_a(t_nodelst *nodelst);
void			ft_push_b(t_nodelst *nodelst);
void			ft_swap_a(t_nodelst *nodelst);
void			ft_swap_b(t_nodelst *nodelst);
void			ft_swap_ss(t_nodelst *nodelst);
void			ft_rotate_a(t_nodelst *nodelst);
void			ft_rotate_b(t_nodelst *nodelst);
void			ft_rotate_rr(t_nodelst *nodelst);
void			ft_reverse_rotate_b(t_nodelst *nodelst);
void			ft_reverse_rotate_a(t_nodelst *nodelst);
void			ft_reverse_rotate_rr(t_nodelst *nodelst);
void			ft_print_stack_a(t_nodelst *nodelst);
void			ft_print_stack_b(t_nodelst *nodelst);
t_node			*ft_create_node(void);
t_nodelst		*ft_generate_nodelst(char **nbr);
char			**ft_args_to_string(int argc, char *argv[]);
t_nodelst		*ft_manage_entry(int argc, char *argv[]);
int				ft_iterate_stack(t_nodelst *nodelst, char e);
t_node			*ft_return_specific_node(t_nodelst *nodelst, int last, char e);
t_node			*ft_return_lowst_pointer(t_nodelst *lst);
void			ft_initialize_positions(t_nodelst *lst);
t_node			*ft_return_biggst_pointer(t_nodelst *lst, char e);
void			ft_generate_positions(t_nodelst *nodelst);
t_node			*ft_order(t_nodelst *lst);
int				ft_check_nodeorder(t_nodelst *nodelst);
void			ft_refresh_stacklen(t_nodelst *nodelst);
void			ft_get_middle(t_nodelst *nodelst);
int				ft_check_nodeorder(t_nodelst *nodelst);
t_node			*ft_return_node_by_pos(t_nodelst *nodelst, int position);
void			ft_ordenate_3_stack(t_nodelst *nodelst);
int				ft_where_is_node_in_stack(t_nodelst *nodelst, int nbr);
void			ft_ordenate_10_stack(t_nodelst *nodelst);
t_node			*ft_return_last_ptr(t_nodelst *lst);
void			ft_ordenate_100_stack(t_nodelst *nodelst);
void			ft_ordenate_500_stack(t_nodelst *nodelst);
void			ft_ordenate_100_last_part(t_nodelst *nodelst);
void			ft_numbers_return_to_stack_a(t_nodelst *nodelst);
void			ft_generate_previus_values(t_nodelst *nodelst);
void			ft_generate_previus_values_on_b(t_nodelst *nodelst);
int				ft_is_in_the_middle_of_the_stack(t_nodelst *nodelst, int nd);
int				ft_calculate_middle_pos(t_nodelst *lst, int nodepos);
void			ft_find_first_cond_from_top(t_nodelst *nodelst, int chunksize);
void			ft_find_first_cond_from_bottom(t_nodelst *nodelst, int cnk);
int				ft_find_moves_from_top(t_nodelst *nodelst, int position);
int				ft_find_moves_from_bottom(t_nodelst *nodelst, int position);
t_node			*ft_return_last_ptr_b_edition(t_nodelst *lst);
void			ft_refresh_stacklen_b(t_nodelst *nodelst);
int				ft_just_because_the_norm(t_nodelst *nodelst, int big);
void			ft_conditional_ra_and_rra(t_nodelst *nodelst);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
int				ft_isdigit(int c);
void			ft_perror_exit(char *s);
char			**ft_split(char const *s, char c);
int				ft_atoi(const char *str);
size_t			ft_strlen(const char *str);
#endif