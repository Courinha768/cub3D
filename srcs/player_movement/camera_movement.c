/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:20:44 by aappleto          #+#    #+#             */
/*   Updated: 2023/09/02 17:40:34 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/*
Change where the camera is pointing.
Uses CAMERA_SPEED located in includes/cub3D.h
Direction: LEFT
*/
void	look_left(t_data *data)
{
	data->player.dirx -= CAMERA_SPEED * 0.01;
	if (data->player.dirx >= 2 * M_PI)
		data->player.dirx -= 2 * M_PI;
	else if (data->player.dirx <= 0)
		data->player.dirx += 2 * M_PI;
	data->player.view_dir.x = cos(data->player.dirx);
	data->player.view_dir.y = sin(data->player.dirx);
	data->ray.ray_dir.x = cos(data->player.dirx);
	data->ray.ray_dir.y = sin(data->player.dirx);
	data->player.plane.x = -sin(data->player.dirx);
	data->player.plane.y = cos(data->player.dirx);
}

/*
Change where the camera is pointing.
Uses CAMERA_SPEED located in includes/cub3D.h
Direction: RIGHT
*/
void	look_right(t_data *data)
{
	data->player.dirx += CAMERA_SPEED * 0.01;
	if (data->player.dirx >= 2 * M_PI)
		data->player.dirx -= 2 * M_PI;
	else if (data->player.dirx <= 0)
		data->player.dirx += 2 * M_PI;
	data->player.view_dir.x = cos(data->player.dirx);
	data->player.view_dir.y = sin(data->player.dirx);
	data->ray.ray_dir.x = cos(data->player.dirx);
	data->ray.ray_dir.y = sin(data->player.dirx);
	data->player.plane.x = -sin(data->player.dirx);
	data->player.plane.y = cos(data->player.dirx);
}
