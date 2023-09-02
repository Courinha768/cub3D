/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3d_scene.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:24:07 by aappleto          #+#    #+#             */
/*   Updated: 2023/09/02 19:13:22 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	render_3d_scene(t_data *data)
{
	float	camerax;
	int		pixel_w;

	camerax = 0;
	pixel_w = -1;
	while (++pixel_w < SCREENW)
	{
		camerax = 2 * pixel_w / (float)(SCREENW) - 1;
		data->ray.ray_dir.x = data->player.view_dir.x + data->player.plane.x
			* camerax;
		data->ray.ray_dir.y = data->player.view_dir.y + data->player.plane.y
			* camerax;
		data->player.map_posx = (int)data->player.position.x;
		data->player.map_posy = (int)data->player.position.y;
		data->ray.delta.x = sqrt(1 + pow(data->ray.ray_dir.y, 2)
				/ pow(data->ray.ray_dir.x, 2));
		data->ray.delta.y = sqrt(1 + pow(data->ray.ray_dir.x, 2)
				/ pow(data->ray.ray_dir.y, 2));
		calc_step_and_side(data);
		find_wall(data);
		calc_wall_height(data);
		draw_scene(data, pixel_w);
	}
}

void	draw_scene(t_data *data, int pixel_w)
{
	int	pixel_h;

	pixel_h = -1;
	get_tex_data(data);
	while (++pixel_h < SCREENH)
	{
		if (pixel_h < data->draw.start)
			my_pixel_put(&data->scene, pixel_w, pixel_h,
				data->map.ceiling_color);
		else if (pixel_h > data->draw.end)
			my_pixel_put(&data->scene, pixel_w, pixel_h,
				data->map.floor_color);
		else
			draw_wall(data, pixel_w, pixel_h);
	}
}

void	draw_wall(t_data *data, int pixel_w, int pixel_h)
{
	data->tex.tex_y = (int)(((float)pixel_h - (float)SCREENH / 2.0
				+ (float)data->tex.wall_line_h / 2.0) * data->tex.step);
	if (data->ray.wall_side == 0 && data->ray.ray_dir.x > 0)
		data->tex.color = get_color(&data->wall1, data->tex.tex_x,
				data->tex.tex_y);
	else if (data->ray.wall_side == 0 && data->ray.ray_dir.x < 0)
		data->tex.color = get_color(&data->wall2, data->tex.tex_x,
				data->tex.tex_y);
	else if (data->ray.wall_side == 1 && data->ray.ray_dir.y > 0)
		data->tex.color = get_color(&data->wall3, data->tex.tex_x,
				data->tex.tex_y);
	else
		data->tex.color = get_color(&data->wall4, data->tex.tex_x,
				data->tex.tex_y);
	my_pixel_put(&data->scene, pixel_w, pixel_h, data->tex.color);
}

void	get_tex_data(t_data *data)
{
	float	wall_x;

	data->tex.tex_x = 0;
	data->tex.tex_y = 0;
	if (data->ray.wall_side == 0)
		wall_x = data->player.position.y + data->ray.prep_wall_dist
			* data->ray.ray_dir.y;
	else
		wall_x = data->player.position.x + data->ray.prep_wall_dist
			* data->ray.ray_dir.x;
	wall_x -= floor(wall_x);
	data->tex.tex_x = (int)(wall_x * (float)TEXW);
	data->tex.step = (float)TEXH / data->tex.wall_line_h;
}
