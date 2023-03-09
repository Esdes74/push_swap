/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_or_rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:53:17 by eslamber          #+#    #+#             */
/*   Updated: 2023/03/09 09:21:18 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

static void	following_r_or_rr(t_swap *data, int m)
{
	while (data->pb->len > 0 && value(data->pa->head, INT) != data->r)
	{
		if (value(data->pa->head, INT) < value(data->pa->tail, INT) && m < \
				data->targ)
			break ;
		if (value(data->pa->head, INT) < data->targ && \
				value(data->pa->head->next, INT) > data->targ)
		{
			rotate(data, SA);
			break ;
		}
		reverse_or_rotate(data, SA, data->r);
	}
}

static void	db_r_or_rr(t_swap *data, int *n, int *m)
{
	t_cell	*tmp;

	*m = 0;
	*n = 0;
	tmp = data->pa->head;
	while (value(tmp, INT) != data->r)
	{
		*n = *n + 1;
		tmp = tmp->next;
	}
	tmp = data->pb->head;
	while (value(tmp, INT) != data->targ)
	{
		*m = *m + 1;
		tmp = tmp->next;
	}
}

static t_cell	*search_max(t_swap *data, int *res, int mod)
{
	t_cell	*tmp;
	t_cell	*pt;

	if (mod == SA)
		pt = data->pa->head;
	else if (mod == SB)
		pt = data->pb->head;
	tmp = pt;
	*res = value(pt, INT);
	while (tmp != 0)
	{
		if (value(tmp, INT) > *res)
			*res = value(tmp, INT);
		tmp = tmp->next;
	}
	return (pt);
}

void	r_or_rr(t_swap *data)
{
	int		m;
	int		n;
	int		len;

	while (data->pb->len > 0 && value(data->pb->head, INT) != data->targ && \
			value(data->pa->head, INT) != data->r)
	{
		db_r_or_rr(data, &n, &m);
		len = min(data->pa->len, data->pb->len);
		if (n > len && m > len)
			reverse(data, DB);
		else if (n < len && m < len)
			rotate(data, DB);
		else
			break ;
	}
	while (data->pb->len > 0 && value(data->pb->head, INT) != data->targ)
		reverse_or_rotate(data, SB, data->targ);
	search_max(data, &m, SA);
	following_r_or_rr(data, m);
	push(data, SA);
}
