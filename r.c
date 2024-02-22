/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielhasso <ielhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:35:31 by ielhasso          #+#    #+#             */
/*   Updated: 2024/02/19 11:49:24 by ielhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	set_rb(t_data *ifno)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = ifno->stack_b[0];
	while (i < ifno->nb)
	{
		if (i != ifno->nb - 1)
			ifno->stack_b[i] = ifno->stack_b[i + 1];
		else
			ifno->stack_b[i] = tmp;
		i++;
	}
}

static void	set_ra(t_data *info)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = info->stack_a[0];
	while (i < info->na)
	{
		if (i != info->na - 1)
			info->stack_a[i] = info->stack_a[i + 1];
		else
			info->stack_a[i] = tmp;
		i++;
	}
}

void	ra(t_data *info, int one_more)
{
	int	i;

	i = 0;
	while (i < one_more)
	{
		set_ra(info);
		i++;
		write(1, "ra\n", 3);
	}
}

void	rr(t_data *info, int one_more)
{
	int	i;

	i = 0;
	while (i < one_more)
	{
		set_ra(info);
		set_rb(info);
		write(1, "rr\n", 3);
		i++;
	}
}

void	rb(t_data *info, int one_more)
{
	int	i;

	i = 0;
	while (i < one_more)
	{
		set_rb(info);
		i++;
		write(1, "rb\n", 3);
	}
}
