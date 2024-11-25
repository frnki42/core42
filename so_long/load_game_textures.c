#include "so_long.h"

void	load_game_textures(t_game *game)
{
	game->tex_empty = mlx_xpm_file_to_image(game->mlx, "textures/grey_background.xpm", &game->tex_width, &game->tex_height);
	if (!game->tex_empty)
		exit_game(game);
	game->tex_wall = mlx_xpm_file_to_image(game->mlx, "textures/collectible.xpm", &game->tex_width, &game->tex_height);
	if (!game->tex_wall)
		exit_game(game);
	game->tex_collectible = mlx_xpm_file_to_image(game->mlx, "textures/collectible.xpm", &game->tex_width, &game->tex_height);
	if (!game->tex_collectible)
		exit_game(game);
	game->tex_exit = mlx_xpm_file_to_image(game->mlx, "textures/aqua_light.xpm", &game->tex_width, &game->tex_height);
	if (!game->tex_exit)
		exit_game(game);
}

void	load_mary(t_game *game)
{
	game->mary.xpm_left = mlx_xpm_file_to_image(game->mlx, "textures/mary_left.xpm", &game->tex_width, &game->tex_height);
	if (!game->mary.xpm_left)
		exit_game(game);
	game->mary.xpm_right = mlx_xpm_file_to_image(game->mlx, "textures/mary_right.xpm", &game->tex_width, &game->tex_height);
	if (!game->mary.xpm_right)
		exit_game(game);
	game->mary.x = WIDTH / 4;					// change to x of P later
	game->mary.y = HEIGHT / 2;					// change to y of P later
}
