/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 15:47:14 by tlandema          #+#    #+#             */
/*   Updated: 2020/01/21 13:02:36 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "visualisator.h"

/*
**	All the functions used to print some text, aswell as the global that we use
**	for the different text color, it should be moved in a .h file someday.
*/
SDL_Color g_color_tab[NB_COLOR] = {
	{0, 0, 0, 255},
	{240, 240, 240, 255},
	{135, 206, 250, 255},
	{30, 144, 255, 255},
	{0, 0, 139, 255},
	{221, 110, 110, 255},
	{165, 89, 89, 255},
	{110, 70, 70, 255},
	{170, 220, 115, 255},
	{89, 165, 89, 255},
	{30, 100, 60, 255},
	{127, 255, 212, 255},
	{64, 224, 208, 255},
	{0, 139, 139, 255},
	{175, 175, 175, 255},
	{86, 86, 86, 255},
	{56, 56, 56, 255},
	{255, 195, 0, 255},
	{250, 169, 22, 180},
	{131, 56, 236, 200},
	{215, 215, 215, 200},
	{64, 121, 140, 200},
	{255, 0, 110, 200},
	{255, 165, 0, 255},
	{76, 96, 133, 255},
	{57, 160, 237, 255}
};

static TTF_Font		*get_font(int size)
{
	static TTF_Font *font_tab[NB_SIZE];

	if (font_tab[size] == NULL)
		if (!(font_tab[size] = TTF_OpenFont(FONT_PATH, size)))
			return (NULL);
	return (font_tab[size]);
}

static t_image		*get_char(t_window *win, char c, int infos[3])
{
	static t_image	*text_tab[NB_SIZE][NB_COLOR][NB_STYLE][255];
	char			src[2];
	TTF_Font		*tmp_font;
	SDL_Color		color;

	src[0] = c;
	src[1] = '\0';
	if (text_tab[infos[0]][infos[1]][infos[2]][(int)c] == NULL)
	{
		if (!(tmp_font = get_font(infos[0])))
			return (NULL);
		if (tmp_font == NULL)
			return (NULL);
		TTF_SetFontStyle(tmp_font, infos[2]);
		if (infos[1] >= 0 && infos[1] <= NB_COLOR)
			color = g_color_tab[infos[1]];
		else
			color = g_color_tab[0];
		if (!(text_tab[infos[0]][infos[1]][infos[2]][(int)c] =
			malloc_t_image(win, TTF_RenderText_Blended(tmp_font, src, color))))
			return (NULL);
	}
	return (text_tab[infos[0]][infos[1]][infos[2]][(int)c]);
}

static int			calc_text_len(t_window *win, char *str, int infos[3])
{
	t_image			*image;
	int				i;
	int				delta;

	i = 0;
	delta = 0;
	while (i < str[i])
	{
		if (!(image = get_char(win, str[i], infos)))
			return (FAILURE);
		delta += image->surface->w;
		i++;
	}
	return (delta);
}

int					draw_text(t_window *win, char *str, SDL_Point pos,
					int infos[3])
{
	t_image		*tmp_img;
	SDL_Rect	coord;
	int			delta;
	int			len;
	int			i;

	len = ft_strlen(str);
	i = 0;
	delta = 0;
	while (i < len)
	{
		if (!(tmp_img = get_char(win, str[i], infos)))
			return (FAILURE);
		if (tmp_img == NULL)
			return (FAILURE);
		coord = create_rect(pos.x + delta, pos.y, tmp_img->surface->w,
				tmp_img->surface->h);
		if ((draw_image(win, tmp_img, coord) == FAILURE))
			return (FAILURE);
		delta += coord.w;
		i++;
	}
	return (delta);
}

int					draw_centred_text(t_window *win, char *str, SDL_Point pos,
					int infos[3])
{
	int x;
	int y;

	if ((x = calc_text_len(win, str, infos)) == FAILURE)
		return (FAILURE);
	if ((y = get_char(win, 'M', infos)->surface->h) == FAILURE)
		return (FAILURE);
	return (draw_text(win, str,
			create_point(pos.x - x / 2, pos.y - y / 2), infos));
}
