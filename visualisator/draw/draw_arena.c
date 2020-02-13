/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_arena.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 09:59:58 by tlandema          #+#    #+#             */
/*   Updated: 2020/01/21 17:04:18 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "visualisator.h"

/*
**	Reads a char in the memory and changes it to the corresponding hexadecimal
**	value.
*/

static int8_t	change_char_to_hexa(char str[4], unsigned char c)
{
	char *tmp;

	if (!(tmp = ft_ulltoa_ubase(c, "0123456789ABCDEF")))
		return (FAILURE);
	if (c < 16)
	{
		str[0] = '0';
		str[1] = tmp[0];
	}
	else
	{
		str[0] = tmp[0];
		str[1] = tmp[1];
	}
	str[2] = '\0';
	ft_strdel(&tmp);
	return (SUCCESS);
}

/*
**	Draws the header rectangle aswell as the arena rectangle.
*/

static int8_t	draw_arena_structure(t_window *win, t_process *list)
{
	SDL_Rect	pos;
	SDL_Point	point;
	SDL_Rect	pos2;
	int			text[3];

	point = create_point(800, 152);
	if (create_tab_int3(text, 30, TEXT2, BOLD) == FAILURE)
		return (FAILURE);
	pos = create_rect(5, 190, 1800, 1100);
	pos2 = create_rect(5, 155, 1800, 30);
	if (draw_rectangle(win, pos, create_color(10, 9, 8, 255)) == FAILURE)
		return (FAILURE);
	if (draw_rectangle(win, pos2, create_color(10, 9, 8, 255)) == FAILURE)
		return (FAILURE);
	if (draw_text(win, "ARENA", point, text) == FAILURE)
		return (FAILURE);
	if (list != NULL)
		if (draw_structure_sides(win) == FAILURE)
			return (FAILURE);
	return (SUCCESS);
}

/*
**	Draws the Arena filled with 00 before we launched the cycle.
*/

static int8_t	draw_uninit_arena(t_window *win)
{
	SDL_Point	point;
	int			text[3];
	int			count;

	point = create_point(45, 225);
	if (create_tab_int3(text, 17, TEXT2, BOLD) == FAILURE)
		return (FAILURE);
	count = 0;
	while (count < MEM_SIZE)
	{
		if (draw_text(win, "00", point, text) == FAILURE)
			return (FAILURE);
		point.x = (count % 2) ? point.x + 27 : point.x + 28;
		if ((count + 1) % 64 == 0 && count != 0)
		{
			point.y = ((count + 1) / 64 % 2) ? point.y + 16 : point.y + 17;
			point.x = 45;
		}
		count++;
	}
	return (SUCCESS);
}

/*
**	Draws the arena while the cycle have begun, whether it's stopped or running.
*/

static int8_t	draw_active_arena(t_window *win, t_vm *env)
{
	int			count;
	int			text[3];
	char		str[3];
	SDL_Point	point;

	count = -1;
	point = create_point(45, 225);
	while (++count < MEM_SIZE)
	{
		if (create_tab_int3(text, 17, TEXT2 + env->mem_owner[count], BOLD)
				== FAILURE)
			return (FAILURE);
		if (change_char_to_hexa(str, env->mem[count]) == FAILURE)
			return (FAILURE);
		if (draw_text(win, (char *)str, point, text) == FAILURE)
			return (FAILURE);
		point.x = (count % 2) ? point.x + 27 : point.x + 28;
		if ((count + 1) % 64 == 0 && count != 0)
		{
			point.y = ((count + 1) / 64 % 2) ? point.y + 16 : point.y + 17;
			point.x = 45;
		}
	}
	return (SUCCESS);
}

int8_t			draw_arena(t_window *win, t_vm *env, t_draw infos)
{
	if (draw_arena_structure(win, env->process_list) == FAILURE)
		return (FAILURE);
	if (env->process_list == NULL)
	{
		if (draw_arena_final(win, env) == FAILURE)
			return (FAILURE);
	}
	else if (infos.state == TO_START)
	{
		if (draw_uninit_arena(win) == FAILURE)
			return (FAILURE);
	}
	else if (draw_active_arena(win, env) == FAILURE)
		return (FAILURE);
	else if (underliner(win, env) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
