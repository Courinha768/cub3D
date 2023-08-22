#include "../../includes/cub3D.h"

/*
Change where the camera is pointing.
Uses CAMERA_SPEED located in includes/cub3D.h
Direction: LEFT
*/
void	look_left(t_data *data)
{
	data->ray.delta.x = cos(data->player.dirX);
	data->ray.delta.y = sin(data->player.dirX);
	data->player.dirX += CAMERA_SPEED * 0.01;
	if (data->player.dirX >= 2 * M_PI)
		data->player.dirX -= 2 * M_PI;
	data->ray.ray_dir.x = cos(data->player.dirX);
	data->ray.ray_dir.y = sin(data->player.dirX);
	data->player.plane.x = -sin(data->player.dirX);
	data->player.plane.y = cos(data->player.dirX);
}

/*
Change where the camera is pointing.
Uses CAMERA_SPEED located in includes/cub3D.h
Direction: RIGHT
*/
void	look_right(t_data *data)
{
	data->ray.delta.x = cos(data->player.dirX);
	data->ray.delta.y = sin(data->player.dirX);
	data->player.dirX -= CAMERA_SPEED * 0.01;
	if (data->player.dirX >= 2 * M_PI)
		data->player.dirX -= 2 * M_PI;
	data->ray.ray_dir.x = cos(data->player.dirX);
	data->ray.ray_dir.y = sin(data->player.dirX);
	data->player.plane.x = -sin(data->player.dirX);
	data->player.plane.y = cos(data->player.dirX);
}