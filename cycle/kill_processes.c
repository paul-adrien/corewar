/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_processes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 16:02:11 by tlandema          #+#    #+#             */
/*   Updated: 2020/01/16 08:52:36 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static t_process	*kill_first_process(t_vm *env, t_process *process)
{
	env->process_list = env->process_list->next;
	free_process(&process);
	process = env->process_list;
	return (process);
}

static t_process	*kill_one_process(t_vm *env, t_process *process,
					t_process **prev)
{
	(void)env;
	process = process->next;
	free_process(&(*prev)->next);
	(*prev)->next = process;
	return (process);
}

void				kill_processes(t_vm *env)
{
	t_process	*process;
	t_process	*prev;

	process = env->process_list;
	prev = NULL;
	while (process)
	{
		if (process->last_live <= (env->current_cycle - env->cycle_to_die)
				|| env->cycle_to_die < 0)
		{
			if (env->verbose & F_VERBOSE_DEAD)
				ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n",
						process->num, (env->current_cycle - process->last_live),
						env->cycle_to_die);
			if (process == env->process_list)
				process = kill_first_process(env, process);
			else
				process = kill_one_process(env, process, &prev);
		}
		else
		{
			prev = process;
			process = process->next;
		}
	}
}
