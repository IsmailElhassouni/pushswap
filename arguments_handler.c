/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielhasso <ielhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:26:47 by ielhasso          #+#    #+#             */
/*   Updated: 2024/02/18 17:37:32 by ielhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

char	***par_av(int ac, char **av)
{
	char	***tab;
	int		i;

	tab = malloc(sizeof(char **) * (ac + 1));
	if (!tab)
		exit(256);
	i = 0;
	while (i < ac)
	{
		spaces(av[i]);
		tab[i] = ft_split(av[i + 1], ' ');
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

static void	free_arr(char ***tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i] != NULL)
	{
		j = 0;
		while (tab[i][j] != NULL)
		{
			free(tab[i][j]);
			j++;
		}
		free(tab[i]);
		i++;
	}
	free(tab);
}

static int	arr_num(char ***tab)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			count++;
			j++;
		}
		i++;
	}
	return (count);
}

char	**ar(char ***tab)
{
	char	**ar;

	int (i), (j), (k);
	ar = malloc(sizeof(char *) * (arr_num(tab) + 1));
	if (!ar)
		exit(255);
	i = 0;
	k = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			ar[k] = ft_strdup(tab[i][j]);
			if (!ar[k])
				exit(257);
			j++;
			k++;
		}
		i++;
	}
	free_arr(tab);
	ar[k] = NULL;
	return (ar);
}
