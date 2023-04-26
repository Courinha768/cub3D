#include "../includes/cub3D.h"

int	key_hook(int keycode, t_all *all)
{
	if (keycode == ESCAPE)
		exit_game(all);
	else if (keycode == UP || keycode == W)
		move_front(all);
	else if (keycode == DOWN || keycode == S)
		move_back(all);
	else if (keycode == LEFT || keycode == A)
		move_left(all);
	else if (keycode == RIGHT || keycode == D)
		move_right(all);
	return (0);
}