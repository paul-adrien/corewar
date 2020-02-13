/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 11:59:49 by brichard          #+#    #+#             */
/*   Updated: 2020/01/16 15:40:15 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Performs a bitwise XOR operation for the values of the first two
**	arguments (T_DIR/T_REG/T_IND) and writes the result to the third
**	argument. (T_REG)
**	if the result of the operation = 0 then carry = 0 else carry = 1.
*/

static void	get_param(t_vm *vm, t_process *process,
											int32_t *param1, int32_t *param2)
{
	if (process->op.type_param[0] == REG_CODE)
		*param1 = process->reg[process->op.param[0] - 1];
	else if (process->op.type_param[0] == IND_CODE)
		*param1 = get_indirecte(vm, &process->op, 0);
	else
		*param1 = process->op.param[0];
	if (process->op.type_param[1] == REG_CODE)
		*param2 = process->reg[process->op.param[1] - 1];
	else if (process->op.type_param[1] == IND_CODE)
		*param2 = get_indirecte(vm, &process->op, 1);
	else
		*param2 = process->op.param[1];
}

void		xor(t_vm *vm, t_process *process)
{
	int32_t	*d_param;
	int32_t	param1;
	int32_t	param2;

	d_param = process->op.param;
	if ((process->op.type_param[0] ==
				REG_CODE && (d_param[0] < 1 || d_param[0] > REG_NUMBER))
				|| (process->op.type_param[1] == REG_CODE
				&& (d_param[1] < 1 || d_param[1] > REG_NUMBER))
				|| (d_param[2] < 1 || d_param[2] > REG_NUMBER))
		return ;
	get_param(vm, process, &param1, &param2);
	process->reg[process->op.param[2] - 1] = param1 ^ param2;
	process->carry = (param1 ^ param2) == 0 ? 1 : 0;
	if (vm->verbose & F_VERBOSE_OP)
		show_op(process);
}
