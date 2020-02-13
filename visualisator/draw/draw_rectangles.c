/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rectangles.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 14:42:42 by tlandema          #+#    #+#             */
/*   Updated: 2020/01/20 16:07:25 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "visualisator.h"

/*
**	All the functions we are using to draw rectangles in the renderer.
*/

int8_t	draw_rectangle(t_window *win, SDL_Rect rect, SDL_Color color)
{
	if (SDL_SetRenderDrawColor(win->renderer, color.r, color.g,
			color.b, color.a) < 0)
		return (FAILURE);
	if ((SDL_RenderFillRect(win->renderer, &rect) < 0))
		return (FAILURE);
	return (SUCCESS);
}

int8_t	draw_centred_rectangle(t_window *win, SDL_Rect rect, SDL_Color color)
{
	SDL_Rect tmp_rect;

	if (SDL_SetRenderDrawColor(win->renderer, color.r, color.g, color.b,
			color.a) < 0)
		return (FAILURE);
	tmp_rect.x = rect.x - rect.w / 2;
	tmp_rect.y = rect.y - rect.h / 2;
	tmp_rect.w = rect.w;
	tmp_rect.h = rect.h;
	if (SDL_RenderFillRect(win->renderer, &tmp_rect) < 0)
		return (FAILURE);
	return (SUCCESS);
}

int8_t	draw_border_rectangle(t_window *win, t_brect *infos, int border)
{
	SDL_Rect tmp_rect;

	if (draw_rectangle(win, infos->rect, infos->c_back) == FAILURE)
		return (FAILURE);
	tmp_rect.x = infos->rect.x + border;
	tmp_rect.y = infos->rect.y + border;
	tmp_rect.w = infos->rect.w - border * 2;
	tmp_rect.h = infos->rect.h - border * 2;
	if (draw_rectangle(win, tmp_rect, infos->c_front) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int8_t	draw_centred_border_rectangle(t_window *win, t_brect *infos, int border)
{
	SDL_Rect tmp_rect;

	if (draw_centred_rectangle(win, infos->rect, infos->c_back) == FAILURE)
		return (FAILURE);
	tmp_rect.x = infos->rect.x;
	tmp_rect.y = infos->rect.y;
	tmp_rect.w = infos->rect.w - border * 2;
	tmp_rect.h = infos->rect.h - border * 2;
	if (draw_centred_rectangle(win, tmp_rect, infos->c_front) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
