#include "so_long.h"

void	init_game(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->tex_empty = NULL;
	game->tex_wall = NULL;
	game->tex_collectible = NULL;
	game->tex_exit = NULL;
	game->tex_width = 0;
	game->tex_height = 0;
	printf("# INIT_GAME DONE!\n");		// remove me 
}

void	init_map(t_game *game)
{
	game->map.x = 0;
	game->map.y = 0;
	game->map.data = NULL;
	printf("# INIT_MAP DONE!\n");		// remove me
}

void	init_mary(t_game *game)
{
	game->mary.x = 0;
	game->mary.y = 0;
	game->mary.xpm_left = NULL;
	game->mary.xpm_right = NULL;
	printf("# INIT_MARY DONE!\n");		// remove me
}
