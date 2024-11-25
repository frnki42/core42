#include "so_long.h"

void	render_map(t_game *game)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (game->map.array[y])
	{
		x = 0;
		while (game->map.array[y][x])
		{
			if (game->map.array[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->tex_empty, x * 32, y * 32);
			if (game->map.array[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->tex_wall, x * 32, y * 32);
			if (game->map.array[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->tex_collectible, x * 32, y * 32);
			if (game->map.array[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->tex_exit, x * 32, y * 32);
			x++;
		}
		y++;
	}
}
