/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3d_scene.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:24:07 by aappleto          #+#    #+#             */
/*   Updated: 2023/08/24 17:26:54 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	render_3d_scene(t_data *data)
{
	float	camerax;
	int		pixel_w;

	camerax = 0;
	pixel_w = 0;
	while (pixel_w < SCREENW)
	{
		camerax = 2 * pixel_w / (float)(SCREENW) - 1;
		data->ray.ray_dir.x = data->player.view_dir.x + data->player.plane.x
			* camerax;
		data->ray.ray_dir.y = data->player.view_dir.y + data->player.plane.y
			* camerax;
		data->player.map_posX = (int)data->player.position.x;
		data->player.map_posY = (int)data->player.position.y;
		data->ray.delta.x = sqrt(1 + pow(data->ray.ray_dir.y, 2)
				/ pow(data->ray.ray_dir.x, 2));
		data->ray.delta.y = sqrt(1 + pow(data->ray.ray_dir.x, 2)
				/ pow(data->ray.ray_dir.y, 2));
		calc_step_and_side(data);
		find_wall(data);
		calc_wall_height(data);
		draw_scene(data, pixel_w);
		pixel_w++;
	}
	mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->scene.img, 0, 0);
}

void	draw_scene(t_data *data, int pixel_w)
{
	int	pixel_h;

	get_tex_data(data);
	pixel_h = 0;
	while (pixel_h < SCREENH)
	{
		if (pixel_h < data->draw.start)
			my_pixel_put(&data->scene, pixel_w, pixel_h, create_trgb(0, 0, 255, 255));
		else if (pixel_h > data->draw.end)
			my_pixel_put(&data->scene, pixel_w, pixel_h, create_trgb(0, 180, 180, 180));
		else
		{
			data->tex.tex_y = (int)(((float)pixel_h - (float)SCREENH / 2.0 + (float)data->tex.wall_line_h / 2.0) * data->tex.step);
			if (data->ray.wall_side == 0)
				data->tex.color = get_color(&data->wall1, data->tex.tex_x, data->tex.tex_y);
			else
				data->tex.color = get_color(&data->wall2, data->tex.tex_x, data->tex.tex_y);
			my_pixel_put(&data->scene, pixel_w, pixel_h, data->tex.color);
		}
		pixel_h++;
	}
}

void	get_tex_data(t_data *data)
{
	float wall_x;

	data->tex.tex_x = 0;
	data->tex.tex_y = 0;
	if (data->ray.wall_side == 0)
		wall_x = data->player.position.y + data->ray.prep_wall_dist * data->ray.ray_dir.y;
	else
		wall_x = data->player.position.y + data->ray.prep_wall_dist * data->ray.ray_dir.x;
	wall_x -= floor(wall_x);
	data->tex.tex_x = (int)(wall_x * (float)TEXW);
	data->tex.step = (float)TEXH / data->tex.wall_line_h;
}

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line + x * (img->bits / 8));
	*(unsigned int *)dst = color;
}

unsigned int	get_color(t_img *img, int x, int y)
{
	char	*dst;
	unsigned int color;

	dst = img->addr + (y * img->line + x * (img->bits / 8));
	color = *(unsigned int *)dst;
	return (color);
}