/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paullaurent <paullaurent@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:35:29 by brichard          #+#    #+#             */
/*   Updated: 2020/01/30 17:00:06 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_vm	init_vm(void)
{
	t_vm	new_vm;

	new_vm.process_list = NULL;
	ft_bzero((void *)new_vm.champ, sizeof(t_champ) * MAX_PLAYERS);
	ft_bzero((void *)new_vm.mem, sizeof(char) * MEM_SIZE);
	ft_bzero((void *)new_vm.mem_owner, sizeof(uint8_t) * MEM_SIZE);
	new_vm.win = NULL;
	new_vm.current_cycle = 1;
	new_vm.current_sub_cycle = 1;
	new_vm.cycle_to_die = CYCLE_TO_DIE;
	new_vm.live_count = 0;
	new_vm.live_check_count = 0;
	new_vm.cycle_to_dump = -1;
	new_vm.champ_amount = 0;
	new_vm.verbose = 1;
	new_vm.winner_index = 0;
	return (new_vm);
}
