/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_exitdoor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:23:39 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/01/20 11:57:23 by joan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*-----IF ALL 'c' ARE COLLECTED DISPLAYS AN OPEN EXIT------*/

void	open_exitdoor(t_so_long *sl)
{
	if (sl->c_tmp2 == sl->c_cnt)
		MLX_PITW(sl->mlx, sl->win, sl->te2, sl->ex * 32, sl->ey * 32);
	return ;
}
