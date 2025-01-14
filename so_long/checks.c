/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efembock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 18:18:38 by efembock          #+#    #+#             */
/*   Updated: 2025/01/07 18:23:18 by efembock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

// checks if argv is valid (*.ber file)
void	check_argv(t_game *game, char *argv)
{
	int	len;

	if (!argv)
		exit_game(game, 1);
	len = 0;
	len = ft_strlen(argv);
	if (len < 5)
		exit_game(game, 1);
	if (argv[--len] != 'r')
		exit_game(game, 1);
	if (argv[--len] != 'e')
		exit_game(game, 1);
	if (argv[--len] != 'b')
		exit_game(game, 1);
	if (argv[--len] != '.')
		exit_game(game, 1);
}

// performs all map checks
void	check_valid(t_game *game)
{
	int	res;

	res = 0;
	res += check_rectangle(game);
	res += check_collectible(game);
	res += check_exit(game);
	res += check_player(game);
	res += check_surrounded(game);
	res += check_composition(game);
	if (res)
		exit_game(game, 1);
}

// checks if next move would hit a wall
int	check_wall(t_game *game, int keycode)
{
	int	dest;

	dest = 0;
	if (keycode == 'a' || keycode == 'd')
	{
		if (keycode == 'a')
			dest = game->player.x - 1;
		else if (keycode == 'd')
			dest = game->player.x + 1;
		if (game->map.array[game->player.y][dest] == '1')
			return (0);
	}
	else if (keycode == 's' || keycode == 'w')
	{
		if (keycode == 's')
			dest = game->player.y + 1;
		else if (keycode == 'w')
			dest = game->player.y - 1;
		if (game->map.array[dest][game->player.x] == '1')
			return (0);
	}
	return (1);
}

// checks if the map is surrounded by walls
int	check_surrounded(t_game *game)
{
	size_t	i;

	i = 0;
	while (i < game->map.rows)
	{
		if (game->map.array[i][0] != '1' ||
			game->map.array[i][game->map.columns - 1] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (game->map.array[0][i])
	{
		if (game->map.array[0][i] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (game->map.array[game->map.rows - 1][i])
	{
		if (game->map.array[game->map.rows - 1][i] != '1')
			return (1);
		i++;
	}
	return (0);
}

// exits game if all collectibles are found + swaps C when player stands on it
void	manipulate_map(t_game *game)
{
	if (game->map.array[game->player.y][game->player.x] == 'C')
	{
		game->player.collectible++;
		game->map.array[game->player.y][game->player.x] = '0';
	}
	if (game->map.array[game->player.y][game->player.x] == 'E' &&
			(game->player.collectible == game->map.collectibles))
	{
		win_screen(game->player.moves);
		exit_game(game, 0);
	}
}
