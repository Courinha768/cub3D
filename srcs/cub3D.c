/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:14:35 by aappleto          #+#    #+#             */
/*   Updated: 2023/08/24 17:17:53 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static	void	create_data_info(t_data *data, char **map)
{
	data->map = define_map_info(map);
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
	data->ray.prep_wall_dist = 0;
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

void	load_textures(t_data *data, t_img *wall, char *path)
{
	int	tex_w = TEXW;
	int	tex_h = TEXH;

	wall->img = mlx_xpm_file_to_image(data->mlx.ptr, path, &tex_w, &tex_h);
	wall->addr = mlx_get_data_addr(wall->img, &wall->bits, &wall->line, &wall->endian);
}

void	cub3d(char **map)
{
	t_data	data;

	create_data_info(&data, map);
	create_3dwin(&data);
	data.scene.img = mlx_new_image(data.mlx.ptr, SCREENW, SCREENH);
	data.scene.addr = mlx_get_data_addr(data.scene.img, &data.scene.bits,
			&data.scene.line, &data.scene.endian);
	load_textures(&data, &data.wall1, "./textures/color1_1.xpm");
	load_textures(&data, &data.wall2, "./textures/color2_1.xpm");
	load_textures(&data, &data.wall3, "./textures/color3_1.xpm");
	load_textures(&data, &data.wall4, "./textures/color4_1.xpm");
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
	cub3d(map);
	return (0);
}
