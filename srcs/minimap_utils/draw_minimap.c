#include "../../includes/cub3D.h"

void	draw_minimap(t_data *data)
{
	data->mlx = define_minimap_mlx_vars(data->map);
	data->minimap_imgs.map_square = create_squareimg(data->mlx.ptr, RGB_LIGHT_GREY, 32);
	data->minimap_imgs.player_square = create_squareimg(data->mlx.ptr, RGB_LIGHT_GREY, 16);
	data->player.img = create_squareimg(data->mlx.ptr, RGB_RED, 16);
	paint_path(data);
	place_player(data, data->player.hitbox.tl_corner, PLAYER_SQUARE);
}