#include "so_long.h"

void	create_window(t_game *game)
{
	game->win = mlx_new_window(game->mlx, WIDTH, game->map.rows * 32, ".frnki");
	ft_printf("# NEW WINDOW SUCCESSFULLY CREATED\n");
}
