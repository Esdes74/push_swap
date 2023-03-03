/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:46:38 by eslamber          #+#    #+#             */
/*   Updated: 2023/03/03 16:20:12 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

int	in(int *tab, int value, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
		if (tab[i++] == value)
			return (1);
	return (0);
}
