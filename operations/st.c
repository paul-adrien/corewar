/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 23:13:27 by tlandema          #+#    #+#             */
/*   Updated: 2020/01/16 15:41:20 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Takes the value in the first parameter (T_REG) and passes it either on a
**	register or in the memory (T_REG/T_IND).
*/

void	func(t_vm *vm, t_process *process)
{
	unsigned int	addr;
	int32_t			reg_nb;

	reg_nb = process->op.param[0] - 1;
	addr = process->op.pos_op_code + (process->op.param[1] % IDX_MOD);
	vm->mem[modulo(addr, MEM_SIZE)] =
									(char)(process->reg[reg_nb] >> 24);
	vm->mem_owner[modulo(addr, MEM_SIZE)] = process->visu_num;
	vm->mem[modulo(addr + 1, MEM_SIZE)] =
									(char)(process->reg[reg_nb] >> 16);
	vm->mem_owner[modulo(addr + 1, MEM_SIZE)] = process->visu_num;
	vm->mem[modulo(addr + 2, MEM_SIZE)] =
									(char)(process->reg[reg_nb] >> 8);
	vm->mem_owner[modulo(addr + 2, MEM_SIZE)] = process->visu_num;
	vm->mem[modulo(addr + 3, MEM_SIZE)] = (char)process->reg[reg_nb];
	vm->mem_owner[modulo(addr + 3, MEM_SIZE)] = process->visu_num;
}

void	st(t_vm *vm, t_process *process)
{
	if ((process->op.type_param[0] == REG_CODE && (process->op.param[0] < 1
					|| process->op.param[0] > REG_NUMBER))
					|| (process->op.type_param[1] == REG_CODE
					&& (process->op.param[1] < 1
					|| process->op.param[1] > REG_NUMBER)))
		return ;
	if (process->op.type_param[1] == REG_CODE)
		process->reg[process->op.param[1] - 1] =
										process->reg[process->op.param[0] - 1];
	else
		func(vm, process);
	if (vm->verbose & F_VERBOSE_OP)
		show_op(process);
}
