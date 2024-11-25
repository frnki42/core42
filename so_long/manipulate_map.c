#include "so_long.h"

void	manipulate_map(t_game *game)
{
	if (game->map.array[game->mary.y / 32][game->mary.x / 32] == 'C')
	{
		game->mary.collectible++;
		game->map.array[game->mary.y / 32][game->mary.x / 32] = '0';
		ft_printf("# COLLECTIBLE AQUIRED\n");
	}
//	if (game->map.array[game->mary.y][game->mary.x] == '0')
//	if (game->map.array[game->mary.y][game->mary.x] == '1')
//	if (game->map.array[game->mary.y][game->mary.x] == 'E')
//		mlx_put_image_to_window(game->mlx, game->win, game->tex_exit, x * 32, y * 32);
}
