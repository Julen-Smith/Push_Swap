/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsmith <jsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 09:52:56 by jsmith            #+#    #+#             */
/*   Updated: 2022/02/01 12:43:01 by jsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../Libraries/Libft/libft.h"


typedef struct s_chunk_info
{
	int	*stack_a;
	int	*stack_b;
	int	nbrtotal;
}	t_chunk_info;

void			ft_print_stack(t_chunk_info info);
t_chunk_info	ft_allocate_int_string(t_chunk_info info, char *argv[]);
t_chunk_info	ft_count_ints_from_arg(t_chunk_info info, char *argv[]);
t_chunk_info	ft_prepare_push_swap_stack(t_chunk_info info, char *argv[]);
void			swap_a(t_chunk_info info);
void			swap_b(t_chunk_info info);
void			swap_ss(t_chunk_info info);
void			ft_push_front_stack(t_chunk_info info, char *stack_type);
#endif
