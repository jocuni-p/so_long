#include "so_long.h"

void	print_data(t_so_long *sl)
{
/*<<<<<<<<<<<OJO MI ft_printf FALLA (en casa) CON ALGUNOS PARAMETROS %i o es por la mlx???>>>>>>>>>>>>>>*/

	ft_printf("file_name: %s\n", sl->arg_file);
	ft_printf("mapa len h x w  = %i x %i \n", sl->h, sl->w);
	ft_printf("Total 'P' = %i / [%i][%i] y x\n", sl->p_cnt, sl->y, sl->x);
	ft_printf("Total 'E' = %i / [%i][%i] e_y e_x\n", sl->e_cnt, sl->e_y, sl->e_x);
	ft_printf("Total 'C' = %i / %i accesibles\n", sl->c_cnt, sl->c_tmp1);
}
