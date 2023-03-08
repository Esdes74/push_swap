/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_swap_and_push.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:58:36 by eslamber          #+#    #+#             */
/*   Updated: 2023/03/06 19:31:35 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

static int	s(t_list *lst)
{
	if (lst->len < 2)
		return (1);
	lst->head = lst->head->next;
	lst->head->prev->next = lst->head->next;
	lst->head->prev->prev = lst->head;
	if (lst->len > 2)
		lst->head->next->prev = lst->head->prev;
	lst->head->next = lst->head->prev;
	lst->head->prev = 0;
	return (0);
}

static void	ss(t_swap *data)
{
	if (data->pa->len < 2 || data->pb->len < 2)
		return ;
	ft_printf("ss\n");
	s(data->pa);
	s(data->pb);
}

void	swap(t_swap *data, int mod)
{
	if (mod == DB)
		ss(data);
	else if (mod == SA)
	{
		if (s(data->pa) == 0)
			ft_printf("sa\n");
	}
	else if (mod == SB)
		if (s(data->pb) == 0)
			ft_printf("sb\n");
}

static void	p(t_list *dest, t_list *src)
{
	t_cell	*tmp;

	tmp = unstack_list(src, DEBUG);
	tmp->next = dest->head;
	if (dest->len > 0)
		dest->head->prev = tmp;
	if (dest->len == 0)
		dest->tail = tmp;
	dest->head = tmp;
	dest->len++;
}

void	push(t_swap *data, int mod)
{
	if (mod == SA)
	{
		if (data->pb->len != 0)
		{
			ft_printf("pa\n");
			p(data->pa, data->pb);
		}
	}
	else if (mod == SB)
	{
		if (data->pa->len != 0)
		{
			ft_printf("pb\n");
			p(data->pb, data->pa);
		}
	}
}
