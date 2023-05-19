#include "../includes/cub3D.h"

/*
Change where the camera is pointing.
Uses CAMERA_SPEED located in includes/cub3D.h
Direction: UP
*/
void	look_up(t_data *data)
{
	(void)data;
}

/*
Change where the camera is pointing.
Uses CAMERA_SPEED located in includes/cub3D.h
Direction: DOWN
*/
void	look_down(t_data *data)
{
	(void)data;
}

/*
Change where the camera is pointing.
Uses CAMERA_SPEED located in includes/cub3D.h
Direction: LEFT
*/
void	look_left(t_data *data)
{
	data->player.dirX += CAMERA_SPEED;
}

/*
Change where the camera is pointing.
Uses CAMERA_SPEED located in includes/cub3D.h
Direction: RIGHT
*/
void	look_right(t_data *data)
{
	data->player.dirX -= CAMERA_SPEED;
}