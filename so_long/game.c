#include "so_long.h"

int	main(void)
{
	t_game		game;

	init_game(&game);
	init_mary(&game);
	init_map(&game);
	convert_ber(&game);
	convert_str(&game);
	if (check_rows(&game))
		exit_game(&game);
	start_mlx(&game);
	create_window(&game);
	load_game_textures(&game);
	load_mary(&game);
	display_mary(&game);
//	mlx_do_key_autorepeatoff(game.mlx);
	mlx_hook(game.win, 2, 1L<<0, movement, &game);
	mlx_hook(game.win, 17, 0L, exit_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
