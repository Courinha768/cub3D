#include "../../includes/cub3D.h"

/*
Change the position of the player.
Uses PLAYER_SPEED located in includes/cub3D.h
Direction: FRONT
*/
void	move_front(t_data *data)
{
	data->player.pos.x += PLAYER_SPEED * 0.01 * sin(data->player.dirX);
	data->player.pos.y += PLAYER_SPEED * 0.01 * cos(data->player.dirX);
}

/*
Change the position of the player.
Uses PLAYER_SPEED located in includes/cub3D.h
Direction: BACK
*/
void	move_back(t_data *data)
{
	data->player.pos.x -= PLAYER_SPEED * 0.01 * sin(data->player.dirX);
	data->player.pos.y -= PLAYER_SPEED * 0.01 * cos(data->player.dirX);
}

/*
Change the position of the player.
Uses PLAYER_SPEED located in includes/cub3D.h
Direction: LEFT
*/
void	move_left(t_data *data)
{
	if (sin(data->player.dirX - M_PI_2) < 0)
	{
		data->player.pos.x -= PLAYER_SPEED * 0.01 * cos(data->player.dirX);
		data->player.pos.y += PLAYER_SPEED * 0.01 * sin(data->player.dirX);
	}
	else
	{
		data->player.pos.x += PLAYER_SPEED * 0.01 * cos(data->player.dirX);
		data->player.pos.y -= PLAYER_SPEED * 0.01 * sin(data->player.dirX);
	}
}

/*
Change the position of the player.
Uses PLAYER_SPEED located in includes/cub3D.h
Direction: RIGHT
*/
void	move_right(t_data *data)
{
	if (sin(data->player.dirX - M_PI_2) < 0)
	{
		data->player.pos.x += PLAYER_SPEED * 0.01 * cos(data->player.dirX);
		data->player.pos.y -= PLAYER_SPEED * 0.01 * sin(data->player.dirX);
	}
	else
	{
		data->player.pos.x -= PLAYER_SPEED * 0.01 * cos(data->player.dirX);
		data->player.pos.y += PLAYER_SPEED * 0.01 * sin(data->player.dirX);
	}
}