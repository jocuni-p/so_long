/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:10:52 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/01/30 16:56:43 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/*------------------MAP_FILE EXTENSION VALIDATOR-------------*/

static void	extension_check(t_so_long *sl)
{
	char	*ext;

	if (sl->arg_file == NULL)
		handle_error(PRINT_ERR_2, 24, sl);
	ext = ft_strrchr(sl->arg_file, '.');
	if (ext == NULL)
		handle_error(PRINT_ERR_3, 34, sl);
	if (ft_strlen(ext) != 4 || ft_strncmp(ext, ".ber", 4) != 0)
		handle_error(PRINT_ERR_3, 34, sl);
}

/*---------MAP LINES&ROWS COUNTER AND VALIDATOR---------*/

static void	map_size_check(t_so_long *sl)
{
	int		fd;
	int		len;
	char	*line;

	len = 0;
	line = NULL;
	fd = open(sl->arg_file, O_RDONLY);
	if (fd == -1)
		handle_error(PRINT_ERR_4, 32, sl);
	line = get_next_line(fd);
	while (line != NULL)
	{
		len = ft_strlen(line);
		if (line[len - 1] == '\n')
			len -= 1;
		if (sl->h == 0)
			sl->w = len;
		if (len != sl->w)
			handle_error(PRINT_ERR_5_1, 47, sl);
		my_free(&line);
		sl->h++;
		line = get_next_line(fd);
	}
	close(fd);
}

/*-------------LLIMITS MAP SIZE-----------------*/

static void	map_max_size(t_so_long *sl)
{
	if (sl->h > 30)
		handle_error(PRINT_ERR_8_1, 43, sl);
	if (sl->w > 40)
		handle_error(PRINT_ERR_8, 43, sl);
}

/*------------BI-DIMENSIONAL ARRAY FILLER------------*/

void	map_loader(t_so_long *sl)
{
	int	fd;
	int	i;

	i = 0;
	extension_check(sl);
	map_size_check(sl);
	map_max_size(sl);
	sl->map = (char **)malloc(sizeof(char *) * sl->h + 1);
	if (!sl->map)
		handle_error(PRINT_ERR_6, 33, sl);
	fd = open(sl->arg_file, O_RDONLY);
	if (fd == -1)
		handle_error(PRINT_ERR_4, 32, sl);
	sl->map[i] = get_next_line(fd);
	while (sl->map[i++] != NULL)
		sl->map[i] = get_next_line(fd);
	close(fd);
}
