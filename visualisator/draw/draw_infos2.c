/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_infos2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 13:20:08 by tlandema          #+#    #+#             */
/*   Updated: 2020/01/21 17:17:06 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "visualisator.h"

int8_t	draw_infos_cycle(t_window *win, t_vm *env, SDL_Point point, int text[3])
{
	char *str;

	if (env->cycle_to_die <= 0)
	{
		if (draw_text(win, "0", point, text) == FAILURE)
			return (FAILURE);
	}
	else
	{
		if ((str = ft_lltoa(env->cycle_to_die)) && str == NULL)
			return (FAILURE);
		if (draw_text(win, str, point, text) == FAILURE)
			return (strdel_ret_fail(str));
		ft_strdel(&str);
	}
	return (SUCCESS);
}

int8_t	draw_speed_cursor(t_window *win, int speed_cursor, int c_p_f)
{
	SDL_Rect	pos_speed;
	SDL_Rect	pos_c_p_f;

	pos_speed = create_rect(1900, 113, (3 * speed_cursor), 15);
	pos_c_p_f = create_rect(1900, 128, (12 * c_p_f), 15);
	if (draw_rectangle(win, pos_speed, create_color(250, 169, 22, 180)))
		return (FAILURE);
	if (draw_rectangle(win, pos_c_p_f, create_color(114, 24, 23, 180)))
		return (FAILURE);
	return (SUCCESS);
}
