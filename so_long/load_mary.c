#include "so_long.h"

void	load_mary(t_game *game)
{
	game->mary.sprite[0] = mlx_xpm_file_to_image(game->mlx, "textures/mary_right.xpm", &game->tex_width, &game->tex_height);
	if (!game->mary.sprite[0])
		exit_game(game);
	game->mary.x = WIDTH / 4;					// change to x of P later
	game->mary.y = HEIGHT / 4;					// change to y of P later
}
