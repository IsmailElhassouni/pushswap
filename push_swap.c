/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielhasso <ielhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:06:38 by ielhasso          #+#    #+#             */
/*   Updated: 2024/02/20 12:45:33 by ielhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	spaces(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != 32)
			return ;
		i++;
	}
	write(2, "Error\n", 7);
	exit(110);
}

int	countargs(char **av)
{
	int	i;

	i = 0;
	if (!av)
		write(2, "Error\n", 7);
	while (av[i] != 0)
		i++;
	return (i);
}

int	main(int ac, char **av)
{
	t_data	info;
	char	**argv;
	int		argc;

	argc = 0;
	if (ac > 1)
	{
		argv = ar(par_av(ac, av));
		argc = countargs(argv);
		if (!argc)
			(write(2, "Error\n", 7), exit(21));
		if (pushing_and_checking(&info, argc, argv) == 0)
			return (10);
		if (isorted(&info) == 1)
			exits(0, &info);
		if (argc == 2)
			two(&info);
		else if (argc >= 3)
			hard(&info, argc);
	}
	exits(0, &info);
}
