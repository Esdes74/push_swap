/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:36:04 by eslamber          #+#    #+#             */
/*   Updated: 2023/03/03 12:13:03 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

static int	init_swap(t_swap *data)
{
	/* t_swap	*data; */

	/* data = (t_swap *) malloc(sizeof(t_swap)); */
	/* if (data == 0) */
	/* 	return (NULL); */
	data->pa = (t_list *) malloc(sizeof(t_list));
	data->pa = init_list(data->pa);
	if (data->pa == 0)
		return (free(data), 1);
	data->pb = (t_list *) malloc(sizeof(t_list));
	data->pb = init_list(data->pb);
	if (data->pb == 0)
		return (annihilation(data->pa, NULL, DEBUG), free(data), 1);
	data->tab = 0;
	data->targ = 0;
	return (0);
}

static void	destroy_data(t_swap *data)
{
	annihilation(data->pa, free, DEBUG);
	annihilation(data->pb, free, DEBUG);
}

int	main(int ac, char **av)
{
	/* t_swap	*data; */
	t_swap	data;
	int		i;

	if (ac == 1)
		return (ft_printf_fd(ER, MSG), 1);
	/* data = init_swap(); */
	if (init_swap(&data) == 1)
		return (ft_printf_fd(ER, MSG), 1);
	/* if (data == 0) */
	/* 	return (ft_printf_fd(ER, MSG), 1); */
	i = 1;
	while (i < ac)
		if (parsing(&data, av[i++]) != 0)
			return (ft_printf_fd(ER, MSG), destroy_data(&data), 1);
	if (sort(&data) == 1)
		return (ft_printf_fd(ER, MSG), destroy_data(&data), 1);
	return (destroy_data(&data), 0);
}
