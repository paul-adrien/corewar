/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 11:45:29 by brichard          #+#    #+#             */
/*   Updated: 2020/01/16 15:40:44 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Substract the value of the second to the first parameter (T_REG), and stock
**	the result int he third parameter (T_REG). If the result = 0 then
**	carry = 1 else carry = 0.
*/

void	sub(t_vm *vm, t_process *process)
{
	int		sub;
	int32_t	param1;
	int32_t	param2;
	int32_t	param3;

	param1 = process->op.param[0] - 1;
	param2 = process->op.param[1] - 1;
	param3 = process->op.param[2] - 1;
	if (param1 >= 0 && param1 <= REG_NUMBER - 1
			&& param2 >= 0 && param2 <= REG_NUMBER - 1
			&& param3 >= 0 && param3 <= REG_NUMBER - 1)
	{
		sub = process->reg[param1] - process->reg[param2];
		process->reg[param3] = sub;
		process->carry = (sub == 0 ? 1 : 0);
		if (vm->verbose & F_VERBOSE_OP)
			show_op(process);
	}
}
