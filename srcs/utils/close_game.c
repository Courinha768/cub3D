#include "../../includes/cub3D.h"

int	close_game(t_data *data)
{
	free_map(data->map.map);

	
	//Estas sao so para a visao 2D
	mlx_destroy_image(data->mlx.ptr, data->minimap_imgs.map_square);
	mlx_destroy_image(data->mlx.ptr, data->minimap_imgs.player_square);
	mlx_destroy_image(data->mlx.ptr, data->player.img);


	mlx_destroy_window(data->mlx.ptr, data->mlx.win);
	mlx_destroy_display(data->mlx.ptr);
	free(data->mlx.ptr);
	exit (0);
	return (0);
}