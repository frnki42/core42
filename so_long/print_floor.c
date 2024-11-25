#include "so_long.h"

int	print_floor(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y <= HEIGHT)
	{	
		x = 0;
		while (x <= WIDTH)
		{
			mlx_put_image_to_window(game->mlx, game->win, game->tex_wall, x, y);
			x += 32;	
		}
		y += 32;
	}
	printf("# PRINT_FLOOR DONE!");
	return (0);
}
