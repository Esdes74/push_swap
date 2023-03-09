/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:44:35 by eslamber          #+#    #+#             */
/*   Updated: 2023/03/09 09:38:41 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	sort_two(t_swap *data, int mod)
{
	t_cell	*pt;

	if (mod == SA)
		pt = data->pa->head;
	else if (mod == SB)
		pt = data->pb->head;
	else
		return ;
	if (value(pt, INT) > value(pt->next, INT))
		swap(data, mod);
}

void	sort_three(t_swap *data, int mod)
{
	int		f_min;
	int		s_min;
	t_cell	*pt;

	pt = search_min(data, &f_min, &s_min, mod);
	if (value(pt->next, INT) == s_min)
	{
		if (value(pt, INT) != f_min)
		{
			rotate(data, mod);
			swap(data, mod);
		}
	}
	else if (value(pt->next, INT) != f_min && value(pt->next, INT) != s_min)
	{
		reverse(data, mod);
		if (value(pt, INT) == f_min)
			swap(data, mod);
	}
	else
		if (value(pt, INT) == s_min)
			swap(data, mod);
	else
		rotate(data, mod);
}

t_cell	*search_min(t_swap *data, int *f_min, int *s_min, int mod)
{
	t_cell	*tmp;
	t_cell	*pt;

	if (mod == SA)
		pt = data->pa->head;
	else if (mod == SB)
		pt = data->pb->head;
	tmp = pt;
	*f_min = value(pt, INT);
	*s_min = *f_min;
	while (tmp != 0)
	{
		if (value(tmp, INT) < *f_min)
		{
			*s_min = *f_min;
			*f_min = value(tmp, INT);
		}
		else if (value(tmp, INT) < *s_min || tmp == pt->next)
			*s_min = value(tmp, INT);
		tmp = tmp->next;
	}
	return (pt);
}

void	reverse_or_rotate(t_swap *data, int mod, int m)
{
	int		r;
	int		rr;
	t_cell	*tmp;

	rr = 0;
	r = 0;
	if (mod == SA)
		tmp = data->pa->head;
	else if (mod == SB)
		tmp = data->pb->head;
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
