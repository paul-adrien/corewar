/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_champ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 12:02:25 by brichard          #+#    #+#             */
/*   Updated: 2020/01/22 15:20:05 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	read_magic(t_parser *parser, int32_t fd)
{
	unsigned char		buff[sizeof(COREWAR_EXEC_MAGIC)];
	int32_t				ret;
	int32_t				nb;

	nb = 0;
	ret = read(fd, buff, sizeof(COREWAR_EXEC_MAGIC));
	if (ret > 0 && ret == (int32_t)sizeof(COREWAR_EXEC_MAGIC))
		nb = (buff[0] << 24 | buff[1] << 16 | buff[2] << 8 | buff[3]);
	if (COREWAR_EXEC_MAGIC != nb)
		parsing_error(parser, ERR_MAGIC);
}

void	read_name(t_parser *parser, int32_t fd)
{
	int32_t		ret;
	uint8_t		i;

	if (parser->chp_num == 0)
		attribute_next_chp_num(parser);
	i = parser->cur_chp_index;
	if (i < 4)
	{
		ret = read(fd, parser->env.champ[i].name, PROG_NAME_LENGTH);
		if (ret <= 0 || ret != PROG_NAME_LENGTH)
			parsing_error(parser, ERR_NAME_TOO_SHORT);
		else
		{
			parser->env.champ[i].num = parser->chp_num;
			parser->chp_num = 0;
		}
	}
}

void	read_size(t_parser *parser, int32_t fd)
{
	unsigned char	buff[sizeof(int32_t)];
	int32_t			ret;
	int32_t			size;

	if (padding_is_good(fd, 4) == FALSE)
		parsing_error(parser, ERR_PAD_BEFORE_SIZE);
	ret = read(fd, buff, sizeof(int32_t));
	if (ret <= 0)
		parsing_error(parser, ERR_MISSING_SIZE);
	else if (ret != sizeof(int32_t))
		parsing_error(parser, ERR_SIZE_FORMAT);
	size = (buff[0] << 24 | buff[1] << 16 | buff[2] << 8 | buff[3]);
	if (size < 0)
		parsing_error(parser, ERR_SIZE_NEG);
	parser->env.champ[parser->cur_chp_index].size = size;
}

void	read_comment(t_parser *parser, int32_t fd)
{
	int32_t		ret;
	uint8_t		i;

	i = parser->cur_chp_index;
	ret = read(fd, parser->env.champ[i].comment, COMMENT_LENGTH);
	parser->env.champ[i].comment[ret] = '\0';
	if (padding_is_good(fd, 4) == FALSE)
		parsing_error(parser, ERR_PAD_AFTER_COM);
	if (ret <= 0 || ret != COMMENT_LENGTH)
		parsing_error(parser, ERR_COMMENT_TOO_SHORT);
}

void	read_code(t_parser *parser, int32_t fd)
{
	int32_t			ret;
	char			buf;
	uint8_t			i;

	i = parser->cur_chp_index;
	ret = read(fd, parser->env.champ[i].code, parser->env.champ[i].size);
	if (ret <= 0)
		parsing_error(parser, ERR_MISSING_CODE);
	else if (ret > CHAMP_MAX_SIZE)
		parsing_error(parser, ERR_CODE_TOO_LONG);
	else if (ret != (int32_t)parser->env.champ[i].size || read(fd, &buf, 1) > 0)
		parsing_error(parser, ERR_BINARY_CORRUPTED);
	++parser->cur_chp_index;
}
