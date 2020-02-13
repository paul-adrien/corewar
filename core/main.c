/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paullaurent <paullaurent@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:58:38 by plaurent          #+#    #+#             */
/*   Updated: 2020/01/30 15:48:16 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	visu_failed(t_parser *parser)
{
	delete_vm(&parser->env);
	return (EXIT_FAILURE);
}

static int	usage(void)
{
	ft_putendl("Usage: ./corewar --visual [-dump n_cycles] \
[(-n num) champ1.cor] ...");
	ft_putendl(USG_MSG2);
	ft_putendl(USG_MSG3);
	ft_putendl(USG_MSG4);
	ft_putendl(USG_MSG5);
	ft_putendl(USG_MSG6);
	ft_putendl(USG_MSG7);
	return (EXIT_FAILURE);
}

int			main(int ac, char **av)
{
	t_parser	parser;

	if (ac < 2)
		return (usage());
	ft_bzero((void *)&parser, sizeof(t_parser));
	ft_memset((void *)&parser.flag_n, '5', 4 * sizeof(uint8_t));
	if (vm_parser(&parser, ++av) == FAILURE)
	{
		delete_vm(&parser.env);
		return (usage());
	}
	if (load_memory(&parser) == SUCCESS)
	{
		player_caller(parser.env.champ_amount, parser.env.champ);
		if (parser.visu == ON)
		{
			if (main_visu(&parser.env) == FAILURE)
				return (visu_failed(&parser));
		}
		else
			cycle(&parser.env);
	}
	delete_vm(&parser.env);
	return (EXIT_SUCCESS);
}
