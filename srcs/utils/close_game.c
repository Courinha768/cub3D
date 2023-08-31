/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:27:30 by aappleto          #+#    #+#             */
/*   Updated: 2023/08/30 17:39:10 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	close_game(t_data *data)
{
	free_map(data->map.map);
	mlx_destroy_image(data->mlx.ptr, data->scene.img);
	mlx_destroy_window(data->mlx.ptr, data->mlx.win);
	mlx_destroy_display(data->mlx.ptr);
	free(data->mlx.ptr);
	free(data->map.NO_texture_path);
	free(data->map.SO_texture_path);
	free(data->map.WE_texture_path);
	free(data->map.EA_texture_path);
	exit (0);
	return (0);
}
