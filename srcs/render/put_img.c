#include "../../cub3D.h"

void	put_img(t_data *data, void *img, int y, int x)
{
	mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, img, x, y);
}