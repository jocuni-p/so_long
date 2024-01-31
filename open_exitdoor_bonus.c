/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_exitdoor_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:23:39 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/01/30 16:34:55 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/*-----IF ALL 'c' ARE COLLECTED DISPLAYS AN OPEN EXIT------*/

void	open_exitdoor(t_so_long *sl)
{
	if (sl->c_tmp2 == sl->c_cnt)
		MLX_PITW(sl->mlx, sl->win, sl->te2, sl->ex * 32, sl->ey * 32);
	return ;
}
