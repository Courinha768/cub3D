#include "../includes/cub3D.h"

static	void	create_data_info(t_data *data, char **map)
{
	data->map = define_map_info(map);
	data->player = define_player_info(data->map);
	data->keys_pressed = init_keys_pressed();
}

static	void	set_mlx_hooks(t_data *data)
{
	mlx_hook(data->mlx.win, ON_DESTROY, 0, close_game, data);
	mlx_hook(data->mlx.win, ON_KEYDOWN, 1, key_pressed_hook, data);
	mlx_hook(data->mlx.win, ON_KEYUP, 2, key_release_hook, data);
	mlx_loop_hook(data->mlx.ptr, loop_hook, data);
}

void	cub3D(char **map)
{
	t_data	data;
	
	create_data_info(&data, map);
	printf("dirX : %f", data.player.dirX);
	if (DRAW_2D)
		draw_2d(&data);
	else
	{
		(void)data;
	}
		
	set_mlx_hooks(&data);

	mlx_loop(data.mlx.ptr);
	close_game(&data);
}

int	main(int ac, char **av)
{
	char	**map;

	if (!verify_map_path(ac, av))
		return (1);
	map = define_map(av[1]);
	if (!verify_map_construction(map))
		return (1);
	cub3D(map);
	return (0);
}