/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:36:15 by eslamber          #+#    #+#             */
/*   Updated: 2023/02/20 15:33:32 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAP_H
# define SWAP_H
# include "libft/libft.h"

typedef struct	s_swap{
	t_list	*pa;
	t_list	*pb;
}	t_swap;

// Main of parsing part
void	parsing(t_swap *data, char *av);

#endif
