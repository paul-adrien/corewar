/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 22:50:08 by tlandema          #+#    #+#             */
/*   Updated: 2020/01/16 15:42:29 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Works exactly as the ld operation appart from the fact that the IDX_MOD
**	is not applied.
*/

static void	put_ind_in_reg(t_vm *vm, t_process *process, int reg_n)
{
	int	addr;

	addr = process->op.param[0];
	process->reg[reg_n] = 0;
	process->reg[reg_n] = (unsigned char)vm->mem[modulo(process->op.pos_op_code
		+ addr, MEM_SIZE)];
	process->reg[reg_n] <<= 8;
	process->reg[reg_n] |= (unsigned char)vm->mem[modulo(process->op.pos_op_code
		+ addr + 1, MEM_SIZE)];
	process->reg[reg_n] <<= 8;
	process->reg[reg_n] |= (unsigned char)vm->mem[modulo(process->op.pos_op_code
		+ addr + 2, MEM_SIZE)];
	process->reg[reg_n] <<= 8;
	process->reg[reg_n] |= (unsigned char)vm->mem[modulo(process->op.pos_op_code
		+ addr + 3, MEM_SIZE)];
}

void		lld(t_vm *vm, t_process *process)
{
	int	reg_nb;

	reg_nb = process->op.param[1];
	if (reg_nb >= 1 && reg_nb <= REG_NUMBER)
	{
		if (process->op.type_param[0] == IND_CODE)
			put_ind_in_reg(vm, process, reg_nb - 1);
		else
			process->reg[reg_nb - 1] = process->reg[process->op.param[0] - 1];
		process->carry = ((process->reg[reg_nb - 1] == 0) ? 1 : 0);
		if (vm->verbose & F_VERBOSE_OP)
			show_op(process);
	}
}
