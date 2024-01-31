/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_finisher.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:16:56 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/01/16 11:19:02 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*------CLOSE THE WINDOW AND FINISHES THE GAME PROPERLY-------*/

int	game_finisher(t_so_long *sl)
{
	mlx_destroy_window(sl->mlx, sl->win);
	exit (0);
}
