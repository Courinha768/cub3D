/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:13:05 by aappleto          #+#    #+#             */
/*   Updated: 2023/09/02 17:42:13 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

t_map_info_bool	init_info_bool(void)
{
	t_map_info_bool	temp_info;

	temp_info.no_texture_path = false;
	temp_info.so_texture_path = false;
	temp_info.we_texture_path = false;
	temp_info.ea_texture_path = false;
	temp_info.floor_color = false;
	temp_info.ceiling_color = false;
	temp_info.map = false;
	return (temp_info);
}

bool	is_complete(t_map_info_bool info)
{
	return (info.no_texture_path && info.so_texture_path && info.we_texture_path
		&& info.ea_texture_path && info.floor_color && info.ceiling_color);
}

void	parse_vars(char *line, char **texture_path, bool *bool_var
		, bool *not_xpm)
{
	size_t	line_size;

	*texture_path = ft_substr(line, 3, ft_strlen(line) - 4);
	line_size = ft_strlen(*texture_path);
	if (line_size < 4 || (*texture_path)[line_size - 1] != 'm'
		|| (*texture_path)[line_size - 2] != 'p'
		|| (*texture_path)[line_size - 3] != 'x'
		|| (*texture_path)[line_size - 4] != '.')
		{
			*not_xpm = true;
		}
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
}

void	texture_files_exist(t_map_info *map_info)
{
	if (!verify_file_existance(map_info->no_texture_path))
		c3d_error(MAP_NOT_CONSTRUCTED_CORRECTLY, 3, NULL, map_info);
	if (!verify_file_existance(map_info->so_texture_path))
		c3d_error(MAP_NOT_CONSTRUCTED_CORRECTLY, 3, NULL, map_info);
	if (!verify_file_existance(map_info->we_texture_path))
		c3d_error(MAP_NOT_CONSTRUCTED_CORRECTLY, 3, NULL, map_info);
	if (!verify_file_existance(map_info->ea_texture_path))
		c3d_error(MAP_NOT_CONSTRUCTED_CORRECTLY, 3, NULL, map_info);
}
