/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:14:35 by aappleto          #+#    #+#             */
/*   Updated: 2023/08/31 17:45:37 by aappleto         ###   ########.fr       */
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

void	cub3d(t_map_info map_info)
{
	t_data	data;

	data.map = map_info;
	create_data_info(&data);
	create_3dwin(&data);
	data.scene.img = mlx_new_image(data.mlx.ptr, SCREENW, SCREENH);
	data.scene.addr = mlx_get_data_addr(data.scene.img, &data.scene.bits,
			&data.scene.line, &data.scene.endian);
	load_textures(&data, &data.wall1, data.map.EA_texture_path);
	load_textures(&data, &data.wall2, data.map.WE_texture_path);
	load_textures(&data, &data.wall3, data.map.SO_texture_path);
	load_textures(&data, &data.wall4, data.map.NO_texture_path);
	data.minimap = true;
	set_mlx_hooks(&data);
	mlx_loop(data.mlx.ptr);
	close_game(&data);
}

int	main(int ac, char **av)
{
	t_map_info	map_info;
	int			fp_len;

	map_info.exist = init_info_bool();
	fp_len = ft_strlen(av[1]);
	if (ac != 2)
		c3d_error(NBR_ARGS, 0, NULL, &map_info);
	if (av[1][fp_len - 4] != '.' || av[1][fp_len - 3] != 'c'
		|| av[1][fp_len - 2] != 'u' || av[1][fp_len - 1] != 'b')
		c3d_error(INVALID_FILE_EXTENSION, 0, NULL, &map_info);
	map_info = parsing(av[1]);
	if (check_map_construction1(map_info)
		|| check_map_construction2(map_info)
		|| check_map_construction3(map_info)
		|| check_map_construction4(map_info))
		c3d_error(MAP_NOT_CONSTRUCTED_CORRECTLY, 0, NULL, &map_info);
	cub3d(map_info);
}

	// printf("NO: [%s]\n", map_info.NO_texture_path);
	// printf("SO: [%s]\n", map_info.SO_texture_path);
	// printf("WE: [%s]\n", map_info.WE_texture_path);
	// printf("EA: [%s]\n\n", map_info.EA_texture_path);
	// int	i = -1;
	// while (map_info.map[++i])
	// 	printf("%s", map_info.map[i]);
	// printf("\n");