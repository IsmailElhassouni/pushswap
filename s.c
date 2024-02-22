/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielhasso <ielhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:26:10 by ielhasso          #+#    #+#             */
/*   Updated: 2024/02/19 14:30:28 by ielhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sa(t_data *info, int time)
{
	int	temp;
	int	i;

	i = 0;
	while (i < time)
	{
		temp = info->stack_a[0];
		info->stack_a[0] = info->stack_a[1];
		info->stack_a[1] = temp;
		i++;
		write(1, "sa\n", 3);
	}
}

void	sb(t_data *info, int time)
{
	int	temp;
	int	i;

	i = 0;
	while (i < time)
	{
		temp = info->stack_b[0];
		info->stack_b[0] = info->stack_b[1];
		info->stack_b[1] = temp;
		i++;
		write(1, "sb\n", 3);
	}
}

void	ss(t_data *info, int time)
{
	int	temp;
	int	i;

	i = 0;
	while (i < time)
	{
		temp = info->stack_a[0];
		info->stack_a[0] = info->stack_a[1];
		info->stack_a[1] = temp;
		temp = info->stack_b[0];
		info->stack_b[0] = info->stack_b[1];
		info->stack_b[1] = temp;
		i++;
		write(1, "ss\n", 3);
	}
}
