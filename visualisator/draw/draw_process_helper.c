/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_process_helper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 07:13:01 by tlandema          #+#    #+#             */
/*   Updated: 2020/01/21 17:18:31 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "visualisator.h"

char	*action_name(int32_t op_code)
{
	static char	*ret[17] = {"LIVE", "LD", "ST", "ADD", "SUB", "AND", "OR", "XOR"
						, "ZJMP", "LDI", "STI", "FORK", "LLD", "LLDI", "LFORK"
						, "AFF"};

	return (ret[op_code - 1]);
}

int32_t	draw_process_pos(t_window *win, t_process *proc, int text[3],
				SDL_Point point)
{
	char *str;

	if ((str = ft_lltoa(proc->pc / 64 + 1)) == NULL)
		return (FAILURE);
	if ((draw_text(win, str, point, text)) == FAILURE)
		return (strdel_ret_fail(str));
	ft_strdel(&str);
	point.x += 20;
	if ((str = ft_lltoa(proc->pc % 64 + 1)) == NULL)
		return (FAILURE);
	if (draw_text(win, "X", point, text) == FAILURE)
		return (strdel_ret_fail(str));
	point.x += 12;
	if (draw_text(win, str, point, text) == FAILURE)
		return (strdel_ret_fail(str));
	ft_strdel(&str);
	point.x += 45;
	return (point.x);
}

int8_t	draw_process_header(t_window *win, int text[3])
{
	SDL_Point	point;
	SDL_Rect	pos;

	point = create_point(1825, 710);
	pos = create_rect(1880, 705, 3, 585);
	text[0] = 20;
	if (draw_rectangle(win, pos, create_color(76, 96, 133, 255)) == FAILURE)
		return (FAILURE);
	pos.x += 70;
	if (draw_rectangle(win, pos, create_color(76, 96, 133, 255)) == FAILURE)
		return (FAILURE);
	pos = create_rect(1810, 735, 585, 3);
	if (draw_rectangle(win, pos, create_color(76, 96, 133, 255)) == FAILURE)
		return (FAILURE);
	if (draw_text(win, "PID", point, text) == FAILURE)
		return (FAILURE);
	point.x += 70;
	if (draw_text(win, "POS", point, text) == FAILURE)
		return (FAILURE);
	point.x += 175;
	if (draw_text(win, "ACTION", point, text) == FAILURE)
		return (FAILURE);
	text[0] = 18;
	return (SUCCESS);
}

int32_t	draw_process_num(t_window *win, t_process *proc, int text[3],
				SDL_Point point)
{
	char	*str;
	int32_t	tmp;

	if ((str = ft_lltoa(proc->num)) == NULL)
		return (FAILURE);
	point.x -= 5;
	if ((tmp = draw_text(win, str, point, text)) && tmp == FAILURE)
		return (strdel_ret_fail(str));
	ft_strdel(&str);
	point.x += 52;
	return (point.x + 20);
}
