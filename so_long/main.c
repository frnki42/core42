#include "minilibx-linux/mlx.h"
#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>

#define WIDTH	1280
#define HEIGHT	720

typedef struct	s_vars
{
	int	img_width;
	int	img_height;
	void	*img;
	void	*img2;
	void	*mlx;
	void	*win;
}	t_vars;

int	print_bye(t_vars *vars)
{
	printf("Bye!\n");
	return (0);
}

int	print_hello(t_vars *vars)
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
			mlx_put_image_to_window(vars->mlx, vars->win,vars->img, x, y);
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

	y = 16;
	while (y <= HEIGHT)
	{	
		x = 16;
		while (x <= WIDTH)
		{
			mlx_put_image_to_window(vars->mlx, vars->win,vars->img2, x, y);
			x += 64;	
		}
		y += 64;
	}
	return (0);
}

int	exit_game(t_vars *vars)
{
	if (vars->img)
		mlx_destroy_image(vars->mlx, vars->img);
	if (vars->img2)
		mlx_destroy_image(vars->mlx, vars->img2);
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
		printf("RELOAD!");
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
		mlx_string_put(vars->mlx, vars->win, x, y, AQUA_DARK, "IIIIIIIIII");
	if (mouse_button == 2)
		mlx_string_put(vars->mlx, vars->win, x, y, FG_1 , "IIIIIIIIII");
	if (mouse_button == 3)
		mlx_string_put(vars->mlx, vars->win, x, y, AQUA_LIGHT, "IIIIIIIIII");
	if (mouse_button == 4)
		mlx_string_put(vars->mlx, vars->win, x, y, 0x98971a, "IIIIIIIIII");
	if (mouse_button == 5)
		mlx_string_put(vars->mlx, vars->win, x, y, 0xfb4934, "IIIIIIIIII");
	if (mouse_button == 8)
		print_checker(vars);
	printf("mouse button [%d] clicked at (%d, %d)\n", mouse_button, x, y);
	return (0);
}

int	main(void)
{
	t_vars	vars;
	int	x;
	int	y;

	x = 0;
	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (1);
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, ".frnki");
	if (!vars.win)
		return (free(vars.mlx), 1);
	vars.img = mlx_xpm_file_to_image(vars.mlx, "textures/grey_background.xpm",
			&vars.img_width, &vars.img_height);
	if (!vars.img)
		return (free(vars.mlx), 1);
	vars.img2 = mlx_xpm_file_to_image(vars.mlx, "textures/green_dark.xpm",
			&vars.img_width, &vars.img_height);
	if (!vars.img2)
		return (free(vars.mlx), 1);
	mlx_do_key_autorepeaton(vars.mlx);
	mlx_hook(vars.win, 2, 1L<<0, key_hook, &vars);
	mlx_hook(vars.win, 7, 1L<<4, print_hello, &vars);
	mlx_hook(vars.win, 8, 1L<<5, print_bye, &vars);
	mlx_hook(vars.win, 4, 1L<<2, mouse_click, &vars);
	mlx_hook(vars.win, 17, 0L, exit_game, &vars);
	mlx_loop(vars.mlx);
}
