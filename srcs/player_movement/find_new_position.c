/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_new_position.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:20:58 by aappleto          #+#    #+#             */
/*   Updated: 2023/08/24 17:22:28 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

t_position	find_new_position(t_position wanted_position,
		t_position old_position, t_map_info map)
{
	t_position	new_position;

	new_position.x = wanted_position.x;
	new_position.y = old_position.y;
	if (!check_colision(define_player_hitbox(new_position), map))
		return (new_position);
	new_position.x = old_position.x;
	new_position.y = wanted_position.y;
	if (!check_colision(define_player_hitbox(new_position), map))
		return (new_position);
	new_position.x = old_position.x;
	new_position.y = old_position.y;
	return (new_position);
}
