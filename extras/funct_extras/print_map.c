#include "so_long.h"

void	print_map(t_so_long *sl)
{
	int	i = 0;

	while (sl->map[i] != NULL)
	{
		ft_putstr_fd(sl->map[i], 1);
		i++;
	}
	write(1, "\n\n", 2);
}
