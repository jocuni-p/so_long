/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_paths_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:43:17 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/01/30 16:33:44 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/*-----------MAP PATHS VALIDATION------------*/

void	map_paths(t_so_long *sl, int y, int x)
{
	if (sl->map[y][x] != '1' && sl->map[y][x] != 'o' && sl->map[y][x] != 'c' \
		&& sl->map[y][x] != 'e' && sl->map[y][x] != 'p' && sl->map[y][x] != 'w')
	{
		if (sl->map[y][x] == 'P')
			sl->map[y][x] = 'p';
		else if (sl->map[y][x] == 'W')
			sl->map[y][x] = 'w';
		else if (sl->map[y][x] == 'E')
		{
			sl->etmp++;
			sl->map[y][x] = 'e';
			return ;
		}
		else if (sl->map[y][x] == 'C')
		{
			sl->c_tmp1++;
			sl->map[y][x] = 'c';
		}
		else
			sl->map[y][x] = 'o';
		map_paths(sl, y, x + 1);
		map_paths(sl, y + 1, x);
		map_paths(sl, y, x - 1);
		map_paths(sl, y - 1, x);
	}
}
