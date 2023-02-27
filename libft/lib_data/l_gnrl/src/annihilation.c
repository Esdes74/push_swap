/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annihilation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:44:56 by eslamber          #+#    #+#             */
/*   Updated: 2023/02/25 18:32:28 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib_data.h"

void	annihilation(t_list *lst, void (*f)(void *), int debug)
{
	t_cell	*tmp;

	if (lst == 0)
	{
		if (debug)
			ft_printf("ERROR : fct annihilation : List is null\n");
		return ;
	}
	if (!is_list(lst->type_lst))
	{
		if (debug)
			ft_printf("ERROR : fct annihilation : Utilisation of non type \
list\n");
		return ;
	}
	tmp = lst->head;
	while (tmp != 0)
	{
		tmp = tmp->next;
		if (f != 0)
			f(lst->head->data_cell->data);
		free(lst->head->data_cell);
		free(lst->head);
		lst->head = tmp;
	}
	free(lst);
}
