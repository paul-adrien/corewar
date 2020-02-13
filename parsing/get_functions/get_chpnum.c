/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_chpnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 16:34:24 by tlandema          #+#    #+#             */
/*   Updated: 2020/01/17 15:41:32 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		swap_chp_num(t_parser *parser)
{
	int8_t	i;

	i = 0;
	while (i < 4 && parser->env.champ[i].num != 0)
	{
		if (parser->env.champ[i].num == parser->chp_num)
			parser->env.champ[i].num = parser->cur_chp_index + 1;
		++i;
	}
}

static uint8_t	flag_n_already_given(t_parser *parser)
{
	int8_t	i;

	i = 0;
	while (i < 4 && parser->env.champ[i].num != 0)
	{
		if (parser->chp_num == parser->flag_n[i])
			return (TRUE);
		++i;
	}
	return (FALSE);
}

void			get_chpnum(t_parser *parser, char **av)
{
	if (ft_strcheck(*av, ft_isdigit) == TRUE)
	{
		parser->chp_num = ft_atol(*av);
		parser->flag_n[parser->cur_chp_index] = parser->chp_num;
		if (parser->chp_num > 0 && parser->chp_num <= MAX_PLAYERS
				&& flag_n_already_given(parser) == FALSE)
		{
			if (chp_num_is_attributed(parser) == TRUE)
				swap_chp_num(parser);
			parser->state = S_CHAMP;
		}
		else
			parsing_error(parser, ERR_WRONG_PLAYER_NUM);
	}
	else
		parsing_error(parser, ERR_INVALID_CHAMP_NUM);
}
