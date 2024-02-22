/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielhasso <ielhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:07:03 by ielhasso          #+#    #+#             */
/*   Updated: 2024/02/20 17:01:53 by ielhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_push_swap
{
	int	*stack_a;
	int	na;
	int	*stack_b;
	int	nb;
	int	*action;
	int	ra;
	int	rb;
	int	rr;
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	rra;
	int	rrb;
	int	rrr;
}		t_data;
int		ft_strlen(const char *s);
void	exits(int i, t_data *info);
int		isorted(t_data *info);
char	**ar(char ***tab);
char	***par_av(int ac, char **av);
char	**ft_split(char const *s, char c);
void	spaces(char *s);
void	sa(t_data *info, int time);
void	sb(t_data *info, int time);
void	ss(t_data *info, int time);
void	two(t_data *info);
int		is_rr(t_data *info);
int		is_rrr(t_data *info);
int		is_ss(t_data *info);
int		pushing_and_checking(t_data *info, int argc, char **argv);
void	rra(t_data *info, int time);
void	rrb(t_data *info, int time);
void	ra(t_data *info, int time);
void	rb(t_data *info, int time);
void	rrr(t_data *info, int time);
void	rr(t_data *info, int time);
void	pb(t_data *info, int time);
void	pa(t_data *info, int time);
char	*ft_strdup(const char *s);
long	ft_atoi(const char *str, t_data *info);
void	count_actions(t_data *info);
void	backtozero(t_data *b);
int		pbzero(t_data *info, int i);
void	mergemoves(t_data *info);
void	actions(t_data *info);
void	hard(t_data *info, int ac);
void	sort_3(t_data *info);
int		is_low_move(t_data *info);
void	azero(t_data *info, int pos);
void	bzro(t_data *info, int pos);
void	sort_three(t_data *info);
void	pushing_to_b(t_data *info, int ac);
void	pushing_to_a(t_data *info,int ac);
#endif