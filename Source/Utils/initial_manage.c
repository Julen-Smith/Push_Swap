/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_manage.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsmith <jsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 09:56:45 by jsmith            #+#    #+#             */
/*   Updated: 2022/02/13 01:55:56 by jsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"


char **ft_args_to_string(int argc, char *argv[])
{
	int i;
	char **ptr;

	i = 0;
	ptr = malloc(sizeof(char *) * argc);
	while (i != argc -1)
	{
		ptr[i] = malloc (sizeof(char) * ft_strlen(argv[i+1])+1);
		ft_strlcpy(ptr[i],argv[i+1],ft_strlen(argv[i+1])+1);
		i++;		
	}
	ptr[i] = NULL;
	return (ptr);
}

void	ft_check_veracity(char **numbers)
{
	int i;
	int u;

	i = 0;
	while(numbers[i])
	{
		u = 0;
		while(numbers[i][u])
		{
			if (!ft_isdigit(numbers[i][u]))
				 if	(numbers[i][u] != '-')
					ft_perror_exit("Invalid character detected.");
			u++;
		}
		i++;
	}
}

void	ft_check_order(char **numbers)
{
	int i;
	int u;
	int dummy;

	dummy = 0;
	i = 0;
	u = 0;
	while(numbers[i])
	{
		if (dummy < ft_atoi(numbers[i]))
		{
			dummy = ft_atoi(numbers[i]);
			u++;
		}
		i++;
	}
	if(i == u)
		exit(0);
}

t_nodelst	*ft_manage_entry(int argc, char *argv[], t_nodelst *nodelst)
{
	char **numbers;
	
	if (argc < 2)
		ft_perror_exit("Argumentos insuficientes");
	if(argc == 2)
		numbers = ft_split(argv[1],' ');
	else
		numbers = ft_args_to_string(argc, argv);
	ft_check_veracity(numbers);
	ft_check_order(numbers);
	nodelst = ft_generate_nodelst(numbers);
	/**
	 * @brief Construct a new return object
	 * FALTA COMPROBAR DUPLICADOS	
	 */
	
	return(nodelst);
}
