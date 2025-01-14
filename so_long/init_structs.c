/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efembock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 18:19:24 by efembock          #+#    #+#             */
/*   Updated: 2025/01/07 18:19:26 by efembock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
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
}

// initializes player 
void	init_player(t_game *game)
{
	game->player.collectible = 0;
	game->player.moves = 0;
	game->player.x = 0;
	game->player.y = 0;
	game->player.xpm_left = NULL;
	game->player.xpm_right = NULL;
}

// initializes stuff
void	initialize_game(t_game *game)
{
	init_game(game);
	init_player(game);
	init_map(game);
}
