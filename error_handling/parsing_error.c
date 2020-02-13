/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 11:46:53 by brichard          #+#    #+#             */
/*   Updated: 2020/01/30 15:40:48 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	parsing_error(t_parser *parser, int32_t error_code)
{
	static char	*err_str[ERR_MSG_NUM] = {ERR_MSG0, ERR_MSG1, ERR_MSG2, ERR_MSG3,
									ERR_MSG4, ERR_MSG5, ERR_MSG6, ERR_MSG7,
									ERR_MSG8, ERR_MSG9, ERR_MSG10, ERR_MSG11,
									ERR_MSG12, ERR_MSG13, ERR_MSG14, ERR_MSG15,
									ERR_MSG16, ERR_MSG17, ERR_MSG18, ERR_MSG19,
									ERR_MSG20, ERR_MSG21};
	static char *champ_pos[4] = {"first", "second", "third", "fourth"};

	ft_printf(err_str[error_code], error_code >= 7 && error_code <= 18 ?
			champ_pos[parser->cur_chp_index] : "");
	parser->state = S_ERR;
}
