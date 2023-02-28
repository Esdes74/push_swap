/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:41:02 by eslamber          #+#    #+#             */
/*   Updated: 2023/02/28 20:08:08 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

static void	reverse_or_rotate(t_swap *data, int mod)
{
	int		f;
	int		r;
	int		rr;
	t_cell	*tmp;

	tmp = search_min(data, &f, &r, mod);
	rr = 0;
	r = 0;
	while ((r++) < -1 || value(tmp, INT) != f)
		tmp = tmp->next;
	tmp = data->pa->tail;
	while ((rr++) < -1 || value(tmp, INT) != f)
		tmp = tmp->prev;
	if (r <= rr)
		rotate(data, SA);
	else
		reverse(data, SA);
}

static void	pre_sort(t_swap *data)
{
	int		f_min;
	int		s_min;
	t_cell	*tmp;

	while (data->pa->len > 3)
	{
		tmp = search_min(data, &f_min, &s_min, SA);
		if (value(tmp, INT) <= f_min + 5 && value(tmp, INT) >= f_min - 5)
			push(data, SB);
		else
			reverse_or_rotate(data, SA);
	}
	sort_three(data, SA);
	while (data->pb->len > 0)
		push(data, SA);
}

void	sort(t_swap *data)
{
	if (data->pa->len == 2)
		return (sort_two(data, SA));
	else if (data->pa->len == 3)
		return (sort_three(data, SA));
	pre_sort(data);
}
