/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_command_panel.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 09:35:29 by tlandema          #+#    #+#             */
/*   Updated: 2020/01/21 13:34:43 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "visualisator.h"

/*
**	Draw infos about the command to use the visualisator.
*/

static int8_t	command_more_info(t_window *win, int *text)
{
	if (draw_text(win, "\'Left/Right\' : Move in process list",
			create_point(520, 120), text) == FAILURE)
		return (FAILURE);
	if (draw_text(win, "\'O\'                       : Speed Down",
			create_point(900, 50), text) == FAILURE)
		return (FAILURE);
	if (draw_text(win, "\'P\'                       : Speed Up",
			create_point(900, 120), text) == FAILURE)
		return (FAILURE);
	if (draw_text(win, "\'K\' : Cycle Per Frame Down",
			create_point(1500, 50), text) == FAILURE)
		return (FAILURE);
	if (draw_text(win, "\'L\' : Cycle Per Frame UP",
			create_point(1500, 120), text) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

/*
**	Draw infos about the command to use the visualisator.
*/

static int8_t	command_info(t_window *win, int i)
{
	SDL_Point	point;
	int			text[3];

	if (create_tab_int3(text, 20, TEXT2, BOLD) == FAILURE)
		return (FAILURE);
	point = create_point(520, 50);
	if (i == TO_START)
	{
		if (draw_text(win, "\'space\' : Install champions", point,
				text) == FAILURE)
			return (FAILURE);
	}
	else if (i == PAUSED)
	{
		if (draw_text(win, "\'space\' : Launch", point, text) == FAILURE)
			return (FAILURE);
	}
	else
	{
		if (draw_text(win, "\'space\' : Pause", point, text) == FAILURE)
			return (FAILURE);
	}
	if (command_more_info(win, text) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

/*
**	Draw infos about the command to use the visualisator, it depends of the
**	state of the machine.
*/

int8_t			draw_command_panel(t_window *win, int i)
{
	SDL_Rect	pos;
	SDL_Point	point;
	int			command_text[3];

	point = create_point(1000, 15);
	if (create_tab_int3(command_text, 30, TEXT2, BOLD) == FAILURE)
		return (FAILURE);
	pos = create_rect(510, 5, 1295, 145);
	if (draw_rectangle(win, pos, create_color(10, 9, 8, 255)) == FAILURE)
		return (FAILURE);
	if (draw_text(win, "COMMANDS :", point, command_text) == FAILURE)
		return (FAILURE);
	if (command_info(win, i) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
