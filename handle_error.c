/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:34:50 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/01/17 11:45:17 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*------FREE MEMORY AND CLOSE PROGRAM PROPERLY-----*/

void	handle_error(char *str, int size, t_so_long *sl)
{
	write(2, str, size);
	if (sl->map != NULL)
		free_array_2d(sl);
	exit (EXIT_FAILURE);
}