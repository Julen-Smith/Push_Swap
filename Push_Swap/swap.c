/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsmith <jsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 11:55:39 by jsmith            #+#    #+#             */
/*   Updated: 2022/02/01 11:56:10 by jsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Include/push_swap.h"

void swap_a(t_chunk_info info)
{
    int aux;
    
    if(info.stack_a[0] && info.stack_a[1])
    {
        aux = info.stack_a[0];  
        info.stack_a[0] =  info.stack_a[1];
        info.stack_a[1] =  aux;                                  
    }     
    ft_putstr_fd("\nswap_a\n",1);
}

void swap_b(t_chunk_info info)
{
    int aux;
    
    if(info.stack_b[0] && info.stack_b[1])
    {
        aux = info.stack_b[0];  
        info.stack_b[0] =  info.stack_b[1];
        info.stack_b[1] =  aux;                                  
    }     
    ft_putstr_fd("\nswap_b\n",1);
}

void swap_ss(t_chunk_info info)
{
    swap_a(info);
    swap_b(info);
    ft_putstr_fd("\nswap_ss\n",1);
}
