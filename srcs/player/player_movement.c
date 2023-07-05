#include "../../includes/cub3D.h"

/*
Change the positionition of the player.
Uses PLAYER_SPEED located in includes/cub3D.h
Direction: FRONT
*/
void	move_front(t_data *data)
{
	data->player.position.x -= PLAYER_SPEED * 0.01 * sin(data->player.dirX);
	data->player.position.y -= PLAYER_SPEED * 0.01 * cos(data->player.dirX);
}

/*
Change the positionition of the player.
Uses PLAYER_SPEED located in includes/cub3D.h
Direction: BACK
*/
void	move_back(t_data *data)
{
	data->player.position.x += PLAYER_SPEED * 0.01 * sin(data->player.dirX);
	data->player.position.y += PLAYER_SPEED * 0.01 * cos(data->player.dirX);
}

/*
Change the positionition of the player.
Uses PLAYER_SPEED located in includes/cub3D.h
Direction: LEFT
*/
void	move_left(t_data *data)
{
	data->player.position.x += PLAYER_SPEED * 0.01 * cos(data->player.dirX);
	data->player.position.y -= PLAYER_SPEED * 0.01 * sin(data->player.dirX);
}

/*
Change the positionition of the player.
Uses PLAYER_SPEED located in includes/cub3D.h
Direction: RIGHT
*/
void	move_right(t_data *data)
{
	data->player.position.x -= PLAYER_SPEED * 0.01 * cos(data->player.dirX);
	data->player.position.y += PLAYER_SPEED * 0.01 * sin(data->player.dirX);
}