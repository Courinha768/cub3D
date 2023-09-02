/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:18:16 by aappleto          #+#    #+#             */
/*   Updated: 2023/09/02 17:51:23 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	loop_hook(t_data *data)
{
	static unsigned int	frames;
	t_position			old_position;

	frames++;
	if (!(frames % (10000 / REFRESH_RATE)))
	{
		if (data->keys_pressed.general)
		{
			render_3d_scene(data);
			if (data->minimap)
				render_minimap(data);
			mlx_put_image_to_window(data->mlx.ptr, data->mlx.win,
				data->scene.img, 0, 0);
			old_position = data->player.position;
			update_position(data);
			if (check_colision(data->player.hitbox, data->map))
			{
				data->player.position = find_new_position(data->player.position,
						old_position, data->map);
				data->player.hitbox = define_player_hitbox(
						data->player.position);
			}
		}
	}
	return (0);
}
