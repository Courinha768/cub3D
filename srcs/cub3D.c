/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:14:35 by aappleto          #+#    #+#             */
/*   Updated: 2023/08/30 16:49:23 by aappleto         ###   ########.fr       */
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
	(void)ac;

	map_info = parsing(av[1]);
	cub3d(map_info);
}
