#include "../includes/cub3D.h"

int	loop_hook(t_all *all)
{
	static unsigned int	frames;
	static t_position	last_position;

	frames++;
	if (!(frames % 1000))
	{
		if (!last_position.x || !same_position(last_position, all->player.pos))
		{
			if (last_position.x)
				put_img(all, all->whiteSquareImg2, last_position.y * MP_SSIZE
					+ MP_SSIZE / 4, last_position.x * MP_SSIZE + MP_SSIZE / 4);
			last_position.x = all->player.pos.x;
			last_position.y = all->player.pos.y;
			place_player(all);
		}
	}
	return (0);
}
