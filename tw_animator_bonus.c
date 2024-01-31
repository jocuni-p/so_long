/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tw_animator_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:46:45 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/01/30 16:36:45 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	tw_animator(t_so_long *sl)
{
	int	r;

	r = 1;
	if (sl->flag == 0)
	{
		r = MLX_PITW(sl->mlx, sl->win, sl->tw2, sl->w_x * 32, sl->w_y * 32);
		r = MLX_PITW(sl->mlx, sl->win, sl->tw2, sl->w2_x * 32, sl->w2_y * 32);
		sl->flag = 1;
	}
	else
	{
		r = MLX_PITW(sl->mlx, sl->win, sl->tw, sl->w_x * 32, sl->w_y * 32);
		r = MLX_PITW(sl->mlx, sl->win, sl->tw, sl->w2_x * 32, sl->w2_y * 32);
		sl->flag = 0;
	}
	if (r == 0)
		handle_error(PRINT_ERR_15, 24, sl);
	return (0);
}
