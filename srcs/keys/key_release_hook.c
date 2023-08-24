/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release_hook.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:19:33 by aappleto          #+#    #+#             */
/*   Updated: 2023/08/24 17:19:38 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	key_release_hook(int keycode, t_data *data)
{
	if (keycode == ESCAPE)
		close_game(data);
	else if (keycode == W)
		data->keys_pressed.w = false;
	else if (keycode == S)
		data->keys_pressed.s = false;
	else if (keycode == A)
		data->keys_pressed.a = false;
	else if (keycode == D)
		data->keys_pressed.d = false;
	else if (keycode == LEFT)
		data->keys_pressed.left = false;
	else if (keycode == RIGHT)
		data->keys_pressed.right = false;
	data->keys_pressed.general -= 1;
	return (0);
}
