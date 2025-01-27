/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efembock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 18:19:24 by efembock          #+#    #+#             */
/*   Updated: 2025/01/21 12:44:01 by efembock         ###   ########.fr       */
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
	game->player.xpm_up = NULL;
	game->player.xpm_down = NULL;
}

// initializes stuff
void	initialize_game(t_game *game)
{
	init_game(game);
	init_player(game);
	init_map(game);
}

void	generate_map_string(t_game *game, int map)
{
	char	*output;
	char	*temp;

	output = get_next_line(map);
	if (!output)
	{
		close(map);
		exit_game(game, 1);
	}
	while (output)
	{
		game->map.rows++;
		temp = game->map.string;
		game->map.string = ft_strjoin(game->map.string, output);
		if (!game->map.string)
		{
			free(temp);
			close(map);
			exit_game(game, 1);
		}
		free(temp);
		free(output);
		output = get_next_line(map);
	}
	free(output);
}
