/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mov_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joan <jocuni-p@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 22:59:43 by joan              #+#    #+#             */
/*   Updated: 2024/01/31 11:54:36 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	print_mov(t_so_long *sl)
{
	char	*s;

	s = ft_itoa(sl->mov_tmp);
	if (sl->mov_cnt != sl->mov_tmp)
	{
		sl->mov_cnt++;
		MLX_PITW(sl->mlx, sl->win, sl->t1, 0, 0);
		mlx_string_put(sl->mlx, sl->win, 5, 8, 0xFFFFFF, s);
	}
	free(s);
}
