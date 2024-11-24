#include "so_long.h"

int	main(void)
{
	t_game		game;

	game.mlx = mlx_init();
	if (!game.mlx)
		return (1);
	game.win = mlx_new_window(game.mlx, WIDTH, HEIGHT, ".frnki");
	game.tex[0] = mlx_xpm_file_to_image(game.mlx, "textures/grey_background.xpm", &game.tex_width, &game.tex_height);
	game.tex[1] = mlx_xpm_file_to_image(game.mlx, "textures/green_light.xpm", &game.tex_width, &game.tex_height);
	game.tex[2] = mlx_xpm_file_to_image(game.mlx, "textures/green_dark.xpm", &game.tex_width, &game.tex_height);
	game.tex[3] = mlx_xpm_file_to_image(game.mlx, "textures/aqua_light.xpm", &game.tex_width, &game.tex_height);
	if (!game.tex[0] || !game.tex[1] || !game.tex[2] || !game.tex[3])
		return (free(game.mlx), 1);
	game.mary.sprite[0] = mlx_xpm_file_to_image(game.mlx, "textures/mary_right.xpm", &game.tex_width, &game.tex_height);
	if (!game.mary.sprite[0])
		return (free(game.mlx), 1);
	game.mary.x = WIDTH / 4;					// change to x of P later
	game.mary.y = HEIGHT / 4;					// change to y of P later
	mlx_do_key_autorepeaton(game.mlx);			// change to off later!
	mlx_hook(game.win, 2, 1L<<0, movements, &game);
	mlx_hook(game.win, 17, 0L, exit_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
