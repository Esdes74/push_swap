/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:36:10 by eslamber          #+#    #+#             */
/*   Updated: 2023/03/09 08:32:36 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

static int	annalyse(char *elem)
{
	size_t	i;
	size_t	len;
	char	*int_max;
	char	*int_min;

	len = ft_strlen(elem);
	int_max = "2147483647";
	int_min = "-2147483648";
	if (len > ft_strlen(int_min))
		return (1);
	if (len == ft_strlen(int_min) && ft_strncmp(int_min, elem, len) < 0)
		return (1);
	if (len == ft_strlen(int_max) && ft_strncmp(int_max, elem, len) < 0)
		return (1);
	i = 0;
	if (elem[0] == '-' || elem[0] == '+')
		i++;
	while (ft_isdigit(elem[i]))
		i++;
	if (i == len)
		return (0);
	return (1);
}

static int	add(t_swap *data, char *elem)
{
	int	*new;

	if (annalyse(elem) != 0)
		return (1);
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
