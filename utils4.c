/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielhasso <ielhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:42:26 by ielhasso          #+#    #+#             */
/*   Updated: 2024/02/19 13:15:21 by ielhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	is_rr(t_data *info)
{
	if (info->ra != 0 && info->rb != 0)
	{
		if (info->ra > info->rb)
		{
			info->rr = info->rb;
			info->ra = info->ra - info->rb;
			info->rb = 0;
		}
		else if (info->rb > info->ra)
		{
			info->rr = info->ra;
			info->rb = info->rb - info->ra;
			info->ra = 0;
		}
		else
		{
			info->rr = info->rb;
			info->ra = 0;
			info->rb = 0;
		}
		return (1);
	}
	return (0);
}

int	is_ss(t_data *info)
{
	if (info->sa != 0 && info->sb != 0)
	{
		info->sa = 0;
		info->sb = 0;
		info->ss = 1;
		return (1);
	}
	return (0);
}

int	is_rrr(t_data *info)
{
	if (info->rra != 0 && info->rrb != 0)
	{
		if (info->rra > info->rrb)
		{
			info->rrr = info->rrb;
			info->rra = info->rra - info->rrb;
			info->rrb = 0;
		}
		else if (info->rrb > info->rra)
		{
			info->rrr = info->rra;
			info->rrb = info->rrb - info->rra;
			info->rra = 0;
		}
		else
		{
			info->rrr = info->rrb;
			info->rra = 0;
			info->rrb = 0;
		}
		return (1);
	}
	return (0);
}

void	backtozero(t_data *info)
{
	info->ra = 0;
	info->rb = 0;
	info->rr = 0;
	info->sa = 0;
	info->sb = 0;
	info->ss = 0;
	info->rra = 0;
	info->rrb = 0;
	info->rrr = 0;
}

int	is_low_move(t_data *info)
{
	int	i;
	int	pos;
	int	temp;

	pos = 0;
	temp = info->action[0];
	i = 0;
	while (i < info->na)
	{
		if (temp > info->action[i])
		{
			pos = i;
			temp = info->action[i];
		}
		i++;
	}
	return (pos);
}
