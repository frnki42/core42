#include "so_long.h"

int	exit_game(t_game *game)
{
	if (game->tex[0])
		mlx_destroy_image(game->mlx, game->tex[0]);
	if (game->tex[1])
		mlx_destroy_image(game->mlx, game->tex[1]);
	if (game->tex[2])
		mlx_destroy_image(game->mlx, game->tex[2]);
	if (game->tex[3])
		mlx_destroy_image(game->mlx, game->tex[3]);
	if (game->tex[4])
		mlx_destroy_image(game->mlx, game->tex[4]);
	if (game->mary.sprite[0])
		mlx_destroy_image(game->mlx, game->mary.sprite[0]);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	exit (0);
	return (0);
}
