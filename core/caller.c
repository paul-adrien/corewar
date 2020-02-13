/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caller.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 14:43:24 by tlandema          #+#    #+#             */
/*   Updated: 2020/01/12 21:57:41 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	player_caller(uint8_t nb_champ, t_champ champ[MAX_PLAYERS])
{
	int i;

	i = 0;
	ft_putendl("Introducing contestants...");
	while (i < nb_champ)
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n", i + 1,
				champ[i].size, champ[i].name, champ[i].comment);
		i++;
	}
}
