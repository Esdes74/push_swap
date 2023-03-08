/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_math.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:05:01 by eslamber          #+#    #+#             */
/*   Updated: 2023/03/05 10:11:35 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_MATH_H
# define LIB_MATH_H
# include <stdlib.h>

// Return the power of n, or -1 if to long
void	ft_power(void);

// Return the higher between x and y
int		max(int x, int y);

// Return the smaller between x and y
int		min(int x, int y);
#endif
