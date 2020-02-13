/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paullaurent <paullaurent@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:35:29 by brichard          #+#    #+#             */
/*   Updated: 2020/01/16 04:01:14 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	delete_process(t_process *to_delete)
{
	if (to_delete != NULL)
	{
		to_delete->next = NULL;
		ft_bzero((void *)to_delete->reg, sizeof(int32_t) * REG_NUMBER + 1);
		to_delete->pc = 0;
		to_delete->cycles_left = 0;
		to_delete->carry = 0;
		to_delete->active = 0;
	}
}
