/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 12:03:46 by flhember          #+#    #+#             */
/*   Updated: 2019/11/14 17:31:24 by chcoutur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			find_good_first_room(t_data *env, t_lst **lst, t_stock *pipe)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	while (i < env->nb_room && ft_strncmp((*lst)->tab[i]->name, pipe->room, ft_strlen((*lst)->tab[i]->name)))
		i++;
	if (i == env->nb_room)
		return (-1);
	j = ft_strlen((*lst)->tab[i]->name);
	ft_printf("room = [%s]\n", pipe->room);
	if (j > ft_strlen(pipe->room))
	{
		while (k < j + 1)
		{
			pipe->room++;
			k++;
		}
	}
	return (i);
}

int			find_stock_pipe(t_data *env, t_lst **lst, t_stock *pipe)
{
	int		fst_pe;
	int		sec_pe;
	if ((fst_pe = find_good_first_room(env, lst, pipe)) == -1)
	{
		ft_printf("fst_pe failed\n");
		return (-1);
	}
	if ((sec_pe = find_good_first_room(env, lst, pipe)) == -1)
	{
		ft_printf("sec_pe failed\n");
		return (-1);
	}
	printf("first room = [%s] ->\tSeconde room = [%s]\n", (*lst)->tab[fst_pe]->name, (*lst)->tab[sec_pe]->name);
	return (0);
}

int			stock_pipe(t_data *env, t_lst **lst, t_stock *pipe)
{
	while (pipe)
	{
		if (pipe->pipe == 1)
		{
			if ((find_stock_pipe(env, lst, pipe)) == -1)
				return (-1);
		}
		pipe = pipe->next;
	}
			ft_printf("\n");
	return (0);
}