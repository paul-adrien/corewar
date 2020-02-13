/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 22:43:21 by tlandema          #+#    #+#             */
/*   Updated: 2020/01/16 15:44:11 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Loads the value passed in the first parameter (T_DIR/T_IND) inside of the
**	second argument (T_REG). If the value passed in the register was equal to
**	zero then the carry = 1, if it wasn't null then carry = 0.
*/

static void	put_ind_in_reg(t_vm *vm, t_process *process, int reg_n)
{
	int		addr;

	addr = process->op.param[0] % IDX_MOD;
	process->reg[reg_n] = 0;
	process->reg[reg_n] |= (unsigned char)vm->mem[modulo(process->op.pos_op_code
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

void		ld(t_vm *vm, t_process *process)
{
	int	reg_nb;

	reg_nb = process->op.param[1] - 1;
	if (process->op.type_param[0] == IND_CODE)
		put_ind_in_reg(vm, process, reg_nb);
	else
		process->reg[reg_nb] = process->op.param[0];
	process->carry = (process->reg[reg_nb] == 0 ? 1 : 0);
	if (vm->verbose & F_VERBOSE_OP)
		show_op(process);
}
