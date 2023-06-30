#include "../../cub3D.h"

void	draw_minimap(t_data *data)
{
	data->mlx = define_minimap_mlx_vars(data->map);
	data->minimap_imgs.map_square = create_squareimg(data->mlx.ptr, RGB_LIGHT_GREY, 32);
	data->minimap_imgs.player_square = create_squareimg(data->mlx.ptr, RGB_LIGHT_GREY, 16);
	data->player.img = create_squareimg(data->mlx.ptr, RGB_RED, 16);
	paint_path(data);
	place_player(data, data->player.hitbox.tl_corner, PLAYER_SQUARE);
	mlx_hook(data->mlx.win, ON_DESTROY, 0, close_game, data);
	mlx_hook(data->mlx.win, ON_KEYDOWN, 1, key_pressed_hook, data);
	mlx_hook(data->mlx.win, ON_KEYUP, 2, key_release_hook, data);
	mlx_loop_hook(data->mlx.ptr, loop_hook, data);
	mlx_loop(data->mlx.ptr);
}