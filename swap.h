/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:36:15 by eslamber          #+#    #+#             */
/*   Updated: 2023/02/27 18:48:49 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAP_H
# define SWAP_H
# include "libft/libft.h"

# define SA -1
# define SB -2
# define DB -3

typedef struct s_swap{
	t_list	*pa;
	t_list	*pb;
}	t_swap;

// Main of parsing part
int		parsing(t_swap *data, char *av);

// Execute rule swap
void	swap(t_swap *data, int mod);

// Execute rule push
void	push(t_swap *data, int mod);

// Execute rule rotate
void	rotate(t_swap *data, int mod);

// Execute rule reverse
void	reverse(t_swap *data, int mod);

#endif
