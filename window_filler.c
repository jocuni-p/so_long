/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_filler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:51:52 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/01/19 12:48:15 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*--------------LOADS AN XPM_MAP AND CREATES AN IMAGE-------------*/

static void	init_tiles(t_so_long *sl)
{
	sl->t1 = MLX_XFTI(sl->mlx, "./textures/t1.xpm", &sl->px, &sl->px);
	if (sl->t1 == NULL)
		handle_error(PRINT_ERR_15, 24, sl);
	sl->tc = MLX_XFTI(sl->mlx, "./textures/tc.xpm", &sl->px, &sl->px);
	if (sl->tc == NULL)
		handle_error(PRINT_ERR_15, 24, sl);
	sl->to = MLX_XFTI(sl->mlx, "./textures/to.xpm", &sl->px, &sl->px);
	if (sl->to == NULL)
		handle_error(PRINT_ERR_15, 24, sl);
	sl->te = MLX_XFTI(sl->mlx, "./textures/te.xpm", &sl->px, &sl->px);
	if (sl->te == NULL)
		handle_error(PRINT_ERR_15, 24, sl);
	sl->tp = MLX_XFTI(sl->mlx, "./textures/tp.xpm", &sl->px, &sl->px);
	if (sl->tp == NULL)
		handle_error(PRINT_ERR_15, 24, sl);
	sl->te2 = MLX_XFTI(sl->mlx, "./textures/te2.xpm", &sl->px, &sl->px);
	if (sl->te2 == NULL)
		handle_error(PRINT_ERR_15, 24, sl);
}

static void	window_filler2(t_so_long *sl)
{
	int	r;

	r = 1;
	if (sl->map[sl->aux_y][sl->aux_x] == '1')
		r = MLX_PITW(sl->mlx, sl->win, sl->t1, sl->aux_x * 32, sl->aux_y * 32);
	else if (sl->map[sl->aux_y][sl->aux_x] == 'c')
		r = MLX_PITW(sl->mlx, sl->win, sl->tc, sl->aux_x * 32, sl->aux_y * 32);
	else if (sl->map[sl->aux_y][sl->aux_x] == 'o' || \
			sl->map[sl->aux_y][sl->aux_x] == '0')
		r = MLX_PITW(sl->mlx, sl->win, sl->to, sl->aux_x * 32, sl->aux_y * 32);
	else if (sl->map[sl->aux_y][sl->aux_x] == 'e')
		r = MLX_PITW(sl->mlx, sl->win, sl->te, sl->aux_x * 32, sl->aux_y * 32);
	else if (sl->map[sl->aux_y][sl->aux_x] == 'p')
	{
		sl->map[sl->aux_y][sl->aux_x] = 'o';
		r = MLX_PITW(sl->mlx, sl->win, sl->tp, sl->aux_x * 32, sl->aux_y * 32);
	}
	if (r == 0)
		handle_error(PRINT_ERR_15, 24, sl);
}

void	window_filler(t_so_long *sl)
{
	init_tiles(sl);
	while (sl->aux_y < sl->h)
	{
		sl->aux_x = 0;
		while (sl->aux_x < sl->w)
		{
			window_filler2(sl);
			sl->aux_x++;
		}
		sl->aux_y++;
	}
}
