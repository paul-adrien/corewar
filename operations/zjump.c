/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjump.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 11:55:14 by brichard          #+#    #+#             */
/*   Updated: 2020/01/16 15:38:57 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	If carry = 1 then PC = CUR_POS + (ARG1 (T_DIR) % IDX_MOD)
**	else if carr = 0 nothing is done.
*/

void	zjump(t_vm *vm, t_process *process)
{
	if (process->carry == 1)
	{
		process->pc = modulo(process->op.pos_op_code
				+ (process->op.param[0] % IDX_MOD), MEM_SIZE);
	}
	if (vm->verbose & F_VERBOSE_OP)
		show_op(process);
}
