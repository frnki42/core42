/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efembock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 18:19:13 by efembock          #+#    #+#             */
/*   Updated: 2025/01/07 19:12:34 by efembock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static void	prepare_game(t_game *game, char *path)
{
	check_argv(game, path);
	convert_ber(game, path);
	check_new_lines(game);
	convert_str(game);
	detect_start(game);
	count_collectibles(game);
	check_valid(game);
	flood_fill(game, game->map.start_y, game->map.start_x);
	if (check_path(game))
		exit_game(game, 1);
}

static void	create_window(t_game *game)
{
	game->win = mlx_new_window(game->mlx,
			game->map.columns * 32, game->map.rows * 32,
			"./so_long");
	if (!game->win)
		exit_game(game, 1);
}

static void	start_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_game(game, 1);
}

static void	start_game(t_game *game)
{
	start_mlx(game);
	create_window(game);
	load_game_textures(game);
	load_player(game);
	render_map(game);
}

int	main(int argc, char **argv)
{
	t_game		game;

	if (argc < 2)
		return (ft_printf("Error\n# NO MAP PATH WAS SPECIFIED!\n"), 1);
	if (argc > 2)
		return (ft_printf("Error\n# TOO MANY ARGUMENTS!\n"), 1);
	initialize_game(&game);
	prepare_game(&game, argv[1]);
	start_game(&game);
	mlx_hook(game.win, 2, 1L << 0, movement, &game);
	mlx_hook(game.win, 17, 0L, exit_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
