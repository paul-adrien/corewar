/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_infos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:08:22 by tlandema          #+#    #+#             */
/*   Updated: 2020/01/21 17:16:46 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "visualisator.h"

static int8_t	draw_infos_text(t_window *win, t_vm *env)
{
	SDL_Point	point;
	int			text[3];
	int			tmp;
	char		*str;

	if (create_tab_int3(text, 20, TEXT2, BOLD) == FAILURE)
		return (FAILURE);
	point = create_point(1815, 10);
	if (draw_text(win, "Infos : ", point, text) == FAILURE)
		return (FAILURE);
	point.x += 45;
	point.y += 25;
	if ((tmp = draw_text(win, "- Cycles : ", point, text))
			&& tmp == FAILURE)
		return (FAILURE);
	point.x += tmp;
	if ((str = ft_lltoa(env->current_cycle)) && str == NULL)
		return (FAILURE);
	if (draw_text(win, str, point, text) == FAILURE)
		return (strdel_ret_fail(str));
	ft_strdel(&str);
	return (SUCCESS);
}

/*
** rajouter dans le deuxieme if la fonction qui regarde si tout les process ont
** dit je suis alive si oui remettre check_amount a 0 of course et cycle_to_die
** -CYCLE_DELTA.
*/

static int8_t	draw_infos_text2(t_window *win, t_vm *env)
{
	int				text[3];
	SDL_Point		point;
	int				tmp;

	point = create_point(1860, 70);
	if (create_tab_int3(text, 20, TEXT2, BOLD) == FAILURE)
		return (FAILURE);
	if ((tmp = draw_text(win, "- Cycles to die : ", point, text))
			&& tmp == FAILURE)
		return (FAILURE);
	point.x += tmp;
	if (draw_infos_cycle(win, env, point, text) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

static int8_t	draw_infos_text3(t_window *win, int speed_cursor, int c_p_f)
{
	int			text[3];
	SDL_Point	point;
	int			tmp;

	point = create_point(1820, 115);
	if (create_tab_int3(text, 20, TEXT2, BOLD) == FAILURE)
		return (FAILURE);
	if ((tmp = draw_text(win, "Speed :", point, text))
			&& tmp == FAILURE)
		return (FAILURE);
	if (draw_speed_cursor(win, speed_cursor, c_p_f) == FAILURE)
		return (FAILURE);
	point.x += tmp;
	return (SUCCESS);
}

/*
** ici if ret == the_end on renvoie failure en realite c'est simplement la fin
** du programme il faut donc check qui est le dernier a avoir dit qu'il etait en
** vie.
*/

int8_t			draw_infos(t_window *win, t_vm *env, t_draw infos)
{
	SDL_Rect	pos;

	pos = create_rect(1810, 5, 490, 145);
	if (draw_rectangle(win, pos, create_color(10, 9, 8, 255)))
		return (FAILURE);
	if (draw_infos_text(win, env) == FAILURE)
		return (FAILURE);
	if (draw_infos_text2(win, env) == FAILURE)
		return (FAILURE);
	if (draw_infos_text3(win, infos.cycles_per_sec, infos.cycle_per_frame)
			== FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
