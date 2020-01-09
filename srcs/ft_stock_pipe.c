/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 12:03:46 by flhember          #+#    #+#             */
/*   Updated: 2020/01/07 11:16:09 by chcoutur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void		print_lst_adja(t_lst **lst, t_data *env)
{
	size_t	i;
	t_room	*cpy;

	i = 0;
	printf("\n\n");
	while (i < env->nb_room)
	{
		cpy = (*lst)->tab[i];
		printf("\ttab[%zu]:\n-name:%s", i, cpy->name);
		while (cpy->next)
		{
			if (cpy->next)
				printf("-> %s ", cpy->next->name);
			cpy = cpy->next;
		}
		printf("-> NULL \n\n");
		i++;
	}
	printf("\n\n");
}

t_room		*creat_cpy(t_lst **lst, int sec_pe)
{
	t_room	*cpy;

	cpy = NULL;
	if (!(cpy = ft_memalloc(sizeof(t_room))))
		return (NULL);
	cpy->name = ft_strdup((*lst)->tab[sec_pe]->name);
	cpy->pos = (*lst)->tab[sec_pe]->pos;
	cpy->x = (*lst)->tab[sec_pe]->x;
	cpy->y = (*lst)->tab[sec_pe]->y;
	cpy->start = (*lst)->tab[sec_pe]->start;
	cpy->end = (*lst)->tab[sec_pe]->end;
	cpy->next = NULL;
	return (cpy);
}

int			add_link_lst(t_lst **lst, int fst_pe, int sec_pe)
{
	t_room	*cpy;
	t_room	*lst_cpy;

	lst_cpy = (*lst)->tab[fst_pe];
	if (!(cpy = creat_cpy(lst, sec_pe)))
		return (-1);
	while (lst_cpy->next)
		lst_cpy = lst_cpy->next;
	lst_cpy->next = cpy;
	return (0);
}

char		*ft_strncut(char *str, int n)
{
	int		i;
	char	*new_str;
	
	i = 0;
	if (!(new_str = ft_memalloc(sizeof(char) * (n + 1))))
		return (NULL);
	while (i < n)
	{
		new_str[i] = str[i];
		i++;
	}
	return (new_str);
}

size_t 	ft_strnlen(char *str, char c)
{
	size_t i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (i);
}

int			find_good_room(t_data *env, t_lst **lst, t_stock **pipe)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	if (ft_is_c((*pipe)->room, '-') == 1)
		(*pipe)->room1 = ft_strncut((*pipe)->room, ft_strnlen((*pipe)->room, '-'));
	else
		(*pipe)->room1 = ft_strdup((*pipe)->room);
	while (i < env->nb_room && ft_strcmp((*lst)->tab[i]->name, (*pipe)->room1) != 0)
	{
		i++;
	}
	if (i == env->nb_room)
		return (-1);
	j = ft_strlen((*lst)->tab[i]->name);
	if (j < ft_strlen((*pipe)->room))
	{
		while (k < (j + 1))
		{
			(*pipe)->room++;
			k++;
		}
	}
	ft_strdel(&(*pipe)->room1);
	return ((*lst)->tab[i]->pos);
}

int			find_stock_pipe(t_data *env, t_lst **lst, t_stock *pipe)
{
	int		fst_pe;
	int		sec_pe;
	char	*str;

	str = pipe->room;
	if ((fst_pe = find_good_room(env, lst, &pipe)) == -1)
		return (-1);
	if ((sec_pe = find_good_room(env, lst, &pipe)) == -1)
		return (-1);
	pipe->room = str;
	if (add_link_lst(lst, fst_pe, sec_pe) == -1)
		return (-1);
	if (add_link_lst(lst, sec_pe, fst_pe) == -1)
		return (-1);
	return (0);
}

int			stock_pipe(t_data *env, t_lst **lst, t_stock *pipe)
{
	while (pipe)
	{
		if (pipe->pipe == 1)
		{
			if ((find_stock_pipe(env, lst, pipe)) == -1)
			{
				printf("oups\n");
				return (-1);
			}
		}
		pipe = pipe->next;
	}
	return (0);
}
