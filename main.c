/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:36:04 by eslamber          #+#    #+#             */
/*   Updated: 2023/02/17 12:51:10 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

int	main(int ac, char **av)
{
	t_swap	*data;
	int		i;

	data = (t_swap *) malloc(sizeof(t_swap));
	if (data == 0)
		return (1);
	i = 1;
	while (i < ac)
		parsing(data, av[i++]);
	return (0);
}
