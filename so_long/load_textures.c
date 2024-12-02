#include "so_long.h"

// loads game textures .xpm files
void	load_game_textures(t_game *game)
{
	game->tex_empty = mlx_xpm_file_to_image(game->mlx,
			"textures/empty.xpm",
			&game->tex_width, &game->tex_height);
	if (!game->tex_empty)
		exit_game(game, 1);
	game->tex_wall = mlx_xpm_file_to_image(game->mlx,
			"textures/wall.xpm",
			&game->tex_width, &game->tex_height);
	if (!game->tex_wall)
		exit_game(game, 1);
	game->tex_collectible = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible.xpm",
			&game->tex_width, &game->tex_height);
	if (!game->tex_collectible)
		exit_game(game, 1);
	game->tex_exit = mlx_xpm_file_to_image(game->mlx,
			"textures/exit_unlocked.xpm",
			&game->tex_width, &game->tex_height);
	if (!game->tex_exit)
		exit_game(game, 1);
}

// loads mary .xpm files
void	load_mary(t_game *game)
{
	game->mary.xpm_left = mlx_xpm_file_to_image(game->mlx,
			"textures/mary_left.xpm",
			&game->tex_width, &game->tex_height);
	if (!game->mary.xpm_left)
		exit_game(game, 1);
	game->mary.xpm_right = mlx_xpm_file_to_image(game->mlx,
			"textures/mary_right.xpm",
			&game->tex_width, &game->tex_height);
	if (!game->mary.xpm_right)
		exit_game(game, 1);
}
