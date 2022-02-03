/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsmith <jsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 08:00:47 by jsmith            #+#    #+#             */
/*   Updated: 2022/02/02 14:02:19 by jsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Include/push_swap.h"

void ft_push_front_stack(t_chunk_info info, char *stack_type)
{
    int i;
    int u;

    i = 0;
    u = 1;
    if(ft_strncmp(stack_type,"stack_a",ft_strlen(stack_type)))
        {
            while(ft_isdigit(info.stack_a[i]))
            {
                info.stack_a[i] = info.stack_a[u];     
                i++;
                u++;
            }
           // info.stack_a[i] = ;    
        }
    else
        {
            i = 0;
            u = 1;
            while(ft_isdigit(info.stack_b[i]))
            {
                info.stack_b[i] = info.stack_b[u];     
                i++;
                u++;
            }  
        }  
}

void push_a(t_chunk_info info)
{
   if(info.stack_b[0])
    ft_push_front_stack(info,"stack_a");
   ft_putstr_fd("\npush_a\n",1);
}

void    push_swap(t_chunk_info info)
{
    //Coge la posicion a 0 y a 1 y las cambia
    //swap_a(info);
    //Coge la posicion a 0 y a 1 y las cambia
    //swap_b(info);
    //Coge la posicion a 0 y a 1 y las cambia en ambos stacks
    //swap_ss(info);
    //primer elemento de b0 y lo manda a a0
    push_a(info);
    //primer elemento de a0 y lo manda a b0
    //push_b(info);
    //a0 a[MAX]
    //rotate_a(info);
     //b0 b[MAX]
    //rotate_b();
    //rotate a rotate b
    //rotate_rr(info);
    //a[MAX] a0
    //reverse_rotate_a(info);
    //b[MAX] b0
    //reverse_rotate_b(info);
    //reverse_a reverse_b together
    //reverse_rotate_rrr(info);
}

int main(int argc, char *argv[])
{   
    t_chunk_info info;

    info.nbrtotal = argc -1;
    info = ft_prepare_push_swap_stack(info,argv);
    info.stack_b = malloc(sizeof(int) * info.nbrtotal);
    ft_print_stack(info);printf("\n");
    push_swap(info);
    ft_print_stack(info);printf("\n");
    free(info.stack_a);
    free(info.stack_b);
    return (0);
}