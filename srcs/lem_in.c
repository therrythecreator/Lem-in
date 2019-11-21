/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 18:08:59 by flhember          #+#    #+#             */
/*   Updated: 2019/11/21 18:46:24 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int		lem_in(void)
{
	t_data		env;
	t_lst		*lst;

	lst = NULL;
	init_struct(&env);
	if (!(lst = parsing_main(&env)))
		return (-1);
	if ((algo_main(&lst, &env) == -1))
		return (-1);
//	print_adja(&lst, &env);
	free_lst_adja(&lst, &env);
	return (0);
}
