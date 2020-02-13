/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_verb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 10:57:38 by tlandema          #+#    #+#             */
/*   Updated: 2020/01/30 11:52:57 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	get_verb(t_parser *parser, char **av)
{
	if (ft_strcheck(*av, ft_isdigit) == TRUE)
	{
		parser->env.verbose = ft_atol(*av);
		if (parser->env.verbose >= 0 && parser->env.verbose <= 64)
			parser->state = S_OPTION;
		else
			parsing_error(parser, ERR_INVALID_VERB_NUM);
	}
	else
		parsing_error(parser, ERR_INVALID_VERB_NUM);
}
