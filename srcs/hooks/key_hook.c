#include "../../includes/cub3D.h"

// int	key_press_hook(t_data *data)
// {
// 	printf
// }

int	key_hook(int keycode, t_data *data)
{
	if (keycode == ESCAPE)
		exit_game(data);
	else if (keycode == W)
		move_front(data);
	else if (keycode == S)
		move_back(data);
	else if (keycode == A)
		move_left(data);
	else if (keycode == D)
		move_right(data);
	else if (keycode == UP)
		look_up(data);
	else if (keycode == DOWN)
		look_down(data);
	else if (keycode == LEFT)
		look_left(data);
	else if (keycode == RIGHT)
		look_right(data);
	return (0);
	printf("x : %f\ny : %f\n\n", data->player.pos.x, data->player.pos.y);
}