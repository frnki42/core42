#include "so_long.h"

// initializes game
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
	ft_printf("# INIT_GAME DONE\n");
}

// initializes map
void	init_map(t_game *game)
{
	game->map.collectibles = 0;
	game->map.columns = 0;
	game->map.rows = 0;
	game->map.start_x = 0;
	game->map.start_y = 0;
	game->map.string = NULL;
	game->map.array = NULL;
	game->map.array_cpy = NULL;
	ft_printf("# INIT_MAP DONE\n");
}

// initializes mary 
void	init_mary(t_game *game)
{
	game->mary.collectible = 0;
	game->mary.moves = 0;
	game->mary.x = 0;
	game->mary.y = 0;
	game->mary.xpm_left = NULL;
	game->mary.xpm_right = NULL;
	ft_printf("# INIT_MARY DONE\n");
}

// initializes stuff
void	init_stuff(t_game *game)
{
	init_game(game);
	init_mary(game);
	init_map(game);
}
