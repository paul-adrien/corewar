/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 14:37:42 by brichard          #+#    #+#             */
/*   Updated: 2020/01/16 10:07:44 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int8_t	get_ind(t_vm *vm, t_process *proc, int num, int pos)
{
	unsigned int	value;

	value = 0;
	value = value | (unsigned char)vm->mem[(pos + 1) % MEM_SIZE];
	value = value << 8;
	value = value | (unsigned char)vm->mem[(pos + 2) % MEM_SIZE];
	proc->op.param[num] = value;
	if ((value & 0x8000) == 0x8000)
		proc->op.param[num] = (value - USHRT_MAX) - 1;
	return (IND_SIZE);
}

static void		get_dir(t_vm *vm, t_process *proc, int num, int pos)
{
	unsigned int	value;

	value = 0;
	value = value | (unsigned char)vm->mem[(pos + 1) % MEM_SIZE];
	value = value << 8;
	value = value | (unsigned char)vm->mem[(pos + 2) % MEM_SIZE];
	if (g_op_tab[proc->op.op_code - 1].direct_size == 1)
	{
		if ((value & 0x8000) == 0x8000)
			value = (value - USHRT_MAX) - 1;
		proc->op.param[num] = value;
		return ;
	}
	value = value << 8;
	value = value | (unsigned char)vm->mem[(pos + 3) % MEM_SIZE];
	value = value << 8;
	value = value | (unsigned char)vm->mem[(pos + 4) % MEM_SIZE];
	proc->op.param[num] = value;
}

static int8_t	get_reg(t_vm *vm, t_process *proc, int num, int pos)
{
	unsigned char	value;

	value = (unsigned char)vm->mem[(pos + 1) % MEM_SIZE];
	proc->op.param[num] = value;
	if (value < 1 || value > 16)
		return (-1);
	return (1);
}

static int		find_param(t_vm *vm, t_process *proc, int num, int pos)
{
	unsigned char	type;
	unsigned char	mask;

	type = proc->op.ocp;
	mask = 0xC0;
	mask >>= (2 * num);
	type &= mask;
	type >>= (6 - 2 * num);
	proc->op.type_param[num] = type;
	if (type == REG_CODE)
		return (get_reg(vm, proc, num, pos));
	else if (type == DIR_CODE)
	{
		get_dir(vm, proc, num, pos);
		return ((g_op_tab[proc->op.op_code - 1].direct_size ? 2 : 4));
	}
	else if (type == IND_CODE)
		return (get_ind(vm, proc, num, pos));
	return (0);
}

int				take_param_op(t_vm *vm, t_process *process)
{
	uint32_t	i;
	int32_t		pos;
	int32_t		tmp;

	i = 0;
	pos = process->pc;
	if (g_op_tab[process->op.op_code - 1].bytecode)
	{
		pos++;
		process->op.ocp = (unsigned char)vm->mem[pos % MEM_SIZE];
		if (check_ocp(process->op.ocp, process->op.op_code) != 1)
			return (0);
		while (i < g_op_tab[process->op.op_code - 1].nb_param)
		{
			tmp = find_param(vm, process, i, pos);
			if (tmp == -1)
				return (0);
			pos += tmp;
			i++;
		}
	}
	else
		get_dir(vm, process, 0, pos);
	return (1);
}
