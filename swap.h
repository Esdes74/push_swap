/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:36:15 by eslamber          #+#    #+#             */
/*   Updated: 2023/02/17 18:14:32 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAP_H
# define SWAP_H
# define ER 2
# define MSG "Error\n"
# define P_ERROR ft_printf_fd(ER, MSG)
# include "libft/libft.h"

typedef struct	s_swap{
	t_list	*pa;
	t_list	*pb;
}	t_swap;

// Main of parsing part
void	parsing(t_swap *data, char *av);

#endif
