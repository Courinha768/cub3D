/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_construction2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 17:52:40 by aappleto          #+#    #+#             */
/*   Updated: 2023/09/02 17:57:19 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static int	check_map_construction4_util(t_map_info map_info)
{
	int	i;

	i = -1;
	while (++i < (int)map_info.height)
	{
		if (map_info.map[i][0]
			&& map_info.map[i][0] != 49 && map_info.map[i][0] != 10
			&& map_info.map[i][0] != 32)
			return (true);
		if (map_info.map[i][ft_strlen(map_info.map[i]) - 1]
			&& map_info.map[i][ft_strlen(map_info.map[i]) - 1] != 49
			&& map_info.map[i][ft_strlen(map_info.map[i]) - 1] != 10
			&& map_info.map[i][ft_strlen(map_info.map[i]) - 1] != 32)
			return (true);
	}
	return (false);
}

/*
	Checks if the map is surrounded by walls 2
	Return flase if the map is well constructed
*/
int	check_map_construction4(t_map_info map_info)
{
	int	i;

	i = -1;
	while (++i < (int)map_info.width && map_info.map[0][i])
	{
		if (map_info.map[0][i]
			&& map_info.map[0][i] != 49 && map_info.map[0][i] != 10
			&& map_info.map[0][i] != 32)
			return (true);
	}
	i = -1;
	while (++i < (int)map_info.width && map_info.map[map_info.height - 1][i])
	{
		if (map_info.map[map_info.height - 1][i]
			&& map_info.map[map_info.height - 1][i] != 49
			&& map_info.map[map_info.height - 1][i] != 10
			&& map_info.map[map_info.height - 1][i] != 32)
			return (true);
	}
	if (check_map_construction4_util(map_info))
		return (true);
	return (false);
}
