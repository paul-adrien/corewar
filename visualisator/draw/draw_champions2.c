/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_champions2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 05:33:11 by tlandema          #+#    #+#             */
/*   Updated: 2020/01/21 17:14:56 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "visualisator.h"

int8_t	draw_champion_name(t_window *win, char *name, SDL_Point point,
		int text[3])
{
	int		i;
	int		j;
	char	tmp[27];

	j = 0;
	if ((i = ft_strlen(name)) && i > 26)
	{
		while (j < i)
		{
			ft_strncpy(tmp, &name[j], 26);
			tmp[26] = '\0';
			if (draw_text(win, tmp, point, text) == FAILURE)
				return (FAILURE);
			point.y += 12;
			j += 26;
		}
	}
	else if (draw_text(win, name, point,
			text) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int8_t	draw_last_live(t_window *win, int last_live, SDL_Point point,
		int text[3])
{
	char	*str;

	if (!(str = ft_lltoa(last_live)))
		return (FAILURE);
	if (draw_text(win, str, point, text) == FAILURE)
		return (strdel_ret_fail(str));
	ft_strdel(&str);
	return (SUCCESS);
}

int8_t	draw_champion_last_face(t_window *win, SDL_Point point, int text[3],
		int winner)
{
	point.x += 30;
	point.y += 70;
	if (winner)
	{
		if (draw_text(win, " 0       0", point, text) == FAILURE)
			return (FAILURE);
		point.y += 70;
		point.x -= 5;
		if (draw_text(win, "\\----------/", point, text) == FAILURE)
			return (FAILURE);
		return (SUCCESS);
	}
	if (draw_text(win, " X       X", point, text) == FAILURE)
		return (FAILURE);
	point.y += 70;
	point.x -= 5;
	if (draw_text(win, "/----------\\", point, text) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
