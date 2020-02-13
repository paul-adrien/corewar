/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paullaurent <paullaurent@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:42:54 by tlandema          #+#    #+#             */
/*   Updated: 2020/01/23 15:28:38 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Creates a copy of the process and place the PC of the new process is :
**	PC = (ARG1 (T_DIR) % IDX_MOD) + POS_OF_OLD_PROCESS.
*/

void	op_fork(t_vm *vm, t_process *process)
{
	int32_t	param1;

	param1 = process->op.param[0];
	if (copy_process(vm, modulo(process->pc + (param1 % IDX_MOD),
												MEM_SIZE), process) == FAILURE)
	{
		delete_vm(vm);
		ft_printf("exit fork\n");
		exit(EXIT_FAILURE);
	}
	if (vm->verbose & F_VERBOSE_OP)
		show_op(process);
}
