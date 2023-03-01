/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:41:02 by eslamber          #+#    #+#             */
/*   Updated: 2023/03/01 15:51:50 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

static void	reverse_or_rotate(t_swap *data, int mod, int m)
{
	int		f;
	int		r;
	int		rr;
	t_cell	*tmp;

	if (m == -5)
		tmp = search_min(data, &f, &r, mod);
	if (m == -6)
		tmp = search_max(data, &f, mod);
	rr = 0;
	r = 0;
	while ((r++) < -1 || value(tmp, INT) != f)
		tmp = tmp->next;
	if (mod == SA)
		tmp = data->pa->tail;
	else
		tmp = data->pb->tail;
	while ((rr++) < -1 || value(tmp, INT) != f)
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
			reverse_or_rotate(data, SB, -6);
	}
}

static void	pre_sort(t_swap *data)
{
	int		f_min;
	int		s;
	t_cell	*tmp;

	while (data->pa->len > 0)
	{
		tmp = search_min(data, &f_min, &s, SA);
		if (data->pa->len > 300)
			s = 40;
		else if (data->pa->len > 150)
			s = 30;
		else if (data->pa->len > 75)
			s = 20;
		else
			s = 10;
		if (value(tmp, INT) <= f_min + s && value(tmp, INT) >= f_min - s)
			push(data, SB);
		else
			reverse_or_rotate(data, SA, -5);
	}
}

void	sort(t_swap *data)
{
	if (data->pa->len == 2)
		return (sort_two(data, SA));
	else if (data->pa->len == 3)
		return (sort_three(data, SA));
	pre_sort(data);
	real_sort(data);
}
