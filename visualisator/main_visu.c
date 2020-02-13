/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_visu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 09:53:59 by tlandema          #+#    #+#             */
/*   Updated: 2020/01/30 15:52:48 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "visualisator.h"

int8_t	main_visu(t_vm *env)
{
	t_window	win;

	if (open_window("Test", &win) == FAILURE)
		return (FAILURE);
	env->win = (void *)&win;
	if (drawer((t_window *)env->win, env) == FAILURE)
		return (FAILURE);
	if (env->cycle_to_dump < 0 || env->current_cycle < env->cycle_to_dump)
		winner(env, env->winner_index);
	return (SUCCESS);
}

void	cycle_actualisator(t_vm *env, t_process *process)
{
	exec_proc_list(env, process);
	check_cycle_to_die(env);
	++env->current_cycle;
	++env->current_sub_cycle;
}
