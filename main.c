/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:36:04 by eslamber          #+#    #+#             */
/*   Updated: 2023/03/08 17:56:55 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

static int	init_swap(t_swap *data)
{
	data->pa = (t_list *) malloc(sizeof(t_list));
	if (data->pa == 0)
		return (1);
	data->pa = init_list(data->pa);
	data->pb = (t_list *) malloc(sizeof(t_list));
	if (data->pb == 0)
		return (annihilation(data->pa, NULL, DEBUG), 1);
	data->pb = init_list(data->pb);
	data->tab = 0;
	data->targ = 0;
	return (0);
}

static void	destroy_data(t_swap *data)
{
	annihilation(data->pa, free, DEBUG);
	annihilation(data->pb, free, DEBUG);
}

static int	sorted(t_swap data)
{
	t_cell	*tmp;

	tmp = data.pa->head;
	while (tmp != data.pa->tail && value(tmp, INT) < value(tmp->next, INT))
		tmp = tmp->next;
	if (tmp == data.pa->tail)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_swap	data;
	int		i;

	if (init_swap(&data) == 1)
		return (ft_printf_fd(ER, MSG), 1);
	i = 1;
	while (i < ac)
		if (parsing(&data, av[i++]) != 0)
			return (ft_printf_fd(ER, MSG), destroy_data(&data), 1);
	if (sorted(data) == 0)
		return (destroy_data(&data), 0);
	if (sort(&data) == 1)
		return (ft_printf_fd(ER, MSG), destroy_data(&data), 1);
	return (destroy_data(&data), 0);
}
