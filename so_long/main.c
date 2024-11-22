#include "minilibx-linux/mlx.h"
#include "so_long.h"

int	print_bye(void)
{
	printf("Bye!\n");
	return (0);
}

int	print_hello(void)
{
	printf("Hello!\n");
	return (0);
}

int	print_floor(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (y <= HEIGHT)
	{	
		x = 0;
		while (x <= WIDTH)
		{
			mlx_put_image_to_window(vars->mlx, vars->win,vars->img[0], x, y);
			x += 32;	
		}
		y += 32;
	}
	return (0);
}

int	print_checker(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (y <= HEIGHT)
	{	
		x = 0;
		while (x <= WIDTH)
		{
			mlx_put_image_to_window(vars->mlx, vars->win,vars->img[1], x, y);
			mlx_put_image_to_window(vars->mlx, vars->win,vars->img[2], x + 32, y);
			x += 64;	
		}
		y += 32;
	}
	return (0);
}

int	exit_game(t_vars *vars)
{
	if (vars->img[0])
		mlx_destroy_image(vars->mlx, vars->img[0]);
	if (vars->img[1])
		mlx_destroy_image(vars->mlx, vars->img[1]);
	if (vars->img[2])
		mlx_destroy_image(vars->mlx, vars->img[2]);
	if (vars->img[3])
		mlx_destroy_image(vars->mlx, vars->img[3]);
	if (vars->img[4])
		mlx_destroy_image(vars->mlx, vars->img[4]);
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	exit (0);
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == ' ')
		printf("SPAWN!");
	if (keycode == 'a')
		printf("LEFT!");
	if (keycode == 'd')
		printf("RIGHT!");
	if (keycode == 's')
		printf("DOWN!");
	if (keycode == 'w')
		printf("UP!");
	if (keycode == 'r')
		mlx_clear_window(vars->mlx, vars->win);
	if (keycode == 65288)			// backspace
		mlx_clear_window(vars->mlx, vars->win);
	if (keycode == 65293)			// enter
		print_floor(vars);
	if (keycode == 65307)			// escape
		exit_game(vars);
	printf("You pressed: %c (keycode: %i)\n", (char)keycode, keycode);
	return (0);
}

int	mouse_click(int mouse_button, int x, int y, t_vars *vars)
{
	if (mouse_button == 1)
		mlx_string_put(vars->mlx, vars->win, x, y, AQUA_DARK, "4242424242");
	if (mouse_button == 2)
		mlx_string_put(vars->mlx, vars->win, x, y, FG_1 , "4242424242");
	if (mouse_button == 3)
		mlx_string_put(vars->mlx, vars->win, x, y, AQUA_LIGHT, "4242424242");
	if (mouse_button == 4)
		mlx_string_put(vars->mlx, vars->win, x, y, 0xd3869b, "4242424242");
	if (mouse_button == 5)
		mlx_string_put(vars->mlx, vars->win, x, y, 0x83a598, "4242424242");
	if (mouse_button == 8)
		print_checker(vars);
	if (mouse_button == 9)
		print_checker(vars);
	printf("mouse button [%d] clicked at (%d, %d)\n", mouse_button, x, y);
	return (0);
}
/*
int	display_map(t_vars vars)
{
	int	y;
	int	x;

	y = 0;
	while (vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
		{
			if (vars->map[y][x] == '0')
				mlx_put_image_to_window(vars->mlx, vars->win,vars->img[0], x, y);
			if (vars->map[y][x] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win,vars->img[1], x, y);
			if (vars->map[y][x] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win,vars->img[2], x, y);
			if (vars->map[y][x] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->win,vars->img[3], x, y);
			if (vars->map[y][x] == 'P')
				mlx_put_image_to_window(vars->mlx, vars->win,vars->img[4], x, y);
		}
	}
}
*/
int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (1);
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, ".frnki");
	vars.img[0] = mlx_xpm_file_to_image(vars.mlx, "textures/grey_background.xpm", &vars.img_width, &vars.img_height);
	vars.img[1] = mlx_xpm_file_to_image(vars.mlx, "textures/green_light.xpm", &vars.img_width, &vars.img_height);
	vars.img[2] = mlx_xpm_file_to_image(vars.mlx, "textures/green_dark.xpm", &vars.img_width, &vars.img_height);
	vars.img[3] = mlx_xpm_file_to_image(vars.mlx, "textures/aqua_light.xpm", &vars.img_width, &vars.img_height);
	vars.img[4] = mlx_xpm_file_to_image(vars.mlx, "textures/orange_light.xpm", &vars.img_width, &vars.img_height);
	if (!vars.img[0] || !vars.img[1] || !vars.img[2] || !vars.img[3] || !vars.img[4])
		return (free(vars.mlx), 1);
	mlx_do_key_autorepeaton(vars.mlx);			// change to off later!!
	mlx_hook(vars.win, 2, 1L<<0, key_hook, &vars);
	mlx_hook(vars.win, 7, 1L<<4, print_hello, &vars);
	mlx_hook(vars.win, 8, 1L<<5, print_bye, &vars);
	mlx_hook(vars.win, 4, 1L<<2, mouse_click, &vars);
	mlx_hook(vars.win, 17, 0L, exit_game, &vars);
	mlx_loop(vars.mlx);
}
