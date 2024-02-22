/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielhasso <ielhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:48:54 by ielhasso          #+#    #+#             */
/*   Updated: 2024/02/20 12:46:26 by ielhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "limits.h"
#include "pushswap.h"

long	ft_atoi(const char *str, t_data *info)
{
	long (res);
	int (i), (neg);
	i = 0;
	neg = 1;
	res = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	if (str[i] < '0' || str[i] > '9')
		(write(2, "Error\n", 7), exits(10, info));
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (str[i] - '0') + (res * 10);
		i++;
		if (str[i] != '\0' && (str[i] < '0' || str[i] > '9'))
			(write(2, "Error\n", 7), exits(10, info));
		if (res > INT_MAX || res < INT_MIN)
			(write(2, "Error\n", 7), exits(10, info));
	}
	return (res * neg);
}

void	azero(t_data *info, int index)
{
	if (index == 0)
		return ;
	else if (index == 1)
		info->ra = 1;
	else if (index == info->na - 1)
		info->rra = 1;
	else if (index <= info->na / 2)
		info->ra = index;
	else if (index > info->na / 2)
		info->rra = info->na - index;
}

void	bzro(t_data *info, int index)
{
	if (index == 0)
		return ;
	else if (index == 1)
		info->rb = 1;
	else if (index == info->nb - 1)
		info->rrb = 1;
	else if (index <= info->nb / 2)
		info->rb = index;
	else if (index > info->nb / 2)
		info->rrb = info->nb - index;
}

void	mergemoves(t_data *info)
{
	if (is_ss(info) == 1)
		return ;
	else if (is_rr(info) == 1)
		return ;
	else if (is_rrr(info) == 1)
		return ;
}

void	count_actions(t_data *info)
{
	int	i;

	i = 0;
	while (i < info->na)
	{
		azero(info, i);
		bzro(info, pbzero(info, info->stack_a[i]));
		mergemoves(info);
		info->action[i] = info->sa + info->sb + info->ss + info->ra + info->rb
			+ info->rr + info->rra + info->rrb + info->rrr;
		backtozero(info);
		i++;
	}
}
