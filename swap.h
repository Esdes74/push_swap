/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:36:15 by eslamber          #+#    #+#             */
/*   Updated: 2023/03/02 20:05:08 by eslamber         ###   ########.fr       */
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

// Sort two first values of lst given (by mod)
void	sort_two(t_swap *data, int mod);

// Sort three first values of lst given
void	sort_three(t_swap *data, int mod);

// Search the 2 minimal values of list given
t_cell	*search_min(t_swap *data, int *f_min, int *s_min, int mod);

// Searche the maximal value if list given
t_cell	*search_max(t_swap *data, int *res, int mod);

// Build a list of size highest integer, return 1 if not ok
int		*tab_min(t_swap *data, int *t, int size);

// Return 1 if value is in tab, 0 if not
int		in(int *tab, int value, size_t size);

#endif
