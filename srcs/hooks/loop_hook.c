#include "../../includes/cub3D.h"

static void	move(t_data *data)
{
	if (data->keys.w)
		move_front(data);
	if (data->keys.s)
		move_back(data);
	if (data->keys.a)
		move_left(data);
	if (data->keys.d)
		move_right(data);
	if (data->keys.up)
		look_up(data);
	if (data->keys.down)
		look_down(data);
	if (data->keys.left)
		look_left(data);
	if (data->keys.right)
		look_right(data);
}

static int	collision(t_data *data)
{
	if (data->map.map[(int)data->player.pos.y][(int)data->player.pos.x] - 48)
		return (1);
	return (0);
}

int	loop_hook(t_data *data)
{
	static unsigned int	frames;
	t_position	saved_position;

	frames++;
	if (!(frames % 1000))
	{
		saved_position = define_position(data->player.pos.x, data->player.pos.y);
		move(data);
		if ((!saved_position.x || !same_position(saved_position, data->player.pos)) && !collision(data))
		{
			if (saved_position.x)
				put_img(data, data->whiteSquareImg2, (saved_position.y - 0.5) * MP_SSIZE
					+ MP_SSIZE / 4, (saved_position.x - 0.5) * MP_SSIZE + MP_SSIZE / 4);
			saved_position = define_position(data->player.pos.x, data->player.pos.y);
			place_player(data);
		}
		if (collision(data))
			data->player.pos = define_position(saved_position.x, saved_position.y);
	}
	return (0);
}
