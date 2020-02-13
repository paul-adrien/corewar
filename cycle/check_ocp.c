/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ocp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 22:12:00 by tlandema          #+#    #+#             */
/*   Updated: 2020/01/12 22:12:31 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** L12 : car t_reg = 1 et t_dir = 2 mais t_ind = 4 et non 3
*/

static int	param_ok(int ocp_chunk, int op_code, int num_param)
{
	if (ocp_chunk < 1 || ocp_chunk > 3)
		return (0);
	if (ocp_chunk == 3)
		ocp_chunk += 1;
	if (ocp_chunk & g_op_tab[op_code - 1].type_param[num_param])
		return (1);
	return (0);
}

/*
**  L30 : on regarde le premier param && on envoie a param_ok le deux
**	bits que l'on veut regarder cad les deux dernier 1100 0000*
**	L32 : pareil mais deuxieme param et 0011 0000
**	L34 : pareil mais troisieme param et 0000 1100
*/

int			check_ocp(int ocp, int op_code)
{
	int	nb_param;

	nb_param = g_op_tab[op_code - 1].nb_param;
	if (nb_param >= 1 && !param_ok((ocp & 0xC0) >> 6, op_code, 0))
		return (0);
	if (nb_param >= 2 && !param_ok((ocp & 0x30) >> 4, op_code, 1))
		return (0);
	if (nb_param >= 3 && !param_ok((ocp & 0xC) >> 2, op_code, 2))
		return (0);
	return (1);
}
