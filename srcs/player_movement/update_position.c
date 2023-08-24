/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:21:07 by aappleto          #+#    #+#             */
/*   Updated: 2023/08/24 17:21:11 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	update_position(t_data *data)
{
	if (data->keys_pressed.w && !data->keys_pressed.s)
		move_front(data);
	else if (data->keys_pressed.s && !data->keys_pressed.w)
		move_back(data);
	if (data->keys_pressed.d && !data->keys_pressed.a)
		move_right(data);
	else if (data->keys_pressed.a && !data->keys_pressed.d)
		move_left(data);
	if (data->keys_pressed.right && !data->keys_pressed.left)
		look_right(data);
	else if (data->keys_pressed.left && !data->keys_pressed.right)
		look_left(data);
	data->player.hitbox = define_player_hitbox(data->player.position);
}
