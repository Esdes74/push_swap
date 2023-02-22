/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:36:10 by eslamber          #+#    #+#             */
/*   Updated: 2023/02/22 20:30:14 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

static int	add(t_swap *data, char *elem)
{
	int	*new;

	new = (int *) malloc(sizeof(int));
	if (new == 0)
		return (1);
	*new = ft_atoi(elem);
	if (where(data->pa, INT, new, sizeof(int)) != 0)
		return (free(new), 1);
	if (tailing_list(data->pa, new, INT, DEBUG) == 0)
		return (free(new), 1);
	return (0);
}

static void	destroy_split(char **splitted)
{
	int	i;

	i = 0;
	while (splitted[i] != 0)
		free(splitted[i++]);
	free(splitted);
}

int	parsing(t_swap *data, char *av)
{
	char	**splitted;
	int		i;

	i = 0;
	splitted = ft_split(av, ' ');
	if (splitted == 0)
		return (1);
	while (splitted[i] != 0)
		if (add(data, splitted[i++]) != 0)
			return (destroy_split(splitted), 1);
	return (destroy_split(splitted), 0);
}
