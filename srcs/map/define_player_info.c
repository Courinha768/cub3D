/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_player_info.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:19:55 by aappleto          #+#    #+#             */
/*   Updated: 2023/09/01 16:40:02 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static float	find_player_direction(t_map_info map,
		t_position player_position)
{
	if (map.map[(int)player_position.y][(int)player_position.x] == 'W')
		return (M_PI);
	else if (map.map[(int)player_position.y][(int)player_position.x] == 'N')
		return (3 * M_PI_2);
	else if (map.map[(int)player_position.y][(int)player_position.x] == 'E')
		return (0);
	else if (map.map[(int)player_position.y][(int)player_position.x] == 'S')
		return (M_PI_2);
	else
		return (0);
}

static t_position	find_player_position(t_map_info map)
{
	t_position		temp_player_position;
	unsigned int	i;
	unsigned int	j;

	temp_player_position.x = -1;
	temp_player_position.y = -1;
	i = -1;
	while (++i < map.height && map.map[i])
	{
		j = -1;
		while (++j < map.width && map.map[i][j])
		{
			if (map.map[i][j] == 'N' || map.map[i][j] == 'S'
				|| map.map[i][j] == 'E' || map.map[i][j] == 'W')
			{
				temp_player_position.x = (float)j + 0.46875;
				temp_player_position.y = (float)i + 0.46875;
				return (temp_player_position);
			}
		}
	}
	return (temp_player_position);
}

t_player_info	define_player_info(t_map_info map)
{
	t_player_info	temp_player;

	temp_player.position = find_player_position(map);
	temp_player.dirX = find_player_direction(map, temp_player.position);
	temp_player.hitbox = define_player_hitbox(temp_player.position);
	temp_player.view_dir.x = cos(temp_player.dirX);
	temp_player.view_dir.y = sin(temp_player.dirX);
	temp_player.plane.x = -sin(temp_player.dirX);
	temp_player.plane.y = cos(temp_player.dirX);
	temp_player.map_posX = 0;
	temp_player.map_posY = 0;
	return (temp_player);
}
