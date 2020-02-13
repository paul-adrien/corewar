/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding_is_good.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 13:52:00 by brichard          #+#    #+#             */
/*   Updated: 2019/12/04 14:01:44 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

uint8_t	padding_is_good(int32_t fd, int32_t sizeofpad)
{
	char	buf;

	while (sizeofpad > 0 && read(fd, &buf, 1) > 0)
	{
		if (buf != 0)
			break ;
		--sizeofpad;
	}
	return (sizeofpad == 0 ? TRUE : FALSE);
}
