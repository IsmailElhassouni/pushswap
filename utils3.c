/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielhasso <ielhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:26:47 by ielhasso          #+#    #+#             */
/*   Updated: 2024/02/19 13:15:39 by ielhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	bs(t_data *info, int num)
{
	int	i;

	i = 0;
	while (i < info->nb)
	{
		if (num < info->stack_b[i])
			break ;
		i++;
	}
	if (i == info->nb)
		return (1);
	i = 0;
	while (i < info->nb)
	{
		if (num > info->stack_b[i])
			break ;
		i++;
	}
	if (i == info->nb)
		return (1);
	return (0);
}

static int	gb(t_data *info)
{
	int	i;
	int	var;
	int	pos;

	i = 0;
	pos = 0;
	var = info->stack_b[0];
	while (i < info->nb)
	{
		if (var < info->stack_b[i])
		{
			var = info->stack_b[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}

int	pbzero(t_data *info, int num)
{
	int	var;
	int	i;
	int	pos;

	i = 0;
	var = num;
	pos = 0;
	if (bs(info, num) == 1)
		return (gb(info));
	while (i < info->nb)
	{
		if (var > info->stack_b[i])
			var = info->stack_b[i];
		i++;
	}
	i = -1;
	while (++i < info->nb)
	{
		if (info->stack_b[i] < num && info->stack_b[i] >= var)
		{
			var = info->stack_b[i];
			pos = i;
		}
	}
	return (pos);
}

void	actions(t_data *info)
{
	ss(info, info->ss);
	rr(info, info->rr);
	rrr(info, info->rrr);
	sa(info, info->sa);
	ra(info, info->ra);
	rra(info, info->rra);
	sb(info, info->sb);
	rb(info, info->rb);
	rrb(info, info->rrb);
}
