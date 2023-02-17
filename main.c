/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:36:04 by eslamber          #+#    #+#             */
/*   Updated: 2023/02/17 18:15:25 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

static t_swap	*init_swap(void)
{
	t_swap	*data;

	data = (t_swap *) malloc(sizeof(t_swap));
	if (data == 0)
		return (NULL);
	data->pa = (t_list *) malloc(sizeof(t_list));
	data->pa = init_list(data->pa);
	if (data->pa == 0)
		return (free(data), NULL);
	data->pb = (t_list *) malloc(sizeof(t_list));
	data->pb = init_list(data->pb);
	if (data->pb == 0)
		return (annihilation(data->pb, none, DEBUG), free(data), NULL);
	return (data);
}

static void	destroy_data(t_swap *data)
{
	annihilation(data->pa, free, DEBUG);
	annihilation(data->pb, free, DEBUG);
	free(data);
}

int	main(int ac, char **av)
{
	t_swap	*data;
	int		i;

	data = init_swap();
	if (data == 0)
		return (P_ERROR, 1);
	i = 1;
	while (i < ac)
		parsing(data, av[i++]);
	return (destroy_data(data), 0);
}
