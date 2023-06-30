#include "../../cub3D.h"

int	key_pressed_hook(int keycode, t_data *data)
{
	if (keycode == ESCAPE)
		close_game(data);
	else if (keycode == W)
		data->keys_pressed.w = true;
	else if (keycode == S)
		data->keys_pressed.s = true;
	else if (keycode == A)
		data->keys_pressed.a = true;
	else if (keycode == D)
		data->keys_pressed.d = true;
	else if (keycode == UP)
		data->keys_pressed.up = true;
	else if (keycode == DOWN)
		data->keys_pressed.down = true;
	else if (keycode == LEFT)
		data->keys_pressed.left = true;
	else if (keycode == RIGHT)
		data->keys_pressed.right = true;
	data->keys_pressed.general += 1;
	return (1);
}