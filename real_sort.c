/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 08:52:45 by eslamber          #+#    #+#             */
/*   Updated: 2023/03/03 16:04:16 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

static void	search_better_r(t_swap *data)
{
	int		cb;
	int		ca;
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
					/* ft_printf("ca + cb = %d, %d, %d, %d\n", ca + cb, data->comp, value(tmpb, INT), value(tmpa, INT)); */
			if (value(tmpb, INT) > value(tmpa, INT) && ca + cb < data->comp)
			{
				/* ft_printf("AAAAAAAAAAAAAAAAAAAAA\n"); */
				/* ft_printf("tmpb = %d, tmpa->next = %d\n", value(tmpb, INT), value(tmpa->next, INT)); */
				if (value(tmpa, INT) > value(tmpa->next, INT) ||\
						value(tmpb, INT) < value(tmpa->next, INT))
				{
				/* ft_printf("BBBBBBBBBBBBBBBBBBBBB\n"); */
					data->r = -1;
					data->comp = ca + cb;
					data->targ = value(tmpb, INT);
				}
				/* else */
				/* 	return (1); */
			}
			ca++;
			tmpa = tmpa->next;
		}
		cb++;
		tmpb = tmpb->next;
	}
	/* return (0); */
}

/* static void	search_better_rr(t_swap *data) */
/* { */
/* 	int		cb; */
/* 	int		ca; */
/* 	t_cell	*tmpa; */
/* 	t_cell	*tmpb; */

/* 	tmpb = data->pb->tail; */
/* 	cb = 0; */
/* 	while (tmpb != 0) */
/* 	{ */
/* 		tmpa = data->pa->tail; */
/* 		ca = 1; */
/* 		while (tmpa != data->pa->head) */
/* 		{ */
/* 			if (value(tmpb, INT) < value(tmpa, INT) && ca + cb < data->comp) */
/* 				if (value(tmpa, INT) > value(tmpa->prev, INT) \ */
/* 						|| value(tmpb, INT) > value(tmpa->prev, INT)) */
/* 				{ */
/* 					/1* ft_printf("bbbbbbbbbbbbbbbbb\n"); *1/ */
/* 					data->r = 1; */
/* 					data->comp = ca + cb; */
/* 					data->targ = value(tmpb, INT); */
/* 				} */
/* 			ca++; */
/* 			tmpa = tmpa->prev; */
/* 		} */
/* 		cb++; */
/* 		tmpb = tmpb->prev; */
/* 	} */
/* 		/1* ft_printf("comp = %d, r = %d\n", data->comp, data->r); *1/ */
/* } */

/* static void	simple(t_swap *data) */
/* { */
/* 	int	i; */

/* 	i = 0; */
/* 	while (i == 0) */
/* 	{ */
/* 		if (value(data->pb->head, INT) < value(data->pa->head, INT)) */
/* 			push(data, SA); */
/* 		else if (value(data->pb->head, INT) > value(data->pa->tail, INT)) */
/* 		{ */
/* 			push(data, SA); */
/* 		} */
/* 		else */
/* 			i++; */
/* 	} */
/* } */

static void	r_or_rr(t_swap *data)
{
	int	m;

	/* ft_printf("%d\n", data->targ); */
	/* print_list(data->pa); */
	/* print_list(data->pb); */
	while (value(data->pb->head, INT) != data->targ)
	{
		if (data->targ < value(data->pa->head, INT) \
				&& data->targ > value(data->pa->tail, INT))
			break;
		if (data->r < 0)
			rotate(data, DB);
		else
			reverse(data, DB);
	}
	while (value(data->pb->head, INT) != data->targ)
		if (data->r < 0)
			rotate(data, SB);
		else
			reverse(data, SB);
	/* ft_printf("targ = %d, head = %d\n", data->targ, value(data->pa->head, INT)); */
	search_max(data, &m, SA);
	while (1 == 1)//value(data->pa->head, INT) < data->targ)
	{
		if (value(data->pa->head, INT) < value(data->pa->tail, INT) && m < data->targ)
			break;
		if (value(data->pa->head, INT) < data->targ && value(data->pa->head->next, INT) > data->targ)
		{
			rotate(data, SA);
			break;
		}
		else if (data->r < 0)
			rotate(data, SA);
		else
			reverse(data, SA);
	}
	push(data, SA);
}

void	real_sort(t_swap *data)
{
	int	f;
	int	s;

	/* int i = 0; */
	while (data->pb->len > 0)
	/* { */
	/* while (i < 20) */
	{
		/* simple(data); */
		data->comp = data->pb->len;
		data->r = 0;
		data->targ = value(data->pb->head, INT);
		search_better_r(data);
		/* if (search_better_r(data) == 1) */
		/* { */
		/* 	reverse(data, SA); */
		/* 	push(data, SA); */
		/* } */
		/* ft_printf("comp = %d, r = %d\n", data->comp, data->r); */
		/* search_better_rr(data); */
		search_min(data, &f, &s, SA);
		if (data->r == 0 && f > data->targ)
		{
			while (value(data->pa->head, INT) > value(data->pa->tail, INT))
				reverse_or_rotate(data, SA, f);
			push(data, SA);
		}
		else
			r_or_rr(data);
		/* } */
		/* i++; */
	}
	while (value(data->pa->head, INT) != f)
		reverse_or_rotate(data, SA, f);
}
