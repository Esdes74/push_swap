/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:36:15 by eslamber          #+#    #+#             */
/*   Updated: 2023/03/09 09:28:37 by eslamber         ###   ########.fr       */
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
	int		*tab;
	int		targ;
	int		comp;
	int		r;
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

// Main of sort part
int		sort(t_swap *data);

// Search first and second minimum in list
t_cell	*search_min(t_swap *data, int *f_min, int *s_min, int mod);

// Sort two first values of lst given (by mod)
void	sort_two(t_swap *data, int mod);

// Sort three first values of lst given
void	sort_three(t_swap *data, int mod);

// Choice between r and rr
void	r_or_rr(t_swap *data);

// Main of second part of sort algorithm
void	real_sort(t_swap *data);

// Search best move between rotate or reverse to go to m
void	reverse_or_rotate(t_swap *data, int mod, int m);

// Return 1 if value is in tab, 0 if not
int		in(int *tab, int value, size_t size);

#endif
