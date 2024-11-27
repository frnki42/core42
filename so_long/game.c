#include "so_long.h"

int	main(int argc, char **argv)
{
	size_t	i;
	t_game		game;

	if (argc < 2)
		return (ft_printf("# Error\n# no map path was specified!\n"), 1);
	if (argc > 2)
		return (ft_printf("# Error\n# too many arguments!\n"), 1);
	init_game(&game);
	init_mary(&game);
	init_map(&game);
	convert_ber(&game, argv[1]);
	convert_str(&game);
	detect_start(&game);
	count_collectibles(&game);
	if (check_valid(&game))
		exit_game(&game);
	flood_fill(&game, game.map.start_y, game.map.start_x);
	i = 0;
	while (i < game.map.rows)
		ft_printf("%s\n", game.map.array_cpy[i++]);
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
