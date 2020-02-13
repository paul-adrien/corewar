/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 23:12:40 by tlandema          #+#    #+#             */
/*   Updated: 2020/01/16 15:47:34 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	show_st(t_process *process)
{
	if (process->op.type_param[1] == REG_CODE)
		ft_printf("P %4d | st r%d %d\n", process->num, process->op.param[0],
				process->op.param[1]);
}

void	show_op(t_process *process)
{
	uint8_t	i;

	i = 0;
	if (process->op.op_code == 3 && process->op.type_param[1] == REG_CODE)
	{
		show_st(process);
		return ;
	}
	ft_printf("P %4d | %s ", process->num,
		g_op_tab[process->op.op_code - 1].name);
	while (i < g_op_tab[process->op.op_code - 1].nb_param)
	{
		if (process->op.type_param[i] == REG_CODE)
			ft_putchar('r');
		ft_printf("%d", process->op.param[i]);
		if (i + 1 < g_op_tab[process->op.op_code - 1].nb_param)
			ft_putchar(' ');
		i++;
	}
	if (process->op.op_code == 9 && process->carry == 1)
		ft_putstr(" OK");
	if (process->op.op_code == 12 || process->op.op_code == 15)
		ft_printf(" (%d)", process->pc + process->op.param[0]);
	ft_putchar('\n');
}
