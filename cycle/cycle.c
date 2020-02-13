/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:39:12 by tlandema          #+#    #+#             */
/*   Updated: 2020/01/30 15:48:16 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int				is_opcode(char data)
{
	if (data > 0 && data < 17)
		return (TRUE);
	return (FALSE);
}

uint8_t			must_dump(t_vm *vm)
{
	if ((int32_t)vm->current_cycle == vm->cycle_to_dump + 1
			&& vm->cycle_to_dump != -1)
	{
		show_mem(vm);
		return (TRUE);
	}
	return (FALSE);
}

/*
**	take_op_param recup et check les params
**	L62 : on check que zjump c'est pas deja move le pc
**	L63 : on move le pc en fonction du nombre de param
*/

void			exec_process(t_vm *vm, t_process *process)
{
	if (process->op.active == 0)
	{
		if (is_opcode(vm->mem[process->pc % MEM_SIZE]))
			create_op(process, vm->mem[process->pc % MEM_SIZE]);
		else
			process->pc = (process->pc + 1) % MEM_SIZE;
	}
	else
	{
		if (--process->op.nb_cycle <= 0)
		{
			if (take_param_op(vm, process))
			{
				g_op_tab[process->op.op_code - 1].func(vm, process);
			}
			if (process->op.op_code != 9 || (process->op.op_code == 9
					&& !process->carry))
				process->pc += move_pc(process);
			process->pc = modulo(process->pc, MEM_SIZE);
			delete_op(process);
		}
	}
}

void			exec_proc_list(t_vm *vm, t_process *process)
{
	while (process != NULL)
	{
		exec_process(vm, process);
		process = process->next;
	}
}

void			cycle(t_vm *env)
{
	t_process	**d_process;

	d_process = &env->process_list;
	while (*d_process != NULL && must_dump(env) == FALSE)
	{
		if (env->verbose & F_VERBOSE_CYCLE)
			ft_printf("It is now cycle %d\n", env->current_cycle);
		exec_proc_list(env, (*d_process));
		check_cycle_to_die(env);
		++env->current_cycle;
		++env->current_sub_cycle;
	}
	if (env->cycle_to_dump < 0 || env->current_cycle < env->cycle_to_dump)
		winner(env, env->winner_index);
}
