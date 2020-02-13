/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paullaurent <paullaurent@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 16:37:42 by tlandema          #+#    #+#             */
/*   Updated: 2020/01/16 06:27:09 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int8_t	copy_process(t_vm *vm, int pc_address, t_process *process)
{
	t_process	*son;
	int			i;

	i = -1;
	if ((son = create_process(process->reg[0], process->pc,
			process->visu_num)) == NULL)
		return (FAILURE);
	init_op(&son->op);
	son->carry = process->carry;
	son->pc = pc_address;
	son->cycles_left = 0;
	son->last_live = process->last_live;
	while (++i < REG_NUMBER)
		son->reg[i] = process->reg[i];
	son->next = vm->process_list;
	vm->process_list = son;
	return (SUCCESS);
}
