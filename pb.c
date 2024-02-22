/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielhasso <ielhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:52:17 by ielhasso          #+#    #+#             */
/*   Updated: 2024/02/18 19:02:10 by ielhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <stdlib.h>

static int	*copy_stack(int *stack, int numbers)
{
	int	i;
	int	*tab;

	i = 0;
	tab = malloc(sizeof(int) * numbers);
	if (!tab)
		exit(140);
	while (i < numbers)
	{
		tab[i] = stack[i];
		i++;
	}
	return (tab);
}

static int	*new_stack_a(t_data *info)
{
	int	i;
	int	*new_stack_a;

	new_stack_a = malloc(sizeof(int) * info->na);
	if (!new_stack_a)
		exit(140);
	i = 0;
	while (i < info->na)
	{
		new_stack_a[i] = info->stack_a[i + 1];
		i++;
	}
	free(info->stack_a);
	return (new_stack_a);
}

static void	copy_others_numbers(t_data *info, int *stack_b_copy)
{
	int	i;

	i = 1;
	while (i < info->nb)
	{
		info->stack_b[i] = stack_b_copy[i - 1];
		i++;
	}
}

static void	set_pb(t_data *info)
{
	int	*allocate_stack_b;
	int	number_stack_b;

	number_stack_b = info->nb;
	info->nb++;
	info->na--;
	if (number_stack_b == 0)
	{
		info->stack_b = malloc(sizeof(int) * info->nb);
		if (!info->stack_b)
			exit(140);
		info->stack_b[0] = info->stack_a[0];
	}
	else
	{
		allocate_stack_b = copy_stack(info->stack_b, number_stack_b);
		free(info->stack_b);
		info->stack_b = malloc(sizeof(int) * info->nb);
		if (!info->stack_a)
			exit(140);
		info->stack_b[0] = info->stack_a[0];
		copy_others_numbers(info, allocate_stack_b);
		free(allocate_stack_b);
	}
	info->stack_a = new_stack_a(info);
}

void	pb(t_data *info, int one_more_time)
{
	int	i;

	i = 0;
	while (i < one_more_time)
	{
		set_pb(info);
		write(1, "pb\n", 3);
		i++;
	}
}
