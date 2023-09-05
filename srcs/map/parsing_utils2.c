/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 17:59:06 by aappleto          #+#    #+#             */
/*   Updated: 2023/09/02 19:02:15 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

bool	parse_line_util(char *line, t_map_info *map_info,
	t_map_info_bool *info, bool *not_xpm)
{
	if (!ft_strncmp(line, "NO ", 3) && !info->no_texture_path)
		parse_vars(line, &map_info->no_texture_path, &info->no_texture_path,
			not_xpm);
	else if (!ft_strncmp(line, "SO ", 3) && !info->so_texture_path)
		parse_vars(line, &map_info->so_texture_path, &info->so_texture_path,
			not_xpm);
	else if (!ft_strncmp(line, "WE ", 3) && !info->we_texture_path)
		parse_vars(line, &map_info->we_texture_path, &info->we_texture_path,
			not_xpm);
	else if (!ft_strncmp(line, "EA ", 3) && !info->ea_texture_path)
		parse_vars(line, &map_info->ea_texture_path, &info->ea_texture_path,
			not_xpm);
	else
		return (false);
	return (true);
}

void	parsing_utils(char *file_path, t_map_info *map_info)
{
	map_info->map = define_map(file_path);
	if (!map_info->map)
		c3d_error(MAP_NOT_CONSTRUCTED_CORRECTLY, 0, NULL, map_info);
	map_info->exist.map = true;
	set_map_size(map_info);
	texture_files_exist(map_info);
}

bool	str_isdigit(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (false);
	}
	return (true);
}

void	find_color_free_utils(char *new_line, char **array)
{
	free(array[0]);
	free(array[1]);
	free(array[2]);
	free(array);
	free(new_line);
}
