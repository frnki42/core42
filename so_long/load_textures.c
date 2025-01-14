/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efembock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 18:19:38 by efembock          #+#    #+#             */
/*   Updated: 2025/01/07 18:19:41 by efembock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

// loads game textures .xpm files
void	load_game_textures(t_game *game)
{
	game->tex_empty = mlx_xpm_file_to_image(game->mlx,
			"textures/empty.xpm",
			&game->tex_width, &game->tex_height);
	if (!game->tex_empty)
		exit_game(game, 1);
	game->tex_wall = mlx_xpm_file_to_image(game->mlx,
			"textures/wall.xpm",
			&game->tex_width, &game->tex_height);
	if (!game->tex_wall)
		exit_game(game, 1);
	game->tex_collectible = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible.xpm",
			&game->tex_width, &game->tex_height);
	if (!game->tex_collectible)
		exit_game(game, 1);
	game->tex_exit = mlx_xpm_file_to_image(game->mlx,
			"textures/exit_unlocked.xpm",
			&game->tex_width, &game->tex_height);
	if (!game->tex_exit)
		exit_game(game, 1);
}

// loads player .xpm files
void	load_player(t_game *game)
{
	game->player.xpm_left = mlx_xpm_file_to_image(game->mlx,
			"textures/42man_left.xpm",
			&game->tex_width, &game->tex_height);
	if (!game->player.xpm_left)
		exit_game(game, 1);
	game->player.xpm_right = mlx_xpm_file_to_image(game->mlx,
			"textures/42man_right.xpm",
			&game->tex_width, &game->tex_height);
	if (!game->player.xpm_right)
		exit_game(game, 1);
	game->player.xpm_up = mlx_xpm_file_to_image(game->mlx,
			"textures/42man_up.xpm",
			&game->tex_width, &game->tex_height);
	if (!game->player.xpm_up)
		exit_game(game, 1);
	game->player.xpm_down = mlx_xpm_file_to_image(game->mlx,
			"textures/42man_down.xpm",
			&game->tex_width, &game->tex_height);
	if (!game->player.xpm_down)
		exit_game(game, 1);
}
