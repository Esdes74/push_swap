/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:41:02 by eslamber          #+#    #+#             */
/*   Updated: 2023/10/17 13:20:51 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

static int	in(int *tab, int value, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
		if (tab[i++] == value)
			return (1);
	return (0);
}

static int	*tab_min(t_swap *data, int *t, int size)
{
	int		i;
	t_cell	*tmp;

	t = (int *) malloc(sizeof(int) * size);
	if (t == 0)
		return (0);
	i = 0;
	while (i < size)
	{
		tmp = data->pa->head;
		t[i] = value(tmp, INT);
		while (tmp != 0)
		{
			if (t[i] < value(tmp, INT) && in(t, value(tmp, INT), i) == 0)
				t[i] = value(tmp, INT);
			tmp = tmp->next;
		}
		i++;
	}
	return (t);
}

static int	pre_sort(t_swap *data)
{
	int		s;
	t_cell	*tmp;

	while (data->pa->len > 3)
	{
		tmp = data->pa->head;
		if (data->pa->len > 10)
			s = data->pa->len / 5;
		else
			s = 10;
		data->tab = tab_min(data, data->tab, s);
		if (data->tab == 0)
			return (1);
		if (in(data->tab, value(tmp, INT), s) == 1)
			push(data, SB);
		else
			reverse_or_rotate(data, SA, value(tmp, INT));
		free(data->tab);
	}
	sort_three(data, SA);
	return (0);
}

int	sort(t_swap *data)
{
	if (data->pa->len == 2)
		return (sort_two(data, SA), 0);
	else if (data->pa->len == 3)
		return (sort_three(data, SA), 0);
	if (pre_sort(data) == 1)
		return (1);
	real_sort(data);
	return (0);
}
