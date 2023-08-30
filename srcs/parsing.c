#include "../includes/cub3D.h"

static bool	verify_file_existance(char *file_path)
{
	int	fd;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (false);
	close(fd);
	return (true);
}

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

char	*get_next_valid_line(int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	while (!ft_strncmp(line, "\n", 100))
	{
		free(line);
		line = get_next_line(fd);
		if (!line)
			return (NULL);
	}
	return (line);
}

void	set_parse_vars(char *line, char **texture_path, bool *bool_var)
{
	*texture_path = ft_substr(line, 3, ft_strlen(line) - 4);
	*bool_var = true;
}

int	find_color(char *line)
{
	char	*new_line;
	char	**color_numbers_char;
	int		color_numbers[3];

	new_line = ft_substr(line, 2, ft_strlen(line) - 3);
	color_numbers_char = ft_split(new_line, ',');
	color_numbers[0] = ft_atoi(color_numbers_char[0]);
	color_numbers[1] = ft_atoi(color_numbers_char[1]);
	color_numbers[2] = ft_atoi(color_numbers_char[2]);
	free(color_numbers_char[0]);
	free(color_numbers_char[1]);
	free(color_numbers_char[2]);
	free(color_numbers_char);
	free(new_line);
	if (color_numbers[0] < 0 || color_numbers[0] > 255
			|| color_numbers[1] < 0 || color_numbers[1] > 255
			|| color_numbers[2] < 0 || color_numbers[2] > 255)
			(void)line; //exit
	return (create_trgb(0, color_numbers[0], color_numbers[1], color_numbers[2]));
}

void	parse_line(char *line, t_map_info *map_info, t_map_info_bool *info)
{
	if (!ft_strncmp(line, "NO ", 3))
		set_parse_vars(line, &map_info->NO_texture_path, &info->NO_texture_path);
	else if (!ft_strncmp(line, "SO ", 3))
		set_parse_vars(line, &map_info->SO_texture_path, &info->SO_texture_path);
	else if (!ft_strncmp(line, "WE ", 3))
		set_parse_vars(line, &map_info->WE_texture_path, &info->WE_texture_path);
	else if (!ft_strncmp(line, "EA ", 3))
		set_parse_vars(line, &map_info->EA_texture_path, &info->EA_texture_path);
	else if (!ft_strncmp(line, "F ", 2))
	{
		map_info->floor_color = find_color(line);
		map_info->exist.floor_color = true;
	}
	else if (!ft_strncmp(line, "C ", 2))
	{
		map_info->ceiling_color = find_color(line);
		map_info->exist.ceiling_color = true;
	}
	else
		c3d_error(MAP_NOT_CONSTRUCTED_CORRECTLY, 3, line, map_info);
}

t_map_info	parsing(char *file_path)
{
	int				fd;
	char			*line;
	t_map_info		map_info;

	map_info.exist = init_info_bool();
	if (!verify_file_existance(file_path))
		c3d_error(FILE_DOESNT_EXIST, 0, NULL, &map_info);
	fd = open(file_path, O_RDONLY);
	line = get_next_valid_line(fd);
	while (!is_complete(map_info.exist) && line)
	{
		parse_line(line, &map_info, &map_info.exist);
		free(line);
		line = get_next_valid_line(fd);
	}
	if (line)
		free(line);
	close(fd);
	map_info.map = define_map(file_path);
	map_info.exist.map = true;
	map_info.height = 0;
	map_info.width = 0;
	while (map_info.map[map_info.height])
		map_info.height++;
	while (map_info.map[0][map_info.width])
		map_info.width++;
	return (map_info);
}