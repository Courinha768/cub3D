#include "../../includes/cub3D.h"

void	draw_2d(t_data *data)
{
	data->mlx = define_2d_mlx_vars(data->map);
	data->_2d_imgs.map_square = create_squareimg(data->mlx.ptr, RGB_LIGHT_GREY, 32);
	data->player.img = create_squareimg(data->mlx.ptr, RGB_RED, 16);
	paint_path(data);
	place_player(data, data->player.hitbox.tl_corner);
}