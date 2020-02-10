/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 18:08:59 by flhember          #+#    #+#             */
/*   Updated: 2020/02/10 18:15:46 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void		print_debug1(t_data *env)
{
	int		i;
	t_road	*tmp;

	i = 0;
	while (i < env->road_sol[env->tab_choose][0])
	{
		tmp = env->road[env->road_sol[env->tab_choose - 1][i]];
		while (tmp)
		{
			ft_printf("%s ->", tmp->name);
			if (tmp->index == env->end)
				ft_printf("tout vas bien ");
			tmp = tmp->next;
		}
		ft_printf("\n\n");
		i++;
	}
}



void	start_to_end(t_data *env, t_lst **lst)
{
	int	i;

	i = 0;
	while (i < (int)env->nb_ants)
	{
		ft_printf("L%d-%s", i, (*lst)->tab[env->end]->name);
		if (i + 1 < (int)env->nb_ants)
			ft_printf(" ");
		i++;
	}
	ft_printf("\n");
	free_road_adja(env, (*lst)->malloc_start);
	free_lst_adja(lst, env);
}

int		lem_in(void)
{
	t_data		env;
	t_lst		*lst;

	lst = NULL;
	init_struct(&env);
	if (!(lst = parsing_main(&env)))
	{
		ft_putstr_fd("ERROR\n", 2);
		return (-1);
	}
	if ((algo_main(&lst, &env) == -1))
	{
		free_lst_adja(&lst, &env);
		return (-1);
	}
	if (lst->nb_room == 2 || env.nb_con == 1)
	{
		start_to_end(&env, &lst);
		return (0);
	}
	sort_road(&env);
	env.tab_choose = 1;
	ft_printf("Je sefgv comme une merde\n");
	print_debug1(&env);
	nb_ant_road(&env);
	print_res(&env);
	free_road_adja(&env, lst->malloc_start);
	free_lst_adja(&lst, &env);
	while (1);
	return (0);
}
