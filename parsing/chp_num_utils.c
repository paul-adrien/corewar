/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chp_num_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 12:20:56 by brichard          #+#    #+#             */
/*   Updated: 2020/01/17 15:26:43 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	attribute_next_chp_num(t_parser *parser)
{
	int8_t	i;

	i = 1;
	parser->chp_num = 1;
	while (i <= 4)
	{
		if (chp_num_is_attributed(parser) == FALSE)
			break ;
		++i;
		parser->chp_num = i;
	}
}

uint8_t	chp_num_is_attributed(t_parser *parser)
{
	int8_t	i;

	i = 0;
	while (i < 4 && parser->env.champ[i].num != 0)
	{
		if (parser->env.champ[i].num == parser->chp_num)
			return (TRUE);
		++i;
	}
	return (FALSE);
}
