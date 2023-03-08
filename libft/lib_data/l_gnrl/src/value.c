/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:51:35 by eslamber          #+#    #+#             */
/*   Updated: 2023/02/28 16:31:51 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib_data.h"

int	value(t_cell *cell, t_type t)
{
	if (t == CHAR)
		return (*((char *) cell->data_cell->data));
	return (*((int *) cell->data_cell->data));
}
