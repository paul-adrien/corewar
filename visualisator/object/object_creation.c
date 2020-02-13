/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_creation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 14:36:26 by tlandema          #+#    #+#             */
/*   Updated: 2020/01/20 16:08:51 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "visualisator.h"

int8_t		create_tab_int3(int *dest, int size, int color, int style)
{
	if (dest == NULL)
		return (FAILURE);
	dest[0] = size;
	dest[1] = color;
	dest[2] = style;
	return (SUCCESS);
}

SDL_Rect	create_rect(int x, int y, int w, int h)
{
	SDL_Rect	result;

	result.x = x;
	result.y = y;
	result.w = w;
	result.h = h;
	return (result);
}

SDL_Point	create_point(int x, int y)
{
	SDL_Point	result;

	result.x = x;
	result.y = y;
	return (result);
}

SDL_Color	create_color(int r, int g, int b, int a)
{
	SDL_Color	result;

	result.r = r;
	result.g = g;
	result.b = b;
	result.a = a;
	return (result);
}
