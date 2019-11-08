/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 17:47:54 by flhember          #+#    #+#             */
/*   Updated: 2019/11/08 17:24:52 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

#include "../libft/includes/libft.h"

# define ANTS		0b00001
# define START		0b00010
# define END		0b00100
# define RSTART		0b01000
# define REND		0b10000

typedef struct			s_room
{
	char				*name;
	int					x;
	int					y;
	int					start;
	int					end;
	struct s_room		*next;
}						t_room;

typedef struct			s_lst
{
	t_room				*tab;
	int					i_r;
}						t_lst;

typedef struct			s_stock
{
	char				*str;
	s_stock				*next;
}						t_stock;

typedef struct			s_data
{
	int					flags;
	int					nb_ants;
	int					nb_room;
}						t_data;

int						lem_in(void);
int						parsing_map(t_data *env, t_mark *lst);
t_stock					*creat_maillon_stock(void);
void					add_maillon_end(t_stock *room, t_stock *new);
void					free_lst_stock(t_stock *room);
void					init_struct(t_data *env);
void					init_lst(t_mark *lst);


#endif
