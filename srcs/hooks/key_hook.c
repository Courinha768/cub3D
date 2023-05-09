#include "../../includes/cub3D.h"

int	key_press_hook(int keycode, t_data *data)
{
	if (keycode == ESCAPE)
		exit_game(data);
	else if (keycode == W)
		data->keys.w = 1;
	else if (keycode == S)
		data->keys.s = 1;
	else if (keycode == A)
		data->keys.a = 1;
	else if (keycode == D)
		data->keys.d = 1;
	else if (keycode == UP)
		data->keys.up = 1;
	else if (keycode == DOWN)
		data->keys.down = 1;
	else if (keycode == LEFT)
		data->keys.left = 1;
	else if (keycode == RIGHT)
		data->keys.right = 1;
	return (0);
}

int	key_release_hook(int keycode, t_data *data)
{
	if (keycode == ESCAPE)
		exit_game(data);
	else if (keycode == W)
		data->keys.w = 0;
	else if (keycode == S)
		data->keys.s = 0;
	else if (keycode == A)
		data->keys.a = 0;
	else if (keycode == D)
		data->keys.d = 0;
	else if (keycode == UP)
		data->keys.up = 0;
	else if (keycode == DOWN)
		data->keys.down = 0;
	else if (keycode == LEFT)
		data->keys.left = 0;
	else if (keycode == RIGHT)
		data->keys.right = 0;
	return (0);
}