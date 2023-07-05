#include "../includes/cub3D.h"

void	cub3D(char **map)
{
	t_data	data;
	
	data.map = define_map_info(map);
	data.player = define_player_info(data.map);
	data.keys_pressed = init_keys_pressed();
	if (DRAW_MINIMAP)
		draw_minimap(&data);
	place_player(&data, data.player.hitbox.tl_corner, PLAYER_SQUARE);
	mlx_hook(data.mlx.win, ON_DESTROY, 0, close_game, &data);
	mlx_hook(data.mlx.win, ON_KEYDOWN, 1, key_pressed_hook, &data);
	mlx_hook(data.mlx.win, ON_KEYUP, 2, key_release_hook, &data);
	mlx_loop_hook(data.mlx.ptr, loop_hook, &data);
	mlx_loop(data.mlx.ptr);
	close_game(&data);
}