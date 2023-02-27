/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_rotate_and_reverse.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:58:54 by eslamber          #+#    #+#             */
/*   Updated: 2023/02/27 18:57:55 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

static void	r(t_list *lst)
{
	lst->tail->next = lst->head;
	lst->head->prev = lst->tail;
	lst->head = lst->head->next;
	lst->tail = lst->tail->next;
	lst->head->prev = 0;
	lst->tail->next = 0;
}

void	rotate(t_swap *data, int mod)
{
	if (mod == DB)
	{
		if (data->pa->len >= 2 && data->pb->len >= 2)
		{
			ft_printf("rr\n");
			r(data->pa);
			r(data->pb);
		}
	}
	else if (mod == SA)
	{
		if (data->pa->len >= 2)
		{
			ft_printf("ra\n");
			r(data->pa);
		}
	}
	else if (mod == SB)
	{
		if (data->pb->len >= 2)
		{
			ft_printf("rb\n");
			r(data->pb);
		}
	}
}

static void	rr(t_list *lst)
{
	lst->tail->next = lst->head;
	lst->head->prev = lst->tail;
	lst->head = lst->tail;
	lst->tail = lst->head->prev;
	lst->head->prev = 0;
	lst->tail->next = 0;
}

void	reverse(t_swap *data, int mod)
{
	if (mod == DB)
	{
		if (data->pa->len >= 2 && data->pb->len >= 2)
		{
			ft_printf("rrr\n");
			rr(data->pa);
			rr(data->pb);
		}
	}
	else if (mod == SA)
	{
		if (data->pa->len >= 2)
		{
			ft_printf("rra\n");
			rr(data->pa);
		}
	}
	else if (mod == SB)
	{
		if (data->pb->len >= 2)
		{
			ft_printf("rrb\n");
			rr(data->pb);
		}
	}
}
