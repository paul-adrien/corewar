/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_final_arena.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:12:19 by tlandema          #+#    #+#             */
/*   Updated: 2020/01/21 17:15:41 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "visualisator.h"

static int8_t	draw_winner_champ(t_window *win, t_champ champion)
{
	SDL_Point	point;
	int			text[3];
	char		*str;

	point = create_point(80, 550);
	if (create_tab_int3(text, 100, TEXT2 + champion.num, BOLD) == FAILURE)
		return (FAILURE);
	if (ft_strlen(champion.name) > 15)
	{
		if ((str = ft_strndup(champion.name, 15)) && str == NULL)
			return (FAILURE);
		if (draw_text(win, str, point, text) == FAILURE)
			return (strdel_ret_fail(str));
		ft_strdel(&str);
	}
	else if (draw_text(win, champion.name, point, text) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

static int8_t	draw_loser_champ(t_window *win, t_champ champion, int ind)
{
	SDL_Point	point;
	int			text[3];
	char		*str;

	point = create_point(1050, 550 + (ind * 160));
	if (create_tab_int3(text, 70, DARK_GREEN, BOLD) == FAILURE)
		return (FAILURE);
	if (ft_strlen(champion.name) > 12)
	{
		if ((str = ft_strndup(champion.name, 12)) && str == NULL)
			return (FAILURE);
		if (draw_text(win, str, point, text) == FAILURE)
			return (strdel_ret_fail(str));
		ft_strdel(&str);
	}
	else if (draw_text(win, champion.name, point, text) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

static int8_t	draw_champ_in_places(t_window *win, t_vm *env)
{
	int i;
	int j;

	i = -1;
	j = 0;
	while (++i < env->champ_amount)
	{
		if (i == env->winner_index)
		{
			if (draw_winner_champ(win, env->champ[i]) == FAILURE)
				return (FAILURE);
		}
		else if (draw_loser_champ(win, env->champ[i], j++) == FAILURE)
			return (FAILURE);
	}
	return (SUCCESS);
}

int8_t			draw_arena_final(t_window *win, t_vm *env)
{
	SDL_Point	point;
	SDL_Rect	pos;
	int			text[3];

	pos = create_rect(900, 190, 30, 1100);
	point = create_point(150, 250);
	if (create_tab_int3(text, 100, TEXT2, BOLD) == FAILURE)
		return (FAILURE);
	if (draw_rectangle(win, pos, create_color(250, 169, 22, 180)) == FAILURE)
		return (FAILURE);
	if (draw_text(win, "WINNER", point, text) == FAILURE)
		return (FAILURE);
	point.x += 1050;
	text[1] = DARK_GREEN;
	if (draw_text(win, "LOSER", point, text) == FAILURE)
		return (FAILURE);
	if (draw_champ_in_places(win, env) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
