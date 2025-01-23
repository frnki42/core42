/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efembock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 18:20:19 by efembock          #+#    #+#             */
/*   Updated: 2025/01/23 14:55:06 by efembock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

// replace all reachable '0' 'C' 'P' 'E' with 'X' in game->map.array_cpy
void	flood_fill(t_game *game, size_t y, size_t x)
{
	if (x < 1 || x >= game->map.columns - 1
		|| y < 1 || y >= game->map.rows - 1)
		return ;
	if (game->map.array_cpy[y][x] == '0' ||
		game->map.array_cpy[y][x] == 'C' ||
		game->map.array_cpy[y][x] == 'P' ||
		game->map.array_cpy[y][x] == 'E')
	{
		game->map.array_cpy[y][x] = 'X';
		flood_fill(game, y + 1, x);
		flood_fill(game, y - 1, x);
		flood_fill(game, y, x + 1);
		flood_fill(game, y, x - 1);
	}
}

// check if {P, E, C} got reached by flood_fill in game->map.array_cpy
int	check_path(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (game->map.array_cpy[++y])
	{
		x = -1;
		while (game->map.array_cpy[y][++x])
		{
			if (!(game->map.array_cpy[y][x] == '1'
				|| game->map.array_cpy[y][x] == 'X'
				|| game->map.array_cpy[y][x] == '0'))
			{
				ft_printf("Error\n# NO VALID PATH DETECTED\n");
				return (1);
			}
		}
	}
	return (0);
}

// checks if the map contains empty lines
void	check_empty_lines(t_game *game)
{
	char	*ptr;

	ptr = game->map.string;
	if (*ptr == '\n')
	{
		ft_printf("Error\n# EMPTY LINE IN MAP DETECTED!\n");
		exit_game(game, 1);
	}
	while (*ptr)
	{
		if (*ptr++ == '\n' && *ptr == '\n')
		{
			ft_printf("Error\n# EMPTY LINE IN MAP DETECTED!\n");
			exit_game(game, 1);
		}
	}
}

// locate game->map.start_x and game->map.start_y
void	detect_start(t_game *game)
{
	size_t	x;
	size_t	y;

	y = 0;
	if (!game->map.array)
		exit_game(game, 1);
	while (game->map.array[y])
	{
		x = 0;
		while (game->map.array[y][x])
		{
			if (game->map.array[y][x] == 'P')
			{
				game->map.start_x = x;
				game->map.start_y = y;
			}
			x++;
		}
		y++;
	}
}

void	win_screen(int moves)
{
	ft_printf(" _____________________________________________ \n");
	ft_printf("|      //  ) )                                |\n");
	ft_printf("|   __//__  __       __     / ___     ( )     |\n");
	ft_printf("|    //   //  ) ) //   ) ) //\\ \\     / /      |\n");
	ft_printf("|   //   //      //   / / //  \\ \\   / /       |\n");
	ft_printf("| ()/   //      //   / / //    \\ \\ / /        |\n");
	ft_printf(" ______________________ ______________________ \n");
	ft_printf("|                      |  --- HIGHSCORES ---  |\n");
	ft_printf("|   YOU WON THE GAME!  | MAP:   42.ber        |\n");
	ft_printf("| ____________________ | ____________________ |\n");
	ft_printf("|                      |                      |\n");
	ft_printf("|   CONGRATULATIONS,   | #1 - MARVIN  42      |\n");
	ft_printf("|   YOU ARE AWESOME!   | #2 - .frnki  166     |\n");
	ft_printf("|         ***          | #3 - YOU     %i     |\n", moves);
	ft_printf("|______________________|______________________|\n");
}
