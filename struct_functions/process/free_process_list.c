/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_process_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 14:54:14 by brichard          #+#    #+#             */
/*   Updated: 2020/01/20 11:53:29 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	free_process_list(t_process **to_free)
{
	t_process	*tmp;

	if (to_free == NULL)
		return ;
	while (*to_free != NULL)
	{
		tmp = (*to_free)->next;
		free_process(to_free);
		*to_free = tmp;
	}
}
