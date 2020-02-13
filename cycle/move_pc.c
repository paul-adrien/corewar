/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_pc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 22:26:25 by tlandema          #+#    #+#             */
/*   Updated: 2020/01/14 14:51:37 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			modulo(int a, int b)
{
	if (a % b >= 0)
		return (a % b);
	else
		return ((a % b) + b);
}

static int	size_param(int ocp_chunk, t_op_tab *ref)
{
	if (ocp_chunk == 1)
		return (1);
	else if (ocp_chunk == 2)
		return ((ref->direct_size) ? 2 : 4);
	else if (ocp_chunk == 3)
		return (IND_SIZE);
	return (0);
}

/*
**	L46 : On saute au moins l'op_code
**	L48 : on a forcement un T_DIR si pas de bytecode
**	L50 : si byte code il faut sauter les params
**	L52 : plus de precision dans check_ocp.c
*/

int			move_pc(t_process *process)
{
	int			move;
	t_op_tab	*ref;

	move = 1;
	ref = &g_op_tab[process->op.op_code - 1];
	if (!ref->bytecode)
		return ((ref->direct_size) ? move + 2 : move + 4);
	else
		move++;
	if (ref->nb_param >= 1)
		move += size_param((process->op.ocp & 0xC0) >> 6, ref);
	if (ref->nb_param >= 2)
		move += size_param((process->op.ocp & 0x30) >> 4, ref);
	if (ref->nb_param >= 3)
		move += size_param((process->op.ocp & 0xC) >> 2, ref);
	return (modulo(move, MEM_SIZE));
}
