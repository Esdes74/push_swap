/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:41:02 by eslamber          #+#    #+#             */
/*   Updated: 2023/03/02 20:29:28 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

static void	reverse_or_rotate(t_swap *data, int mod, int m)
{
	int		r;
	int		rr;
	t_cell	*tmp;

	rr = 0;
	r = 0;
	while ((r++) < -1 || value(tmp, INT) != m)
		tmp = tmp->next;
	if (mod == SA)
		tmp = data->pa->tail;
	else
		tmp = data->pb->tail;
	while ((rr++) < -1 || value(tmp, INT) != m)
		tmp = tmp->prev;
	if (r <= rr)
		rotate(data, mod);
	else
		reverse(data, mod);
}

static void	real_sort(t_swap *data)
{
	int		f;
	t_cell	*tmp;

	while (data->pb->len > 0)
	{
		tmp = search_max(data, &f, SB);
		if (value(tmp, INT) == f)
			push(data, SA);
		else
			reverse_or_rotate(data, SB, f);
	}
}

static int	pre_sort(t_swap *data)
{
	int		s;
	t_cell	*tmp;

	while (data->pa->len > 0)
	{
		tmp = data->pa->head;
		if (data->pa->len > 300)
			s = 40;
		else if (data->pa->len > 100)
			s = 30;
		else if (data->pa->len > 75)
			s = 20;
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
