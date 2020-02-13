/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 14:44:45 by tlandema          #+#    #+#             */
/*   Updated: 2020/01/23 15:55:15 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "visualisator.h"

int8_t	open_window(char *name, t_window *win)
{
	SDL_DisplayMode	current;

	if (SDL_Init(SDL_INIT_EVERYTHING) != SUCCESS)
		return (FAILURE);
	if (TTF_Init() == FAILURE)
		return (FAILURE);
	if (SDL_GetDesktopDisplayMode(0, &current) < 0)
		return (FAILURE);
	win->x = current.w * 0.9;
	win->y = current.h * 0.9;
	if (!(win->window = SDL_CreateWindow(name, SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, win->x, win->y, 0)))
		return (FAILURE);
	if (!(win->renderer = SDL_CreateRenderer(win->window, -1,
			SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)))
		return (FAILURE);
	if (SDL_SetRenderDrawBlendMode(win->renderer, SDL_BLENDMODE_BLEND) < 0)
		return (FAILURE);
	return (SUCCESS);
}
