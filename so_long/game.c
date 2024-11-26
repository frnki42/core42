#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game		game;

	if (argc != 2)
		return (write(1, "NAHBRO", 7));
	init_game(&game);
	init_mary(&game);
	init_map(&game);
	convert_ber(&game, argv[1]);
	convert_str(&game);
	count_collectibles(&game);
	if (check_rectangle(&game))
		exit_game(&game);
	if (check_collectible(&game))
		exit_game(&game);
	if (check_exit(&game))
		exit_game(&game);
	if (check_player(&game))
		exit_game(&game);
	start_mlx(&game);
	create_window(&game);
	load_game_textures(&game);
	load_mary(&game);
	render_map(&game);
	display_mary(&game);
//	mlx_do_key_autorepeatoff(game.mlx);
	mlx_hook(game.win, 2, 1L<<0, movement, &game);
	mlx_hook(game.win, 17, 0L, exit_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
