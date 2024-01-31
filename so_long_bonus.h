/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joan <jocuni-p@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 22:05:32 by joan              #+#    #+#             */
/*   Updated: 2024/01/30 16:36:18 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "libft/libft.h"
# include "mlx/mlx.h"

/*--------------------Error messages-------------------*/

# define PRINT_ERR_1 "Error\nInvalid arg number.\n"
# define PRINT_ERR_2 "Error\nInvalid argument.\n"
# define PRINT_ERR_3 "Error\nInvalid arg_file extension.\n"
# define PRINT_ERR_4 "Error\nFailure to open arg-file.\n"
# define PRINT_ERR_5 "Error\nInvalid map.\n"
# define PRINT_ERR_5_1 "Error\nInvalid map. Lenght lines is different.\n"
# define PRINT_ERR_6 "Error\nMemory allocation failure.\n"
# define PRINT_ERR_7 "Error\nMap size too small.\n"
# define PRINT_ERR_8 "Error\nMaximum map wide accepted: 40 lines.\n"
# define PRINT_ERR_8_1 "Error\nMaximum map high accepted: 30 lines.\n"
# define PRINT_ERR_9 "Error\nInvalid walls in map.\n"
# define PRINT_ERR_10 "Error\nFound invalid or missing character.\n"
# define PRINT_ERR_11 "Error\nNo path to 'Collectible'.\n"
# define PRINT_ERR_12 "Error\nNo path to 'Exit'.\n"
# define PRINT_ERR_15 "Error\nMinilibX failure.\n"
# define PRINT_ERR_16 "Error\nmlx_loop failure.\n"
# define PRINT_ERR_17 "Error\nThe map has to include two 'Enemy' characters.\n"

/*-------------Codekeys on Apple platforms------------*/

# define X_EVENT_KEY_PRESS      2
# define X_EVENT_CLOSE_WINDOW   17
# define KEY_ESC                53
# define KEY_UP                 126
# define KEY_DOWN               125
# define KEY_LEFT               123
# define KEY_RIGHT              124

/*----------Function's name reduction-----------*/

# define MLX_PITW   mlx_put_image_to_window
# define MLX_XFTI   mlx_xpm_file_to_image

typedef struct s_so_long
{
	char	*arg_file;
	int		w;
	int		h;
	char	**map;
	int		p_cnt;
	int		x;
	int		y;
	int		ecnt;
	int		etmp;
	int		ex;
	int		ey;
	int		w_cnt;
	int		w_x;
	int		w_y;
	int		w2_x;
	int		w2_y;
	int		c_cnt;
	int		c_tmp1;
	int		c_tmp2;
	void	*mlx;
	void	*win;
	void	*to;
	void	*t1;
	void	*tc;
	void	*te;
	void	*te2;
	void	*tw;
	void	*tw2;
	void	*tp;
	int		px;
	int		mov_cnt;
	int		mov_tmp;
	int		aux_x;
	int		aux_y;
	int		flag;
}			t_so_long;

void	map_loader(t_so_long *sl);
void	map_validator(t_so_long *sl);
void	map_paths(t_so_long *sl, int y, int x);
void	handle_error(char *str, int size, t_so_long *sl);
void	free_array_2d(t_so_long *sl);
void	window_filler(t_so_long *sl);
int		press_key(int keycode, t_so_long *sl);
int		tw_animator(t_so_long *sl);
void	open_exitdoor(t_so_long *sl);
void	print_mov(t_so_long *sl);
int		game_finisher(t_so_long *sl);

#endif
