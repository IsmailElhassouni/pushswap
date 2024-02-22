/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielhasso <ielhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:29:58 by ielhasso          #+#    #+#             */
/*   Updated: 2024/02/18 19:00:45 by ielhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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

static int	*new_stack_b(t_data *info)
{
	int	i;
	int	*new_stack_b;

	new_stack_b = malloc(sizeof(int) * info->nb);
	if (!new_stack_b)
		exit(140);
	i = 0;
	while (i < info->nb)
	{
		new_stack_b[i] = info->stack_b[i + 1];
		i++;
	}
	free(info->stack_b);
	return (new_stack_b);
}

static void	copy_other_numbers(t_data *info, int *old_a)
{
	int	i;

	i = 1;
	while (i < info->na)
	{
		info->stack_a[i] = old_a[i - 1];
		i++;
	}
}

static void	set_pa(t_data *info)
{
	int	*allocate_stack_a;
	int	number_stack_a;

	number_stack_a = info->na;
	info->na++;
	info->nb--;
	allocate_stack_a = copy_stack(info->stack_a, number_stack_a);
	free(info->stack_a);
	info->stack_a = malloc(sizeof(int) * info->na);
	if (!info->stack_a)
		exit(140);
	info->stack_a[0] = info->stack_b[0];
	copy_other_numbers(info, allocate_stack_a);
	free(allocate_stack_a);
	info->stack_b = new_stack_b(info);
}

void	pa(t_data *info, int one_more_time)
{
	int	i;

	i = 0;
	while (i < one_more_time)
	{
		set_pa(info);
		write(1, "pa\n", 3);
		i++;
	}
}
