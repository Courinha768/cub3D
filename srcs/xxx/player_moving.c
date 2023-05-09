#include "../../includes/cub3D.h"

void	move_front(t_data *data)
{
	data->player.pos.x += PLAYER_SPEED * sin(data->player.dirX);
	data->player.pos.y += PLAYER_SPEED * cos(data->player.dirX);
}

void	move_back(t_data *data)
{
	data->player.pos.x -= PLAYER_SPEED * sin(data->player.dirX);
	data->player.pos.y -= PLAYER_SPEED * cos(data->player.dirX);
}

void	move_left(t_data *data)
{
	if (sin(data->player.dirX - M_PI_2) < 0)
	{
		data->player.pos.x -= PLAYER_SPEED * cos(data->player.dirX);
		data->player.pos.y += PLAYER_SPEED * sin(data->player.dirX);
	}
	else
	{
		data->player.pos.x += PLAYER_SPEED * cos(data->player.dirX);
		data->player.pos.y -= PLAYER_SPEED * sin(data->player.dirX);
	}
}

void	move_right(t_data *data)
{
	if (sin(data->player.dirX - M_PI_2) < 0)
	{
		data->player.pos.x += PLAYER_SPEED * cos(data->player.dirX);
		data->player.pos.y -= PLAYER_SPEED * sin(data->player.dirX);
	}
	else
	{
		data->player.pos.x -= PLAYER_SPEED * cos(data->player.dirX);
		data->player.pos.y += PLAYER_SPEED * sin(data->player.dirX);
	}
}