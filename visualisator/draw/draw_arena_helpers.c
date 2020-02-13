/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_arena_helpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 14:42:06 by tlandema          #+#    #+#             */
/*   Updated: 2020/01/23 16:19:08 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "visualisator.h"

int8_t			strdel_ret_fail(char *str)
{
	ft_strdel(&str);
	return (FAILURE);
}

static int8_t	draw_structure_sides2(t_window *win, int text[3])
{
	SDL_Point	point;
	char		*str;
	int			i;

	i = 0;
	point = create_point(15, 227);
	while (++i <= 64)
	{
		if (!(str = ft_lltoa(i)))
			return (FAILURE);
		if (draw_text(win, str, point, text) == FAILURE)
			return (strdel_ret_fail(str));
		ft_strdel(&str);
		point.y = (i % 2) ? point.y + 16 : point.y + 17;
	}
	return (SUCCESS);
}

int8_t			draw_structure_sides(t_window *win)
{
	SDL_Point	point;
	int			text[3];
	char		*str;
	int			i;

	i = 0;
	point = create_point(48, 205);
	if (create_tab_int3(text, 14, BLUE, BOLD)
			== FAILURE)
		return (FAILURE);
	while (++i <= 64)
	{
		if (!(str = ft_lltoa(i)))
			return (FAILURE);
		if (draw_text(win, str, point, text) == FAILURE)
			return (strdel_ret_fail(str));
		ft_strdel(&str);
		point.x = (i % 2) ? point.x + 27 : point.x + 28;
	}
	if (draw_structure_sides2(win, text) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

static int8_t	underliner_helper(t_window *win, SDL_Point point, int text[3],
				uint8_t underliner)
{
	if (underliner)
		if (draw_text(win, "|    |", point, text) == FAILURE)
			return (FAILURE);
	point.y += 2;
	if (draw_text(win, "__", point, text) == FAILURE)
		return (FAILURE);
	point.x += 3;
	if (draw_text(win, "_", point, text) == FAILURE)
		return (FAILURE);
	point.x += 12;
	if (draw_text(win, "_", point, text) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int8_t			underliner(t_window *win, t_vm *env)
{
	SDL_Point	point;
	int			text[3];
	int			tmp_mod;
	int			tmp_div;
	t_process	*process_list;

	process_list = env->process_list;
	while (process_list)
	{
		if (create_tab_int3(text, 17, TEXT2 + env->mem_owner[process_list->pc],
				BOLD) == FAILURE)
			return (FAILURE);
		tmp_mod = (process_list->pc % 64);
		tmp_div = (process_list->pc / 64);
		point.x = tmp_mod / 2 * 55 + tmp_mod % 2 * 27 + 42;
		point.y = tmp_div / 2 * 33 + tmp_div % 2 * 16 + 224;
		underliner_helper(win, point, text, 1);
		point.y -= 15;
		underliner_helper(win, point, text, 0);
		process_list = process_list->next;
	}
	return (SUCCESS);
}
