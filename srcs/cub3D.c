/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:14:35 by aappleto          #+#    #+#             */
/*   Updated: 2023/08/31 15:06:17 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static	void	create_data_info(t_data *data)
{
	data->player = define_player_info(data->map);
	data->keys_pressed = init_keys_pressed();
	data->ray.delta.x = 0;
	data->ray.delta.y = 0;
	data->ray.ray_dir.x = 0;
	data->ray.ray_dir.y = 0;
	data->ray.side_dist.x = 0;
	data->ray.side_dist.y = 0;
	data->ray.step.x = 0;
	data->ray.step.y = 0;
	data->ray.wall_side = 0;
	data->draw.start = 0;
	data->draw.end = 0;
}

static	void	set_mlx_hooks(t_data *data)
{
	mlx_hook(data->mlx.win, ON_DESTROY, 0, close_game, data);
	mlx_hook(data->mlx.win, ON_KEYDOWN, 1, key_pressed_hook, data);
	mlx_hook(data->mlx.win, ON_KEYUP, 2, key_release_hook, data);
	mlx_loop_hook(data->mlx.ptr, loop_hook, data);
}

void	create_3dwin(t_data *data)
{
	data->mlx.ptr = mlx_init();
	data->mlx.win = mlx_new_window(data->mlx.ptr, SCREENW, SCREENH, GAME_NAME);
}

void	cub3d(t_map_info map_info)
{
	t_data	data;

	data.map = map_info;
	create_data_info(&data);
	create_3dwin(&data);
	data.img.img = mlx_new_image(data.mlx.ptr, SCREENW, SCREENH);
	data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bits,
			&data.img.line, &data.img.endian);
	set_mlx_hooks(&data);
	mlx_loop(data.mlx.ptr);
	close_game(&data);
}

int	main(int ac, char **av)
{
	t_map_info	map_info;

	map_info.exist = init_info_bool();
	if (ac != 2)
		c3d_error(NBR_ARGS, 0, NULL, &map_info);
	map_info = parsing(av[1]);
	if (check_map_construction1(map_info)
		|| check_map_construction2(map_info)
		|| check_map_construction3(map_info))
		c3d_error(MAP_NOT_CONSTRUCTED_CORRECTLY, 0, NULL, &map_info);
	cub3d(map_info);
}

	// printf("NO: %s\n", map_info.NO_texture_path);
	// printf("SO: %s\n", map_info.SO_texture_path);
	// printf("WE: %s\n", map_info.WE_texture_path);
	// printf("EA: %s\n\n", map_info.EA_texture_path);
	// int	i = -1;
	// while (map_info.map[++i]) 
	// 	printf("%s", map_info.map[i]);