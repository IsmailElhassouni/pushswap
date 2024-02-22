/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielhasso <ielhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:13:34 by ielhasso          #+#    #+#             */
/*   Updated: 2024/02/20 17:02:10 by ielhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "limits.h"
#include "pushswap.h"

int	iserror(char *av, t_data *info)
{
	long		k;
	static int	tab[1000];
	static int	j = 0;
	int			i;
	long		tmp;

	k = ft_atoi(av, info);
	i = 0;
	if ((k == 0 && av[0] != '0' && av[0] != '-' && av[0] != '+'))
		(write(2, "Error\n", 7), exits(11, info));
	tab[j] = k;
	tmp = tab[j];
	while (i < j)
	{
		if (tmp == tab[i])
			(write(2, "Error\n", 7), exits(12, info));
		i++;
	}
	j++;
	return (k);
}

int	pushing_and_checking(t_data *info, int argc, char **argv)
{
	int	i;

	i = 0;
	info->stack_a = (int *)malloc(sizeof(int *) * argc);
	if (!info->stack_a)
		return (0);
	while (i < argc)
	{
		info->stack_a[i] = iserror(argv[i], info);
		i++;
		info->na++;
	}
	info->nb = 0;
	return (1);
}

void	two(t_data *info)
{
	if (info->stack_a[0] > info->stack_a[1])
		sa(info, 1);
}

void	pushing_to_b(t_data *info, int ac)
{
	int	pos;

	if (ac == 4)
		pb(info, 1);
	else if (ac > 4)
		pb(info, 2);
	while (info->na > 3)
	{
		info->action = malloc(sizeof(int) * info->na);
		count_actions(info);
		pos = is_low_move(info);
		azero(info, pos);
		bzro(info, pbzero(info, info->stack_a[pos]));
		mergemoves(info);
		actions(info);
		pb(info, 1);
		free(info->action);
		backtozero(info);
	}
}

void	hard(t_data *info, int ac)
{
	backtozero(info);
	pushing_to_b(info, ac);
	sort_three(info);
	pushing_to_a(info,ac);
}
