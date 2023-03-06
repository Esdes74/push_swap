/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 08:52:45 by eslamber          #+#    #+#             */
/*   Updated: 2023/03/06 14:03:58 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

static void	search_better_r(t_swap *data, int cb, int ca)
{
	t_cell	*tmpa;
	t_cell	*tmpb;

	tmpb = data->pb->head;
	cb = 0;
	while (tmpb != 0)
	{
		tmpa = data->pa->head;
		ca = 1;
		while (tmpa != data->pa->tail)
		{
			if (value(tmpb, INT) > value(tmpa, INT) && max(ca, cb) < \
					data->comp && (value(tmpa, INT) > value(tmpa->next, INT) \
					|| value(tmpb, INT) < value(tmpa->next, INT)))
			{
				data->r = value(tmpa->next, INT);
				data->comp = max(ca, cb);
				data->targ = value(tmpb, INT);
			}
			ca++;
			tmpa = tmpa->next;
		}
		cb++;
		tmpb = tmpb->next;
	}
}

static void	search_better_r_tail(t_swap *data, int cb, int ca)
{
	t_cell	*tmpa;
	t_cell	*tmpb;

	tmpb = data->pb->tail;
	cb = 0;
	while (tmpb != 0)
	{
		tmpa = data->pa->head;
		ca = 1;
		while (tmpa != data->pa->tail)
		{
			if (value(tmpb, INT) > value(tmpa, INT) && ca + cb < \
					data->comp && (value(tmpa, INT) > value(tmpa->next, INT) \
					|| value(tmpb, INT) < value(tmpa->next, INT)))
			{
				data->r = value(tmpa->next, INT);
				data->comp = ca + cb;
				data->targ = value(tmpb, INT);
			}
			ca++;
			tmpa = tmpa->next;
		}
		cb++;
		tmpb = tmpb->prev;
	}
}

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

static void	r_or_rr(t_swap *data)
{
	int		m;
	int		n;
	int		len;
	t_cell	*tmp;

	while (data->pb->len > 0 && value(data->pb->head, INT) != data->targ && \
			value(data->pa->head, INT) != data->r)
	{
		m = 0;
		n = 0;
		tmp = data->pa->head;
		while (value(tmp, INT) != data->r)
		{
			n++;
			tmp = tmp->next;
		}
		tmp = data->pb->head;
		while (value(tmp, INT) != data->targ)
		{
			m++;
			tmp = tmp->next;
		}
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

static void	push_head(t_swap *data)
{
	while (data->pb->len > 0 && value(data->pb->head, INT) < \
		value(data->pa->head, INT) && value(data->pb->head, INT) > \
		value(data->pa->tail, INT))
		push(data, SA);
}

void	real_sort(t_swap *data)
{
	int	f;
	int	s;

	while (data->pb->len > 0)
	{
		push_head(data);
		data->comp = max(data->pb->len, data->pa->len);
		data->r = 0;
		if (data->pb->len > 0)
			data->targ = value(data->pb->head, INT);
		search_better_r(data, f, s);
		search_better_r_tail(data, f, s);
		search_min(data, &f, &s, SA);
		if (data->r == 0 && f > data->targ)
		{
			while (value(data->pa->head, INT) > value(data->pa->tail, INT))
				reverse_or_rotate(data, SA, f);
			push(data, SA);
		}
		else
			r_or_rr(data);
	}
	search_min(data, &f, &s, SA);
	while (value(data->pa->head, INT) != f)
		reverse_or_rotate(data, SA, f);
}
