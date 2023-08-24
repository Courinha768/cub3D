/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:24:03 by aappleto          #+#    #+#             */
/*   Updated: 2023/08/24 17:24:04 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	put_img(t_data *data, void *img, int y, int x)
{
	mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, img, x, y);
}
