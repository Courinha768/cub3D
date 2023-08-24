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
	mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->img.img, 0, 0);
}

void	draw_scene(t_data *data, int pixel_w)
{
	int	pixel_h;

	pixel_h = 0;
	while (pixel_h < SCREENH)
	{
		if (pixel_h < data->draw.start)
			my_pixel_put(data, pixel_w, pixel_h, create_trgb(0, 0, 255, 255));
		else if (pixel_h > data->draw.end)
			my_pixel_put(data, pixel_w, pixel_h, create_trgb(0, 180, 180, 180));
		else
		{
			if (data->ray.wall_side == 0)
				my_pixel_put(data, pixel_w, pixel_h, create_trgb(0, 255, 0, 0));
			else
				my_pixel_put(data, pixel_w, pixel_h, create_trgb(0, 139, 0, 0));
		}
		pixel_h++;
	}
}

void	my_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img.addr + (y * data->img.line + x * (data->img.bits / 8));
	*(unsigned int *)dst = color;
}
