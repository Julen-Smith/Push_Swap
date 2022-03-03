/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_manage.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsmith <jsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 09:56:45 by jsmith            #+#    #+#             */
/*   Updated: 2022/03/03 13:15:04 by jsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

char	**ft_args_to_string(int argc, char *argv[])
{
	int		i;
	char	**ptr;

	i = 0;
	ptr = malloc(sizeof(char *) * argc);
	while (i != argc -1)
	{
		ptr[i] = malloc (sizeof(char) * ft_strlen(argv[i + 1]) + 1);
		ft_strlcpy(ptr[i], argv[i + 1], ft_strlen(argv[i + 1]) + 1);
		i++;
	}
	ptr[i] = NULL;
	return (ptr);
}

void	ft_check_veracity(char **numbers)
{
	int	i;
	int	u;

	i = 0;
	while (numbers[i])
	{
		u = 0;
		while (numbers[i][u])
		{
			if (!ft_isdigit(numbers[i][u]))
				if (numbers[i][u] != '-')
					ft_perror_exit("Error\n");
			u++;
		}
		i++;
	}
}

void	ft_comprobate_duplicates(t_nodelst *nodelst)
{
	t_node	*i;
	t_node	*u;
	t_node	*ln;

	i = nodelst->a_head;
	u = nodelst->a_head->next;
	ln = ft_return_last_ptr(nodelst);
	while (i && i->next)
	{
		u = i->next;
		while (u && u->next)
		{
			if (i->nbr == u->nbr || i->nbr == ln->nbr)
				ft_perror_exit("Error\n");
			u = u->next;
		}
		i = i->next;
	}
}

t_nodelst	*ft_manage_entry(int argc, char *argv[])
{
	int			i;
	char		**numbers;
	t_nodelst	*nodelst;

	i = 0;
	if (argc < 2)
		exit(0);
	if (argv[1][0] == '\0')
		exit(0);
	if (argc == 2)
		numbers = ft_split(argv[1], ' ');
	else
		numbers = ft_args_to_string(argc, argv);
	ft_check_veracity(numbers);
	nodelst = ft_generate_nodelst(numbers);
	if (!ft_check_nodeorder(nodelst))
		exit(0);
	ft_comprobate_duplicates(nodelst);
	while (numbers[i])
	{
		free(numbers[i]);
		i++;
	}
	free(numbers);
	return (nodelst);
}
