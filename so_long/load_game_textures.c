#include "so_long.h"

void	load_game_textures(t_game *game)
{
	game->tex[0] = mlx_xpm_file_to_image(game->mlx, "textures/grey_background.xpm", &game->tex_width, &game->tex_height);
	game->tex[1] = mlx_xpm_file_to_image(game->mlx, "textures/green_light.xpm", &game->tex_width, &game->tex_height);
	game->tex[2] = mlx_xpm_file_to_image(game->mlx, "textures/green_dark.xpm", &game->tex_width, &game->tex_height);
	game->tex[3] = mlx_xpm_file_to_image(game->mlx, "textures/aqua_light.xpm", &game->tex_width, &game->tex_height);
	if (!game->tex[0] || !game->tex[1] || !game->tex[2] || !game->tex[3])
		exit_game(game);
}
