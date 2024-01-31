/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_array_2d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 10:57:29 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/01/16 11:12:38 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_array_2d(t_so_long *sl)
{
	int	i;

	i = 0;
	if (sl->map != NULL)
	{
		while (sl->map[i] != NULL && i < sl->h)
		{
			free(sl->map[i]);
			sl->map[i] = NULL;
			i++;
		}
		free(sl->map);
		sl->map = NULL;
	}
}
