/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 11:09:51 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/01/30 16:56:30 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/*-------------MAP WALLS VALIDATION--------------*/
static void	map_borderline(t_so_long *sl)
{
	int	x;
	int	y;

	x = sl->w - 1;
	y = sl->h - 1;
	while (x >= 0)
	{
		if (sl->map[0][x] != '1' || sl->map[y][x] != '1')
			handle_error(PRINT_ERR_9, 28, sl);
		x--;
	}
	x = sl->w - 1;
	while (y >= 0)
	{
		if (sl->map[y][0] != '1' || sl->map[y][x] != '1')
			handle_error(PRINT_ERR_9, 28, sl);
		y--;
	}
}

/*-------------MAP CHARS VALIDATION--------------*/
static void	map_chars3(t_so_long *sl)
{
	if (sl->w_cnt == 0)
	{
		sl->w_x = sl->aux_x;
		sl->w_y = sl->aux_y;
	}
	else
	{
		sl->w2_x = sl->aux_x;
		sl->w2_y = sl->aux_y;
	}
	sl->w_cnt++;
}

static void	map_chars2(t_so_long *sl)
{
	if (sl->map[sl->aux_y][sl->aux_x] == 'P')
	{
		sl->p_cnt++;
		sl->x = sl->aux_x;
		sl->y = sl->aux_y;
	}
	else if (sl->map[sl->aux_y][sl->aux_x] == 'W')
		map_chars3(sl);
	else if (sl->map[sl->aux_y][sl->aux_x] == 'E')
	{
		sl->ecnt++;
		sl->ex = sl->aux_x;
		sl->ey = sl->aux_y;
	}
	else if (sl->map[sl->aux_y][sl->aux_x] == 'C')
		sl->c_cnt++;
	else if (sl->map[sl->aux_y][sl->aux_x] != '1' \
			&& sl->map[sl->aux_y][sl->aux_x] != '0')
		handle_error(PRINT_ERR_10, 42, sl);
}

static void	map_chars(t_so_long *sl)
{
	while (sl->aux_y < sl->h)
	{
		sl->aux_x = 0;
		while (sl->aux_x < sl->w - 1)
		{
			map_chars2(sl);
			sl->aux_x++;
		}
		sl->aux_y++;
	}
	if (sl->p_cnt != 1 || sl->ecnt != 1 || sl->c_cnt < 1)
		handle_error(PRINT_ERR_10, 42, sl);
	sl->aux_x = 0;
	sl->aux_y = 0;
}

/*-----------------MAIN VALIDATOR-----------------*/
void	map_validator(t_so_long *sl)
{
	map_borderline(sl);
	map_chars(sl);
	map_paths(sl, sl->y, sl->x);
	if (sl->c_cnt != sl->c_tmp1)
		handle_error(PRINT_ERR_11, 32, sl);
	if (sl->ecnt != sl->etmp)
		handle_error(PRINT_ERR_12, 25, sl);
	if (sl->w_cnt != 2)
		handle_error(PRINT_ERR_17, 53, sl);
}
