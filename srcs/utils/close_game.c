#include "../../includes/cub3D.h"

int	close_game(t_data *data)
{
	free_map(data->map.map);
	mlx_destroy_image(data->mlx.ptr, data->img.img);

	mlx_destroy_window(data->mlx.ptr, data->mlx.win);
	mlx_destroy_display(data->mlx.ptr);
	free(data->mlx.ptr);
	exit (0);
	return (0);
}