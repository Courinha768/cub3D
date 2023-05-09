#include "../../includes/cub3D.h"

int	key_hook(int keycode, t_all *all)
{
	if (keycode == ESCAPE)
		exit_game(all);
	else if (keycode == W)
		move_front(all);
	else if (keycode == S)
		move_back(all);
	else if (keycode == A)
		move_left(all);
	else if (keycode == D)
		move_right(all);
	else if (keycode == UP)
		look_up(all);
	else if (keycode == DOWN)
		look_down(all);
	else if (keycode == LEFT)
		look_left(all);
	else if (keycode == RIGHT)
		look_right(all);
	return (0);
	printf("x : %f\ny : %f\n\n", all->player.pos.x, all->player.pos.y);
}