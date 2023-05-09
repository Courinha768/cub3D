#include "../../includes/cub3D.h"

int	loop_hook(t_data *data)
{
	static unsigned int	frames;
	static t_position	last_position;

	frames++;
	if (!(frames % 1000))
	{
		if (!last_position.x || !same_position(last_position, data->player.pos))
		{
			if (last_position.x)
				put_img(data, data->whiteSquareImg2, last_position.y * MP_SSIZE
					+ MP_SSIZE / 4, last_position.x * MP_SSIZE + MP_SSIZE / 4);
			last_position.x = data->player.pos.x;
			last_position.y = data->player.pos.y;
			place_player(data);
		}
	}
	return (0);
}
