/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 22:47:05 by tlandema          #+#    #+#             */
/*   Updated: 2020/01/16 15:43:40 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Loads the value (value = ARG1 (T_DIR/T_REG/T_IND) + ARG2 (T_REG/T_DIR))
**	of the first two arguments inside the third one (T_REG).
*/

int					check_params_ldi_lldi(t_process *process)
{
	if (process->op.type_param[0] == REG_CODE && (process->op.param[0] < 1
		|| process->op.param[0] > REG_NUMBER))
		return (0);
	else if (process->op.type_param[1] == REG_CODE && (process->op.param[1] < 1
		|| process->op.param[1] > REG_NUMBER))
		return (0);
	else if (process->op.type_param[2] == REG_CODE && (process->op.param[2] < 1
		|| process->op.param[2] > REG_NUMBER))
		return (0);
	else
		return (1);
}

static unsigned int	get_value(t_vm *vm, unsigned int addr)
{
	unsigned int	value;

	value = 0;
	value |= (unsigned char)vm->mem[modulo(addr, MEM_SIZE)];
	value = value << 8;
	value |= (unsigned char)vm->mem[modulo(addr + 1, MEM_SIZE)];
	value = value << 8;
	value |= (unsigned char)vm->mem[modulo(addr + 2, MEM_SIZE)];
	value = value << 8;
	value |= (unsigned char)vm->mem[modulo(addr + 3, MEM_SIZE)];
	return (value);
}

void				ldi(t_vm *vm, t_process *process)
{
	int32_t			param1;
	int32_t			param2;
	int32_t			param3;
	unsigned int	addr;

	if (!check_params_ldi_lldi(process))
		return ;
	if (process->op.type_param[0] == REG_CODE)
		param1 = process->reg[process->op.param[0] - 1];
	else if (process->op.type_param[0] == IND_CODE)
		param1 = get_indirecte(vm, &process->op, 0);
	else
		param1 = process->op.param[0];
	if (process->op.type_param[1] == REG_CODE)
		param2 = process->reg[process->op.param[1] - 1];
	else
		param2 = process->op.param[1];
	param3 = process->op.param[2] - 1;
	addr = ((param1 + param2) % IDX_MOD)
		+ process->op.pos_op_code;
	process->reg[param3] = get_value(vm, addr);
	if (vm->verbose & F_VERBOSE_OP)
		show_op(process);
}
