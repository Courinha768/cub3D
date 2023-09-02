/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 19:08:11 by aappleto          #+#    #+#             */
/*   Updated: 2023/09/02 19:11:40 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	render_minimap(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map.map[++i])
	{
		j = -1;
		while (data->map.map[i][++j])
		{
			if (data->map.map[i][j] == '0')
				draw_square(data, (j + 1) * MINIMAP_SCALE, (i + 1)
					* MINIMAP_SCALE, create_trgb(0, 228, 227, 225));
			else if (data->map.map[i][j] == '1')
				draw_square(data, (j + 1) * MINIMAP_SCALE, (i + 1)
					* MINIMAP_SCALE, create_trgb(0, 27, 28, 30));
			else if (data->map.map[i][j] != '\n' && data->map.map[i][j] != ' ')
				draw_square(data, (j + 1) * MINIMAP_SCALE, (i + 1)
					* MINIMAP_SCALE, create_trgb(0, 228, 227, 225));
		}
	}
	draw_player(data, (data->player.position.x) * MINIMAP_SCALE,
		(data->player.position.y) * MINIMAP_SCALE, create_trgb(0, 255, 0, 0));
}

void	draw_player(t_data *data, float x, float y, int color)
{
	float	x_end;
	float	y_end;
	float	y_reset;

	y = y + MINIMAP_SCALE - 3.4;
	x = x + MINIMAP_SCALE - 3.4;
	x_end = x + MINIMAP_SCALE / 2;
	y_end = y + MINIMAP_SCALE / 2;
	y_reset = y;
	while (x < x_end && x < SCREENW)
	{
		y = y_reset;
		while (y < y_end && y < SCREENH)
		{
			my_pixel_put(&data->scene, x, y, color);
			y++;
		}
		x++;
	}
}

void	draw_square(t_data *data, int x, int y, int color)
{
	int	x_end;
	int	y_end;
	int	y_reset;

	x_end = x + MINIMAP_SCALE;
	y_end = y + MINIMAP_SCALE;
	y_reset = y;
	while (x < x_end && x < SCREENW)
	{
		y = y_reset;
		while (y < y_end && y < SCREENH)
		{
			my_pixel_put(&data->scene, x, y, color);
			y++;
		}
		x++;
	}
}
