/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielhasso <ielhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:33:09 by ielhasso          #+#    #+#             */
/*   Updated: 2024/02/20 17:02:48 by ielhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	smallest_number_a(t_data *info)
{
	int	i;
	int	store;
	int	position;

	store = info->stack_a[0];
	position = 0;
	i = 0;
	while (i < info->na)
	{
		if (store >= info->stack_a[i])
		{
			store = info->stack_a[i];
			position = i;
		}
		i++;
	}
	return (position);
}

static int	ba(t_data *info, int num)
{
	int	i;

	i = 0;
	while (i < info->na)
	{
		if (num < info->stack_a[i])
			break ;
		i++;
	}
	if (i == info->na)
		return (1);
	return (0);
}

int	pazero(t_data *info, int num)
{
	int	var;
	int	i;
	int	pos;

	i = 0;
	var = info->stack_a[0];
	if (ba(info, num) == 1)
		return (smallest_number_a(info));
	while (i < info->na)
	{
		if (info->stack_a[i] >= var)
			var = info->stack_a[i];
		i++;
	}
	i = -1;
	while (++i < info->na)
	{
		if (info->stack_a[i] > num && info->stack_a[i] <= var)
		{
			var = info->stack_a[i];
			pos = i;
		}
	}
	return (pos);
}

void	pushing_to_a(t_data *info,int ac)
{
	if (info->nb != 0)
	{
		while (info->nb > 0)
		{
			backtozero(info);
			azero(info, pazero(info, info->stack_b[0]));
			actions(info);
			pa(info, 1);
		}
		backtozero(info);
		azero(info, smallest_number_a(info));
		actions(info);
		if (ac > 3)
			free(info->stack_b);
	}
}

int	isorted(t_data *info)
{
	int	i;

	i = 0;
	while (i < info->na - 1)
	{
		if (info->stack_a[i] > info->stack_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}
