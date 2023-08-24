/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_player_hitbox.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:20:54 by aappleto          #+#    #+#             */
/*   Updated: 2023/08/24 17:20:56 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

t_hitbox	define_player_hitbox(t_position	player_position)
{
	t_hitbox	temp_hitbox;

	temp_hitbox.tl_corner.x = player_position.x - 0.25;
	temp_hitbox.tr_corner.x = player_position.x + 0.25;
	temp_hitbox.bl_corner.x = player_position.x - 0.25;
	temp_hitbox.br_corner.x = player_position.x + 0.25;
	temp_hitbox.tl_corner.y = player_position.y - 0.25;
	temp_hitbox.tr_corner.y = player_position.y - 0.25;
	temp_hitbox.bl_corner.y = player_position.y + 0.25;
	temp_hitbox.br_corner.y = player_position.y + 0.25;
	return (temp_hitbox);
}
