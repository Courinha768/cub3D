#include "../includes/cub3D.h"

void	look_up(t_data *data)
{
	(void)data;
}

void	look_down(t_data *data)
{
	(void)data;
}

void	look_left(t_data *data)
{
	data->player.dirX += CAMERA_SPEED;
}

void	look_right(t_data *data)
{
	data->player.dirX -= CAMERA_SPEED;
}