/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joan <jocuni-p@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 22:01:04 by joan              #+#    #+#             */
/*   Updated: 2024/01/30 16:29:50 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	init_sl_1(t_so_long *sl, char *str)
{
	sl->arg_file = str;
	sl->w = 0;
	sl->h = 0;
	sl->map = NULL;
	sl->p_cnt = 0;
	sl->x = 0;
	sl->y = 0;
	sl->ecnt = 0;
	sl->etmp = 0;
	sl->ex = 0;
	sl->ey = 0;
	sl->w_cnt = 0;
	sl->w_x = 0;
	sl->w_y = 0;
	sl->w2_x = 0;
	sl->w2_y = 0;
	sl->c_cnt = 0;
	sl->c_tmp1 = 0;
	sl->c_tmp2 = 0;
}

static void	init_sl_2(t_so_long *sl)
{
	sl->mlx = NULL;
	sl->win = NULL;
	sl->to = NULL;
	sl->t1 = NULL;
	sl->tc = NULL;
	sl->te = NULL;
	sl->te2 = NULL;
	sl->tw = NULL;
	sl->tw2 = NULL;
	sl->tp = NULL;
	sl->px = 32;
	sl->mov_cnt = 0;
	sl->mov_tmp = 0;
	sl->aux_x = 0;
	sl->aux_y = 0;
	sl->flag = 0;
}

int	main(int ac, char **av)
{
	t_so_long	sl;

	if (ac != 2)
	{
		write(1, PRINT_ERR_1, 26);
		return (0);
	}
	init_sl_1(&sl, av[1]);
	init_sl_2(&sl);
	map_loader(&sl);
	map_validator(&sl);
	sl.mlx = mlx_init();
	if (sl.mlx == NULL)
		handle_error(PRINT_ERR_15, 24, &sl);
	sl.win = mlx_new_window(sl.mlx, sl.w * 32, sl.h * 32, "so_long_bonus");
	if (sl.win == NULL)
		handle_error(PRINT_ERR_15, 24, &sl);
	window_filler(&sl);
	mlx_hook(sl.win, X_EVENT_KEY_PRESS, 0, &press_key, &sl);
	mlx_hook(sl.win, X_EVENT_CLOSE_WINDOW, 0, &game_finisher, &sl);
	if (mlx_loop(sl.mlx) == -1)
		handle_error(PRINT_ERR_16, 24, &sl);
	free_array_2d(&sl);
	return (0);
}
