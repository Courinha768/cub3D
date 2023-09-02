/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:24:05 by aappleto          #+#    #+#             */
/*   Updated: 2023/09/02 17:41:25 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	calc_step_and_side(t_data *data)
{
	if (data->ray.ray_dir.x < 0)
	{
		data->ray.step.x = -1;
		data->ray.side_dist.x = (data->player.position.x
				- data->player.map_posx) * data->ray.delta.x;
	}
	else
	{
		data->ray.step.x = 1;
		data->ray.side_dist.x = (data->player.map_posx + 1
				- data->player.position.x) * data->ray.delta.x;
	}
	if (data->ray.ray_dir.y < 0)
	{
		data->ray.step.y = -1;
		data->ray.side_dist.y = (data->player.position.y
				- data->player.map_posy) * data->ray.delta.y;
	}
	else
	{
		data->ray.step.y = 1;
		data->ray.side_dist.y = (data->player.map_posy + 1
				- data->player.position.y) * data->ray.delta.y;
	}
}

void	find_wall(t_data *data)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (data->ray.side_dist.x < data->ray.side_dist.y)
		{
			data->ray.side_dist.x += data->ray.delta.x;
			data->player.map_posx += data->ray.step.x;
			data->ray.wall_side = 0;
		}
		else
		{
			data->ray.side_dist.y += data->ray.delta.y;
			data->player.map_posy += data->ray.step.y;
			data->ray.wall_side = 1;
		}
		if (data->map.map[data->player.map_posy][data->player.map_posx] == '1')
			hit = 1;
	}
}

void	calc_wall_height(t_data *data)
{
	data->tex.wall_line_h = 0;
	if (data->ray.wall_side == 0)
		data->ray.prep_wall_dist = fabs((data->player.map_posx - data->player.position.x
					+ (1 - data->ray.step.x) / 2) / data->ray.ray_dir.x);
	else
		data->ray.prep_wall_dist = fabs((data->player.map_posy - data->player.position.y
					+ (1 - data->ray.step.y) / 2) / data->ray.ray_dir.y);
	data->tex.wall_line_h  = (int)(SCREENH / data->ray.prep_wall_dist);
	data->draw.start = -data->tex.wall_line_h  / 2 + SCREENH / 2;
	if (data->draw.start < 0)
		data->draw.start = 0;
	data->draw.end = data->tex.wall_line_h  / 2 + SCREENH / 2;
	if (data->draw.end >= SCREENH)
		data->draw.end = SCREENH - 1;
}
