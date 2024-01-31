/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:06:56 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/01/19 11:24:04 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*-------MOVEMENT TO THE RIGHT--------*/

static void	move_right(t_so_long *sl)
{
	if (sl->map[sl->y][sl->x + 1] == 'o')
	{
		MLX_PITW(sl->mlx, sl->win, sl->to, sl->x * 32, sl->y * 32);
		MLX_PITW(sl->mlx, sl->win, sl->tp, (sl->x + 1) * 32, sl->y * 32);
		sl->mov_tmp++;
		sl->x += 1;
	}
	else if (sl->map[sl->y][sl->x + 1] == 'c')
	{
		MLX_PITW(sl->mlx, sl->win, sl->to, sl->x * 32, sl->y * 32);
		MLX_PITW(sl->mlx, sl->win, sl->tp, (sl->x + 1) * 32, sl->y * 32);
		sl->map[sl->y][sl->x + 1] = 'o';
		sl->mov_tmp++;
		sl->c_tmp2++;
		open_exitdoor(sl);
		sl->x += 1;
	}
	else if (sl->map[sl->y][sl->x + 1] == 'e' && sl->c_cnt == sl->c_tmp2)
	{
		sl->mov_tmp++;
		print_mov(sl);
		game_finisher(sl);
	}
}

/*--------MOVEMENT TO THE LEFT--------*/

static void	move_left(t_so_long *sl)
{
	if (sl->map[sl->y][sl->x - 1] == 'o')
	{
		MLX_PITW(sl->mlx, sl->win, sl->to, sl->x * 32, sl->y * 32);
		MLX_PITW(sl->mlx, sl->win, sl->tp, (sl->x - 1) * 32, sl->y * 32);
		sl->mov_tmp++;
		sl->x -= 1;
	}
	else if (sl->map[sl->y][sl->x - 1] == 'c')
	{
		MLX_PITW(sl->mlx, sl->win, sl->to, sl->x * 32, sl->y * 32);
		MLX_PITW(sl->mlx, sl->win, sl->tp, (sl->x - 1) * 32, sl->y * 32);
		sl->map[sl->y][sl->x - 1] = 'o';
		sl->mov_tmp++;
		sl->c_tmp2++;
		sl->x -= 1;
		open_exitdoor(sl);
	}
	else if (sl->map[sl->y][sl->x - 1] == 'e' && sl->c_cnt == sl->c_tmp2)
	{
		sl->mov_tmp++;
		print_mov(sl);
		game_finisher(sl);
	}
}

/*-------MOVEMENT TO UP--------*/

static void	move_up(t_so_long *sl)
{
	if (sl->map[sl->y - 1][sl->x] == 'o')
	{
		MLX_PITW(sl->mlx, sl->win, sl->to, sl->x * 32, sl->y * 32);
		MLX_PITW(sl->mlx, sl->win, sl->tp, sl->x * 32, (sl->y - 1) * 32);
		sl->mov_tmp++;
		sl->y -= 1;
	}
	else if (sl->map[sl->y - 1][sl->x] == 'c')
	{
		MLX_PITW(sl->mlx, sl->win, sl->to, sl->x * 32, sl->y * 32);
		MLX_PITW(sl->mlx, sl->win, sl->tp, sl->x * 32, (sl->y - 1) * 32);
		sl->map[sl->y - 1][sl->x] = 'o';
		sl->mov_tmp++;
		sl->c_tmp2++;
		open_exitdoor(sl);
		sl->y -= 1;
	}
	else if (sl->map[sl->y - 1][sl->x] == 'e' && sl->c_cnt == sl->c_tmp2)
	{
		sl->mov_tmp++;
		print_mov(sl);
		game_finisher(sl);
	}
}
/*-------MOVEMENT TO DOWN--------*/

static void	move_down(t_so_long *sl)
{
	if (sl->map[sl->y + 1][sl->x] == 'o')
	{
		MLX_PITW(sl->mlx, sl->win, sl->to, sl->x * 32, sl->y * 32);
		MLX_PITW(sl->mlx, sl->win, sl->tp, sl->x * 32, (sl->y + 1) * 32);
		sl->mov_tmp++;
		sl->y += 1;
	}
	else if (sl->map[sl->y + 1][sl->x] == 'c')
	{
		MLX_PITW(sl->mlx, sl->win, sl->to, sl->x * 32, sl->y * 32);
		MLX_PITW(sl->mlx, sl->win, sl->tp, sl->x * 32, (sl->y + 1) * 32);
		sl->map[sl->y + 1][sl->x] = 'o';
		sl->mov_tmp++;
		sl->c_tmp2++;
		open_exitdoor(sl);
		sl->y += 1;
	}
	else if (sl->map[sl->y + 1][sl->x] == 'e' && sl->c_cnt == sl->c_tmp2)
	{
		sl->mov_tmp++;
		print_mov(sl);
		game_finisher(sl);
	}
}

/*-----------SELECTOR-----------*/

int	press_key(int keycode, t_so_long *sl)
{
	if (keycode == KEY_ESC)
		game_finisher(sl);
	else if (keycode == KEY_UP)
		move_up(sl);
	else if (keycode == KEY_LEFT)
		move_left(sl);
	else if (keycode == KEY_DOWN)
		move_down(sl);
	else if (keycode == KEY_RIGHT)
		move_right(sl);
	print_mov(sl);
	return (0);
}
