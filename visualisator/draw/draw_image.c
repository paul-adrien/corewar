/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:32:49 by tlandema          #+#    #+#             */
/*   Updated: 2020/01/20 16:06:37 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "visualisator.h"

/*
**	Draw image is mallocing a surface in a file and copied it in a t_image.
**	It is mostly use for draw_text that recuperates the different letters or
**	symbol using thee ttf library and resources.
*/

t_image	*malloc_t_image(t_window *win, SDL_Surface *p_surface)
{
	t_image *result;

	if (!(result = (t_image *)ft_memalloc(sizeof(t_image))))
		return (NULL);
	result->surface = p_surface;
	if (!(result->texture = SDL_CreateTextureFromSurface(win->renderer,
			result->surface)))
		return (NULL);
	return (result);
}

int8_t	draw_image(t_window *win, t_image *image, SDL_Rect dest)
{
	if ((SDL_RenderCopy(win->renderer, image->texture, NULL, &dest) < 0))
		return (FAILURE);
	return (SUCCESS);
}
