/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:13:05 by aappleto          #+#    #+#             */
/*   Updated: 2023/08/31 16:46:10 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

t_map_info_bool	init_info_bool(void)
{
	t_map_info_bool	temp_info;

	temp_info.NO_texture_path = false;
	temp_info.SO_texture_path = false;
	temp_info.WE_texture_path = false;
	temp_info.EA_texture_path = false;
	temp_info.floor_color = false;
	temp_info.ceiling_color = false;
	temp_info.map = false;
	return (temp_info);
}

bool	is_complete(t_map_info_bool info)
{
	return (info.NO_texture_path && info.SO_texture_path && info.WE_texture_path
		&& info.EA_texture_path && info.floor_color && info.ceiling_color);
}

void	parse_vars(char *line, char **texture_path, bool *bool_var)
{
	*texture_path = ft_substr(line, 3, ft_strlen(line) - 4);
	*bool_var = true;
}

void	set_map_size(t_map_info *map_info)
{
	int				i;
	unsigned int	j;

	map_info->height = 0;
	map_info->width = 0;
	while (map_info->map[map_info->height])
		map_info->height++;
	i = -1;
	while (++i < (int)map_info->height)
	{
		j = 0;
		while (map_info->map[i][j])
			j++;
		if (j > map_info->width)
			map_info->width = j;
	}
	map_info->width = j;
}

void	texture_files_exist(t_map_info *map_info)
{
	if (!verify_file_existance(map_info->NO_texture_path))
		c3d_error(MAP_NOT_CONSTRUCTED_CORRECTLY, 3, NULL, map_info);
	if (!verify_file_existance(map_info->SO_texture_path))
		c3d_error(MAP_NOT_CONSTRUCTED_CORRECTLY, 3, NULL, map_info);
	if (!verify_file_existance(map_info->WE_texture_path))
		c3d_error(MAP_NOT_CONSTRUCTED_CORRECTLY, 3, NULL, map_info);
	if (!verify_file_existance(map_info->EA_texture_path))
		c3d_error(MAP_NOT_CONSTRUCTED_CORRECTLY, 3, NULL, map_info);
}
