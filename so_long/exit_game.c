#include "so_long.h"

int	exit_game(t_game *game)
{
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
	exit (0);
	return (0);
}
