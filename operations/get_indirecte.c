/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_indirecte.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 14:37:22 by brichard          #+#    #+#             */
/*   Updated: 2020/01/13 14:53:48 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		get_indirecte(t_vm *vm, t_op *op, int nb_arg)
{
	int		value;
	int		pos;

	value = 0;
	pos = op->pos_op_code + (op->param[nb_arg] % IDX_MOD);
	value = value | (unsigned char)vm->mem[modulo(pos, MEM_SIZE)];
	value = value << 8;
	value = value | (unsigned char)vm->mem[modulo(pos + 1, MEM_SIZE)];
	value = value << 8;
	value = value | (unsigned char)vm->mem[modulo(pos + 2, MEM_SIZE)];
	value = value << 8;
	value = value | (unsigned char)vm->mem[modulo(pos + 3, MEM_SIZE)];
	return (value);
}
