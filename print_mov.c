/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mov.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joan <jocuni-p@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 22:59:43 by joan              #+#    #+#             */
/*   Updated: 2024/01/16 16:48:21 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_mov(t_so_long *sl)
{
	if (sl->mov_cnt != sl->mov_tmp)
	{
		sl->mov_cnt++;
		ft_printf("Total movements: %i\n", sl->mov_tmp);
	}
}
