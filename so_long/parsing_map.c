/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efembock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 18:20:05 by efembock          #+#    #+#             */
/*   Updated: 2025/01/07 19:13:48 by efembock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

// converts .ber file into string
void	convert_ber(t_game *game, char *path)
{
	int		map;

	game->map.string = ft_strdup("");
	if (!game->map.string)
		exit_game(game, 1);
	map = open(path, O_RDONLY);
	if (map == -1)
	{
		ft_printf("Error\n# FAILED TO OPEN MAP!\n");
		exit_game(game, 1);
	}
	generate_map_string(game, map);
	close(map);
}

// converts 1d map into 2d map
void	convert_str(t_game *game)
{
	game->map.array = ft_split(game->map.string, '\n');
	if (!game->map.array)
		exit_game(game, 1);
	game->map.array_cpy = ft_split(game->map.string, '\n');
	if (!game->map.array_cpy)
		exit_game(game, 1);
}

// detects amount of collectibles
void	count_collectibles(t_game *game)
{
	int	i;

	i = -1;
	while (game->map.string[++i])
	{
		if (game->map.string[i] == 'C')
			game->map.collectibles++;
	}
}

// puts textures according to the map
void	show_map(t_game *game, int x, int y)
{
	if (game->map.array[y][x] == 'P')
	{
		game->player.x = x;
		game->player.y = y;
		mlx_put_image_to_window(game->mlx, game->win,
			game->player.xpm_right, x * 32, y * 32);
		game->map.array[y][x] = '0';
	}
	else if (game->map.array[y][x] == '0')
		mlx_put_image_to_window(game->mlx, game->win,
			game->tex_empty, x * 32, y * 32);
	else if (game->map.array[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->tex_wall, x * 32, y * 32);
	else if (game->map.array[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->tex_collectible, x * 32, y * 32);
	else if (game->map.array[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->tex_exit, x * 32, y * 32);
}

// show_map wrapper function
void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (game->map.array[++y])
	{
		x = -1;
		while (game->map.array[y][++x])
			show_map(game, x, y);
	}
}
