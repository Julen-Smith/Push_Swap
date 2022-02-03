/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsmith <jsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 09:53:34 by jsmith            #+#    #+#             */
/*   Updated: 2022/02/01 14:35:39 by jsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Include/push_swap.h"

void	ft_print_stack(t_chunk_info info)
{
	int	i;

	i = 0;
	while (i != info.nbrtotal)
	{
		ft_putnbr_fd(info.stack_a[i], 1);
		i++;
	}
}

t_chunk_info	ft_allocate_int_string(t_chunk_info info, char *argv[])
{
	int	i;
	int	nbrspaces;
	int	stacki;

	i = 0;
	nbrspaces = 0;
	stacki = 0;
	info.stack_a = malloc(sizeof(int) * info.nbrtotal);
	while (argv[1][i])
	{
		if (ft_isdigit(argv[1][i]))
		{
			info.stack_a[stacki] = ft_atoi(&argv[1][i]);
			stacki++;
		}
		i++;
	}
	return (info);
}

t_chunk_info	ft_count_ints_from_arg(t_chunk_info info, char *argv[])
{
	int	i;
	int	nbrspaces;

	i = 0;
	nbrspaces = 0;
	while (argv[1][i])
	{
		if (argv[1][i] == ' ')
			nbrspaces += 1;
		else if(!ft_isdigit(argv[1][i]))
			ft_perror_exit("One of the arguments given is not numeric");
		i++;
	}
	if (i > 0 && nbrspaces > 0)
		info.nbrtotal = nbrspaces +1;
	else
		ft_perror_exit("Argument Invalid");
	info = ft_allocate_int_string(info, argv);
	return (info);
}

t_chunk_info	ft_prepare_push_swap_stack(t_chunk_info info, char *argv[])
{
	int	i;

	i = 0;
	if (info.nbrtotal == 0)
		ft_perror_exit("Argument Invalid");
	else if (info.nbrtotal > 1)
	{
		info.stack_a = malloc(sizeof(int) * info.nbrtotal);
		while (i != info.nbrtotal)
		{
			if (ft_isalpha_on_ptr(argv[i +1]))
				ft_perror_exit("One of the arguments given is not numeric");
			info.stack_a[i] = ft_atoi(argv[i +1]);
			i++;
		}
	}
	else if (info.nbrtotal == 1)
		info = ft_count_ints_from_arg(info, argv);
	return (info);
}
