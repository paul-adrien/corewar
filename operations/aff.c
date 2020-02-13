/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paullaurent <paullaurent@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 14:16:37 by brichard          #+#    #+#             */
/*   Updated: 2020/01/30 17:21:36 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	aff(t_vm *vm, t_process *process)
{
	int32_t	param1;

	(void)vm;
	param1 = process->reg[process->op.param[0] - 1];
	if (vm->verbose & F_VERBOSE_AFF)
		ft_putchar(param1 % 255);
}
