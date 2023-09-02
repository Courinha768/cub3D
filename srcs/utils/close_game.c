/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:27:30 by aappleto          #+#    #+#             */
/*   Updated: 2023/09/02 17:42:13 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	close_game(t_data *data)
{
	free_map(data->map.map);
	mlx_destroy_image(data->mlx.ptr, data->scene.img);
	mlx_destroy_image(data->mlx.ptr, data->wall1.img);
	mlx_destroy_image(data->mlx.ptr, data->wall2.img);
	mlx_destroy_image(data->mlx.ptr, data->wall3.img);
	mlx_destroy_image(data->mlx.ptr, data->wall4.img);
	mlx_destroy_window(data->mlx.ptr, data->mlx.win);
	mlx_destroy_display(data->mlx.ptr);
	free(data->mlx.ptr);
	free(data->map.no_texture_path);
	free(data->map.so_texture_path);
	free(data->map.we_texture_path);
	free(data->map.ea_texture_path);
	exit (0);
	return (0);
}
