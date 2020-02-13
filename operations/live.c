/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 15:02:53 by tlandema          #+#    #+#             */
/*   Updated: 2020/01/30 16:59:09 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	The live function looks at the only parameter (T_DIR), if it is the number
**	of a player it will then ping the vm that the player last_live_cycle =
**	current_cycle.
*/

void	live(t_vm *vm, t_process *process)
{
	int32_t	num;

	++vm->live_count;
	process->last_live = vm->current_cycle;
	num = -process->op.param[0] - 1;
	if (num >= 0 && num <= vm->champ_amount - 1)
	{
		vm->champ[num].last_live_cycle = vm->current_cycle;
		vm->winner_index = num;
		if (vm->verbose != F_VERBOSE_LIVE)
			ft_printf("Player %d (%s) is said to be alive\n", num + 1,
					vm->champ[num].name);
	}
	if (vm->verbose & F_VERBOSE_OP)
		show_op(process);
}
