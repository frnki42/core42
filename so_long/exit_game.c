#include "so_long.h"

int	exit_game(t_game *game)
{
	size_t	i;

	i = 0;
	if (game->tex_empty)
		mlx_destroy_image(game->mlx, game->tex_empty);
	if (game->tex_wall)
		mlx_destroy_image(game->mlx, game->tex_wall);
	if (game->tex_collectible)
		mlx_destroy_image(game->mlx, game->tex_collectible);
	if (game->tex_exit)
		mlx_destroy_image(game->mlx, game->tex_exit);
	if (game->mary.xpm_left)
		mlx_destroy_image(game->mlx, game->mary.xpm_left);
	if (game->mary.xpm_right)
		mlx_destroy_image(game->mlx, game->mary.xpm_right);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		free(game->mlx);
	if (game->map.string)
		free(game->map.string);
	while (i < game->map.rows)
		free(game->map.array[i++]);
	if (game->map.array)
		free(game->map.array);
	exit (0);
	return (0);
}
