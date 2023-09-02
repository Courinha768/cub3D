/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_construction.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:05:31 by aappleto          #+#    #+#             */
/*   Updated: 2023/09/02 17:34:50 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/*
	Looks multiple player characters
	Return flase if the map is well constructed
*/
int	check_map_construction1(t_map_info map_info)
{
	int		i;
	int		j;
	bool	player;

	player = false;
	i = -1;
	while (++i < (int)map_info.height && map_info.map[i])
	{
		j = -1;
		while (++j < (int)map_info.width && map_info.map[i][j])
		{
			if ((map_info.map[i][j] == 'N' || map_info.map[i][j] == 'S'
					|| map_info.map[i][j] == 'W' || map_info.map[i][j] == 'E')
					&& player == false)
				player = true;
			else if (map_info.map[i][j] == 'N' || map_info.map[i][j] == 'S'
					|| map_info.map[i][j] == 'W' || map_info.map[i][j] == 'E')
				return (2);
		}
	}
	if (player == false)
		return (3);
	return (false);
}

/*
	Looks for invalid characters	
	Return flase if the map is well constructed
*/
int	check_map_construction2(t_map_info map_info)
{
	int		i;
	int		j;

	i = -1;
	while (++i < (int)map_info.height && map_info.map[i])
	{
		j = -1;
		while (++j < (int)map_info.width && map_info.map[i][j])
		{
			if (!(map_info.map[i][j] == 48 || map_info.map[i][j] == 49
					|| map_info.map[i][j] == 'N' || map_info.map[i][j] == 'S'
					|| map_info.map[i][j] == 'W' || map_info.map[i][j] == 'E'
					|| map_info.map[i][j] == 32 || map_info.map[i][j] == 10))
				return (1);
		}
	}
	return (false);
}

static bool	invalid_chars(char c)
{
	return (!(c == 48 || c == 49 || c == 'N' || c == 'S'
			|| c == 'W' || c == 'E'));
}

/*
	Checks if the map is surrounded by walls
	Return flase if the map is well constructed
*/
int	check_map_construction3(t_map_info map_info)
{
	int		i;
	int		j;

	i = 0;
	while (++i < (int)map_info.height - 1 && map_info.map[i])
	{
		j = 0;
		while (++j < (int)map_info.width - 1 && map_info.map[i][j])
		{
			if ((map_info.map[i][j] == 48
				|| map_info.map[i][j] == 'N' || map_info.map[i][j] == 'S'
				|| map_info.map[i][j] == 'W' || map_info.map[i][j] == 'E')
				&& (invalid_chars(map_info.map[i - 1][j])
				|| invalid_chars(map_info.map[i - 1][j - 1])
				|| invalid_chars(map_info.map[i - 1][j + 1])
				|| invalid_chars(map_info.map[i][j - 1])
				|| invalid_chars(map_info.map[i][j + 1])
				|| invalid_chars(map_info.map[i + 1][j])
				|| invalid_chars(map_info.map[i + 1][j - 1])
				|| invalid_chars(map_info.map[i + 1][j + 1])))
				return (true);
		}
	}
	return (false);
}

/*
	Checks if the map is surrounded by walls 2
	Return flase if the map is well constructed
*/
int	check_map_construction4(t_map_info map_info)
{
	int		i;

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
