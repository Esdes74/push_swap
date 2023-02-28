/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_little.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:44:35 by eslamber          #+#    #+#             */
/*   Updated: 2023/02/28 20:15:24 by eslamber         ###   ########.fr       */
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
	if (*((int *) pt->data_cell->data) > *((int *) pt->next->data_cell->data))
		swap(data, mod);
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
