/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 16:28:56 by brichard          #+#    #+#             */
/*   Updated: 2020/01/15 16:29:15 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	show_mem(t_vm *vm)
{
	int	i;

	i = 0;
	ft_printf("0x0000 : ");
	while (i < MEM_SIZE)
	{
		if (!(i % 64) && i)
			ft_printf("%#.4x : ", i);
		ft_printf("%02x ", (unsigned char)vm->mem[i]);
		if (i / 64 != (i + 1) / 64)
			ft_printf("\n");
		i++;
	}
}
