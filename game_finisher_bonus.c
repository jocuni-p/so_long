/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_finisher_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:16:56 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/01/30 16:31:37 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/*------CLOSE THE WINDOW AND FINISHES THE GAME PROPERLY-------*/

int	game_finisher(t_so_long *sl)
{
	mlx_destroy_window(sl->mlx, sl->win);
	exit (0);
}
