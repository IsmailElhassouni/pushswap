/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielhasso <ielhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:22:04 by ielhasso          #+#    #+#             */
/*   Updated: 2024/02/19 14:30:03 by ielhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	set_rra(t_data *info)
{
	int	tmp;
	int	i;

	i = info->na - 1;
	tmp = info->stack_a[info->na - 1];
	while (i >= 0)
	{
		if (i != 0)
			info->stack_a[i] = info->stack_a[i - 1];
		else
			info->stack_a[i] = tmp;
		i--;
	}
}

void	rra(t_data *info, int one_more)
{
	int	i;

	i = 0;
	while (i < one_more)
	{
		set_rra(info);
		i++;
		write(1, "rra\n", 4);
	}
}

static void	set_rrb(t_data *info)
{
	int	tmp;
	int	i;

	i = info->nb - 1;
	tmp = info->stack_b[info->nb - 1];
	while (i >= 0)
	{
		if (i != 0)
			info->stack_b[i] = info->stack_b[i - 1];
		else
			info->stack_b[i] = tmp;
		i--;
	}
}

void	rrb(t_data *info, int one_more)
{
	int	i;

	i = 0;
	while (i < one_more)
	{
		set_rrb(info);
		i++;
		write(1, "rrb\n", 4);
	}
}

void	rrr(t_data *info, int one_more)
{
	int	i;

	i = 0;
	while (i < one_more)
	{
		set_rra(info);
		set_rrb(info);
		write(1, "rrr\n", 4);
		i++;
	}
}
