/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsmith <jsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:20:10 by jsmith            #+#    #+#             */
/*   Updated: 2022/02/02 14:16:08 by jsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"


typedef struct s_stack_a
{
    int nbr;
    void *next;
}   t_stack_a;

typedef struct s_stack_b
{
    int nbr;
    void *next;
}   t_stack_b;

typedef struct s_info
{
	int	nbrtotal;
}	t_info;


t_info ft_manage_string(int argc, char *argv[], t_info info)
{
	int	i;
	int	nbrspaces;

	i = 0;
	nbrspaces = 0;
	info.nbrtotal = 0;
	while (argv[1][i])
	{
		if (ft_isdigit(argv[1][i]) && (argv[1][i+1] == ' ' || !ft_isdigit(argv[1][i+1])))
			info.nbrtotal += 1;
		else if(!ft_isdigit(argv[1][i]) && !ft_is_util(argv[1][i]))
			ft_perror_exit("Argument inválido a la hora de leer el string");
		i++;
	}

	return (info);    
}
t_info ft_manage_args(int argc, char *argv[],t_info info)
{
	int i;
	int u;

	i = 1;
	u = 0;
	while(argv[i])
	{	
		if (ft_isalpha_on_ptr(argv[i]))
			ft_perror_exit("Argument Invalid");
		i++;
	}
	info.nbrtotal = argc -1;
	return (info);
}


int main(int argc, char *argv[])
{   
    t_info info;
    
    if(argc == 1)
		ft_perror_exit("Argument Invalid");
    if(argc == 2)
		info = ft_manage_string(argc, argv, info);
	else
		info = ft_manage_args(argc, argv, info);
	
    return (0);
}