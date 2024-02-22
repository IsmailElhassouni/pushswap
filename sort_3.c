/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielhasso <ielhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:23:52 by ielhasso          #+#    #+#             */
/*   Updated: 2024/02/20 12:52:03 by ielhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_three(t_data *info)
{
	if (info->stack_a[0] > info->stack_a[1]
		&& info->stack_a[0] > info->stack_a[2])
		ra(info, 1);
	if (info->stack_a[0] > info->stack_a[1])
		sa(info, 1);
	if (info->stack_a[1] > info->stack_a[2])
		rra(info, 1);
	if (info->stack_a[0] > info->stack_a[1])
		sa(info, 1);
}

void	exits(int i, t_data *info)
{
	free(info->stack_a);
	exit(i);
}
