#include "so_long.h"

int	main(void)
{
	t_game		game;

	game.mlx = mlx_init();
	if (!game.mlx)
		return (1);
	game.win = mlx_new_window(game.mlx, WIDTH, HEIGHT, ".frnki");
	load_game_textures(&game);
	load_mary(&game);
	mlx_do_key_autorepeaton(game.mlx);			// change to off later!
	mlx_hook(game.win, 2, 1L<<0, movements, &game);
	mlx_hook(game.win, 17, 0L, exit_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
