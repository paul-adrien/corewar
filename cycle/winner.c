/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   winner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 22:17:27 by tlandema          #+#    #+#             */
/*   Updated: 2020/01/17 17:06:34 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	winner(t_vm *vm, uint8_t winner)
{
	ft_printf("Contestant %d, \"%s\", has won !\n", vm->champ[winner].num,
			vm->champ[winner].name);
}
